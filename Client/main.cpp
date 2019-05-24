#include <zmq.hpp>
#include <string>
#include <iostream>
#include "game.h"
#include <nzmqt/nzmqt.hpp>
#include <QCoreApplication>
#include <QTimer>
#include <QDateTime>

bool send(zmq::socket_t& socket, const std::string& string);

int main( int argc, char *argv[] ){

    QCoreApplication a(argc, argv);

    //  Prepare our context and socket
    zmq::message_t iprequest(11);
    zmq::message_t ipreply;

    nzmqt::ZMQContext *contexter = nzmqt::createDefaultContext( &a );
    nzmqt::ZMQSocket *pusher = contexter->createSocket( nzmqt::ZMQSocket::TYP_PUSH, contexter );
    nzmqt::ZMQSocket *subscriber = contexter->createSocket( nzmqt::ZMQSocket::TYP_SUB, contexter );

    // Print intro
    PrintClientIntro();

    // Connect to Benternet server
    std::cout << "Connecting to broker..." << std::endl;
//    subscriber->connectTo( "tcp://localhost:24042" );
//    pusher->connectTo( "tcp://localhost:24041" );
    subscriber->connectTo( "tcp://192.168.1.8:24042" );
    pusher->connectTo( "tcp://192.168.1.8:24041" );

    subscriber->subscribeTo( "bnc>ip>is>" );

    std::cout << "Connected to broker..." << std::endl;

    std::cout << "Sending IP request to broker..." << std::endl;

    nzmqt::ZMQMessage message = nzmqt::ZMQMessage( QString("bnc>ip>get>").toUtf8() );
    pusher->sendMessage( message );

    std::cout << "Waiting for reply..." << std::endl;

    QObject::connect( subscriber, &nzmqt::ZMQSocket::messageReceived, []( const QList<QByteArray>& messages ){
        std::cout << "IP Received..." << std::endl;

        for( const QByteArray & message : messages ){

            //  Prepare our context and socket
            zmq::context_t context (1);
            zmq::socket_t socket (context, ZMQ_REQ);

            // Connect to ZMQ server
            std::cout << "Connecting to server..." << std::endl;
            socket.connect (message.toStdString().substr(10));
            std::cout << "Connected to server..." << std::endl;

            do{
                zmq::message_t request(3);
                zmq::message_t replay(1);
                zmq::message_t reply;

                eGameStatus GameStatus = eGameStatus::PLAYING;
                eGuessStatus GuessStatus = eGuessStatus::INVALID;

                std::string rpl;
                std::string HiddenWord;
                std::string MyGuess;

                char TotalTries = 0;
                char MyTries = 0;
                char Bulls = 0;
                char Cows = 0;


                std::cout << "Sending request to server..." << std::endl;

                // Send request for hidden word
                memcpy(request.data(), "REQ", 3);
                socket.send(request);

                std::cout << "Waiting for reply..." << std::endl;

                // Get the reply
                socket.recv (&reply);
                rpl = std::string(static_cast<char*>(reply.data()), reply.size());
                HiddenWord = rpl;

                TotalTries = GetTotalTries(HiddenWord.length());

                std::cout << "\nCan you guess the " << HiddenWord.length() << "-letter isogram i'm thinking of ?\n";

                do{
                    Bulls = 0;
                    Cows = 0;

                    GetGuess( HiddenWord, &GuessStatus, &GameStatus, &MyTries, &Bulls, &Cows );

                    std::cout << "\nBulls : " << (int)Bulls;
                    std::cout << "\nCows : " << (int)Cows;
                    std::cout << std::endl;

                }while( GameStatus == eGameStatus::PLAYING );

                if( GameStatus == eGameStatus::WON ){
                    std::cout << "\nWELL DONE - YOU WIN !!!\n\n";

                }else if( GameStatus == eGameStatus::LOST ){
                    std::cout << "\nGAME OVER - YOU LOSE !!!\n\n";

                }else{
                    std::cout << "\nGAME SUMMARY ERROR !!!\n\n";
                }

            }while( true );
        }
    });

    contexter->start();

    return a.exec();
}

bool send(zmq::socket_t& socket, const std::string& string){
    zmq::message_t message(string.size());
    std::memcpy(message.data(), string.data(), string.size());
    bool rc = socket.send (message);
    return (rc);
}

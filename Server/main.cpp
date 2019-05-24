#include <zmq.hpp>
#include <string>
#include <iostream>
#include <nzmqt/nzmqt.hpp>
#include <QCoreApplication>
#include <QTimer>
#include <QDateTime>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "benternet.h"

#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>
#define sleep(n)    Sleep(n)
#endif

bool send(zmq::socket_t& socket, const std::string& string);
QByteArray getRemoteAddress( Benternet * b );

int main( int argc, char *argv[] ){

    // Seed rand
    srand(time(NULL));

    // Print intro
    PrintServerIntro();

    QCoreApplication a(argc, argv);
    try{
        nzmqt::ZMQContext *context = nzmqt::createDefaultContext( &a );
        nzmqt::ZMQSocket *pusher = context->createSocket( nzmqt::ZMQSocket::TYP_PUSH, context );
        nzmqt::ZMQSocket *subscriber = context->createSocket( nzmqt::ZMQSocket::TYP_SUB, context );
        nzmqt::ZMQSocket *words = context->createSocket( nzmqt::ZMQSocket::TYP_REP, context );

        Benternet * b = new Benternet( &a );
        b->start();

        words->bindTo("tcp://*:5555");

        QByteArray host( "bnc>ip>is>tcp://" );
        host.append( getRemoteAddress( b ) ).append( ":5555" );

        std::cout << "My host :" << host.toStdString();

        QObject::connect( subscriber, &nzmqt::ZMQSocket::messageReceived, [pusher, host]( const QList<QByteArray>& messages ){
            for( const QByteArray & message : messages ){

                QByteArrayList parts = message.split( '>' );
                if( parts.at( 2 ) == "get" ){

                    std::cout << "IP request recieved...\n";

                    //nzmqt::ZMQMessage message = nzmqt::ZMQMessage( QString( "bnc>ip>is>tcp://" ).append( "localhost:5555" ).toUtf8() );
                    //nzmqt::ZMQMessage message = nzmqt::ZMQMessage( QString( "bnc>ip>is>tcp://" ).append( getRemoteAddress( b ) ).append( ":24043" );
                    pusher->sendMessage( host );

                    std::cout << "IP is sent...\n";
                }
            }
        } );

        QObject::connect( words, &nzmqt::ZMQSocket::messageReceived, [words]( const QList<QByteArray>& messages ){

            std::string HiddenWord;

            // Select random word
            HiddenWord = SelectRandomWord();

            // Print hidden word
            std::cout << "\nHidden word : " << HiddenWord << std::endl << std::endl;

            if( messages.first() == "REQ" ){
                words->sendMessage(QByteArray(HiddenWord.c_str()));
                std::cout << "Hidden word is sent...\n";
            }
            else{
                std::cout << "Error while requesting hidden word...\n";
            }

        });

        //        pusher->connectTo( "tcp://localhost:24041" );
        //        subscriber->connectTo( "tcp://localhost:24042" );
        pusher->connectTo( "tcp://192.168.1.8:24041" );
        subscriber->connectTo( "tcp://192.168.1.8:24042" );
        subscriber->subscribeTo( "bnc>ip>get>" );
        subscriber->subscribeTo( "bnc>ip>send>" );

        context->start();

        if( !pusher->isConnected() || !subscriber->isConnected() ){
            std::cerr << "NOT CONNECTED !!!" << std::endl;
        }
    }

    catch( nzmqt::ZMQException & ex ){
        std::cerr << "Caught an exception : " << ex.what();
    }

    return a.exec();
}

QByteArray getRemoteAddress( Benternet * b ){
    b->subscribe( "wimip>host!>" );
    Sleep( 1000 ); //To freaking fast...
    std::cout << "Requesting wimip address via benternet" << std::endl;
    b->send( "wimip>host?>" );
    std::cout << "Waiting for response..." << std::endl << std::flush;
    QByteArray response = b->receive();
    std::cout << "Received : " << response.toStdString() << std::endl << std::flush;
    QString host = response.split( '>' ).at( 2 ); //not safe, but we rather crash !
    std::cout << "Extracted : " << host.toStdString() << std::endl;
    b->unsubscribe( "wimip>host!>" );
    nzmqt::ZMQSocket * client = b->getContext()->createSocket( nzmqt::ZMQSocket::TYP_REQ, b->getContext() );
    std::cout << "Setting up a direct request connection to " << host.toStdString() << std::endl;
    client->connectTo( host );
    std::cout << "Sending an empty request..." << std::endl;
    client->sendMessage( QByteArray( "?" ), 0 ); //Do wait for successful send
    std::cout << "Waiting for response..." << std::endl;
    QByteArray myExternalIP = client->receiveMessage( (nzmqt::ZMQSocket::ReceiveFlags) 0 ).first(); //Do wait for receive
    std::cout << "Received : " << myExternalIP.toStdString() << std::endl;
    client->close();
    client->deleteLater();
    return( myExternalIP );
}

#include "game.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <map>
#include <sstream>

game::game(){
    srand (time(NULL));

    word woord;
    word1 woord1;
    word2 woord2;
    word3 woord3;
    word4 woord4;
    word5 woord5;

    PrintIntro();

    do{
        word* HiddenWord = ChooseClass( &woord1, &woord2, &woord3, &woord4, &woord5, &woord );

        MyCurrentTry = 1;

        SetGameStatus( EGameStatus::PLAYING );

        PrintObjective( HiddenWord );

        do{
            SetBulls( 0 );
            SetCows( 0 );

            GetGuess( HiddenWord );

            PrintBullsCows();

        }while( GameStatus == EGameStatus::PLAYING );

        PrintGameSummary();

    }while( AskToPlay() == true );
}

game::~game(){ delete MyCount; }

void inline game::IncrTry( void ){ this->MyCurrentTry++; }

void inline game::SetGameStatus( EGameStatus MyStatus ){ this->GameStatus = MyStatus; }

void inline game::SetBulls( char State ){
    switch( State ){
        case 0:
            this->MyCount->Bulls = 0;
            break;

        case 1:
            this->MyCount->Bulls++;
            break;

        default:
            break;
    }
}

void inline game::SetCows( char State ){
    switch( State ){
        case 0:
            this->MyCount->Cows = 0;
            break;

        case 1:
            this->MyCount->Cows++;
            break;

        default:
            break;
    }
}

void game::PrintIntro( void ) const{

    std::stringstream ss;
    ss.str("\nWelcome to Bulls and Cows, a fun word-guessing game !\n\n"
           "          }   {         ___               \n"
           "          (o o)        (o o)              \n"
           "   /-------\\ /          \\ /-------\\    \n"
           "  / | BULL |O            O| COW  | \\     \n"
           " *  |-,--- |              |------|  *     \n"
           "    ^      ^              ^      ^        \n\n");

    std::string Intro = ss.str();

    std::cout << Intro;

    return;
}

bool game::AskToPlay( void ) const{
    std::string Response = "\0";

    std::cout << "\nDo you want to play again ? (y/n)\n";
    std::getline(std::cin, Response);

    if( Response[0] == 'y' || Response[0] == 'Y' ){
        return( true );

    }else{
        std::cout << "Thanks for playing, goodbye !\n";
        return( false );
    }

    return( false );
}

word* game::ChooseClass( word* woord1, word* woord2, word* woord3, word* woord4, word* woord5, word* woord ) const{

    switch( ( rand() % 5 ) + 1  ){
    case 1:
        return( woord1 );
        break;

    case 2:
        return( woord2 );
        break;

    case 3:
        return( woord3 );
        break;

    case 4:
        return( woord4 );
        break;

    case 5:
        return( woord5 );
        break;

    default:
        break;
    }

    return( woord );
}

void game::PrintObjective( word* HiddenWord ) const{ std::cout << "\nCan you guess the " << (int)HiddenWord->GetLength() << "-letter isogram i'm thinking of ?\n"; }

void game::GetGuess( word* HiddenWord){

    std::string MyGuess = "";
    EGuessStatus GuessStatus = EGuessStatus::INVALID;

    if( MyCurrentTry > HiddenWord->GetTries() ){
        SetGameStatus( EGameStatus::LOST );
        return;

    }else{
        do{
            std::cout << "\nTry " << (int)MyCurrentTry << " of " << (int)HiddenWord->GetTries() << " : Please enter your guess : ";
            std::getline( std::cin, MyGuess );

            GuessStatus = CheckGuess( MyGuess, HiddenWord );

        }while( GuessStatus != EGuessStatus::OK );

        IncrTry();

        CompareGuess( MyGuess, HiddenWord );

        return;
    }

    return;
}

EGuessStatus game::CheckGuess( std::string MyGuess, word* HiddenWord ) const{
    if( CheckLength( MyGuess, HiddenWord ) ){

        if( IsLowercase( MyGuess ) ){

            if( IsIsogram( MyGuess ) ){
                return( EGuessStatus::OK );

            }else{
                std::cout << "\nPlease enter an isogram !\n";
                return( EGuessStatus::NOT_ISOGRAM );
            }

        }else{
            std::cout << "\nPlease type in lowercase !\n";
            return( EGuessStatus::NOT_LOWERCASE );
        }

    }else{
        std::cout << "\nPlease enter a word that is " << (int)HiddenWord->GetLength() << " letters long !\n";
        return( EGuessStatus::WRONG_LENGTH );
    }

    return( EGuessStatus::INVALID );
}

bool game::CheckLength( std::string MyGuess, word* HiddenWord ) const{
    if( (signed)MyGuess.length() ==  HiddenWord->GetLength() ){
        return( true );

    }else{
        return( false );
    }
}

bool game::IsLowercase( std::string MyGuess ) const{

    // for all letters of guess

    for( auto Letter : MyGuess ){

        // if a letter is not lowercase

        if( !islower( Letter ) ){
            return( false );
        }
    }

    // else

    return( true );
}

bool game::IsIsogram( std::string MyGuess ) const{

    // Treat 0 and 1 letters as isograms

    if( MyGuess.length() <= 1 ){ return( true ); }

    // Setup map

    std::map<char, bool> LetterSeen;

    // for all letters of guess

    for( auto Letter : MyGuess ){

        // if letter is in map

        if( LetterSeen[Letter] ){
            return( false );

        }else{

            //else add the letter to the map as seen

            LetterSeen[Letter] = true;
        }
    }

    return( true );
}

void game::CompareGuess( std::string MyGuess, word* HiddenWord){

    char i,j = 0;

    std::string HW = HiddenWord->GetWord();

    // loop through all letters in the guess

    for( i = 0; i < (signed)MyGuess.length(); i++ ){

        // loop through all letters in the hidden word

        for( j = 0; j < HiddenWord->GetLength(); j++ ){

            // compare letters against the hidden word

            // if they match

            if( MyGuess[i] == HW[j] ){

                // if they are in the same place

                if( i == j ){
                    SetBulls( 1 );

                }else{
                    SetCows( 1 );
                }
            }
        }
    }

    if( MyCount->Bulls == HiddenWord->GetLength() ){
        SetGameStatus( EGameStatus::WON );
    }

    return;
}

void game::PrintBullsCows( void ) const{

    std::cout << "\nBulls : " << (int)MyCount->Bulls;
    std::cout << "\nCows : " << (int)MyCount->Cows;
    std::cout << std::endl;
}

void game::PrintGameSummary( void ) const{
    if( GameStatus == EGameStatus::WON ){
        std::cout << "\nWELL DONE - YOU WIN !!!\n";

    }else if( GameStatus == EGameStatus::LOST ){
        std::cout << "\nGAME OVER - YOU LOSE !!!\n";

    }else{
        std::cout << "\nGAME SUMMARY ERROR !!!\n";
    }
}

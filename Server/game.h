#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <sstream>
#include <time.h>
#include <map>

enum class eGameStatus{
    PLAYING,
    LOST,
    WON
};

enum class eGuessStatus{
    INVALID,
    OK,
    NOT_ISOGRAM,
    WRONG_LENGTH,
    NOT_LOWERCASE
};

void PrintServerIntro( void ){

    std::stringstream ss;
    ss.str("\nWelcome to Bulls and Cows ZMQ, a fun word game !\n\n"
           "          }   {         ___               \n"
           "          (o o)        (o o)              \n"
           "   /-------\\ /          \\ /-------\\    \n"
           "  / | BULL |O            O| COW  | \\     \n"
           " *  |-,--- |              |------|  *     \n"
           "    ^      ^              ^      ^        \n\n"
           "Initializing server...\n");

    std::string Intro = ss.str();

    std::cout << Intro;

    return;
}

std::string SelectRandomWord(){
    switch( ( rand() % 5 ) + 1  ){
        case 1: return( "gym" );
        case 2: return( "belt" );
        case 3: return( "pages" );
        case 4: return( "fedora" );
        case 5: return( "maestro" );
        default: break;
    }
    return( "planet" );
}

#endif // GAME_H

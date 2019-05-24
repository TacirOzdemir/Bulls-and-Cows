#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <sstream>
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

void PrintClientIntro( void ){

    std::stringstream ss;
    ss.str("\nWelcome to Bulls and Cows ZMQ, a fun word game !\n\n"
           "          }   {         ___               \n"
           "          (o o)        (o o)              \n"
           "   /-------\\ /          \\ /-------\\    \n"
           "  / | BULL |O            O| COW  | \\     \n"
           " *  |-,--- |              |------|  *     \n"
           "    ^      ^              ^      ^        \n\n"
           "Initializing client...\n");

    std::string Intro = ss.str();

    std::cout << Intro;

    return;
}

char GetTotalTries( char Length ){
    switch(Length){
        case 3: return(5);
        case 4: return(7);
        case 5: return(10);
        case 6: return(16);
        case 7: return(20);
        default: return(16);
    }
}

bool CheckLength( std::string MyGuess, std::string HiddenWord ){
    if( (signed)MyGuess.length() ==  (signed)HiddenWord.length() ){
        return( true );

    }else{
        return( false );
    }
}

bool IsLowercase( std::string MyGuess ){

    // for all letters of guess
    for( auto Letter : MyGuess ){

        // if a letter is not lowercase return false
        if( !islower( Letter ) ){
            return( false );
        }
    }

    // or else return true
    return( true );
}

bool IsIsogram( std::string MyGuess ){

    // Treat 0 and 1 letters as isograms
    if( MyGuess.length() <= 1 ){ return( true ); }

    // Setup map
    std::map<char, bool> LetterSeen;

    // for all letters of guess
    for( auto Letter : MyGuess ){

        // if letter is in map return false
        if( LetterSeen[Letter] ){
            return( false );

        }
        //else add the letter to the map as seen
        else{
            //else add the letter to the map as seen
            LetterSeen[Letter] = true;
        }
    }

    return( true );
}

eGuessStatus CheckGuess( std::string MyGuess, std::string HiddenWord ){
    if( CheckLength( MyGuess, HiddenWord ) ){

        if( IsLowercase( MyGuess ) ){

            if( IsIsogram( MyGuess ) ){
                return( eGuessStatus::OK );

            }else{
                std::cout << "\nPlease enter an isogram !\n";
                return( eGuessStatus::NOT_ISOGRAM );
            }

        }else{
            std::cout << "\nPlease type in lowercase !\n";
            return( eGuessStatus::NOT_LOWERCASE );
        }

    }else{
        std::cout << "\nPlease enter an isogram that is " << HiddenWord.length() << " letters long !\n";
        return( eGuessStatus::WRONG_LENGTH );
    }

    //return( eGuessStatus::INVALID );
}

void CompareGuess( std::string MyGuess, std::string HiddenWord, eGameStatus* GameStatus, char* Bulls, char* Cows){

    char i,j = 0;

    // loop through all letters in the guess

    for( i = 0; i < (signed)MyGuess.length(); i++ ){

        // loop through all letters in the hidden word

        for( j = 0; j < HiddenWord.length(); j++ ){

            // compare letters against the hidden word

            // if they match
            if( MyGuess[i] == HiddenWord[j] ){

                // if they are in the same place
                if( i == j ){
                    *Bulls += 1;

                }else{
                    *Cows += 1;
                }
            }
        }
    }

    if( *Bulls == HiddenWord.length() ){
        *GameStatus = eGameStatus::WON;
    }

    return;
}

void GetGuess( std::string HiddenWord, eGuessStatus* GuessStatus, eGameStatus* GameStatus, char* MyTries, char* Bulls, char* Cows ){

    std::string MyGuess = "";

    *GuessStatus = eGuessStatus::INVALID;

    if( *MyTries > GetTotalTries(HiddenWord.length()) ){
        *GameStatus = eGameStatus::LOST;
        return;

    }else{
        do{
            std::cout << "\nTry " << (int)*MyTries << " of " << (int)GetTotalTries(HiddenWord.length()) << " : Please enter your guess : ";
            std::getline( std::cin, MyGuess );

            *GuessStatus = CheckGuess( MyGuess, HiddenWord );

        }while( *GuessStatus != eGuessStatus::OK );

        *MyTries += 1;

        CompareGuess( MyGuess, HiddenWord, GameStatus, Bulls, Cows );

        return;
    }

    return;
}

#endif // GAME_H

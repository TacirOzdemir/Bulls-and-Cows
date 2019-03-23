#ifndef GAME_H
#define GAME_H

#define GAME_PLAYING 0
#define GAME_LOST 1
#define GAME_WON 2

#include "word.h"

struct BullCowCount{
    char Bulls = 0;
    char Cows = 0;
};

enum class EGameStatus{
    PLAYING,
    LOST,
    WON
};

enum class EGuessStatus{
    INVALID,
    OK,
    NOT_ISOGRAM,
    WRONG_LENGTH,
    NOT_LOWERCASE
};

class game {
    public:

        // Constructor
        game( );

        // Destructor
        ~game( );

    private:

        // Variables

        EGameStatus GameStatus = EGameStatus::PLAYING;
        char MyCurrentTry = 0;
        BullCowCount *MyCount = new BullCowCount;

        // Setters for variables

        void inline SetGameStatus( EGameStatus );   // Set GameStatus
        void inline IncrTry( void );                // Increase MyCurrentTry
        void inline SetBulls( char State = 0 );     // Set Bulls
        void inline SetCows( char State = 0 );      // Set Cows

        // Game functions

        void PrintIntro( void ) const;                          // Print the intro
        bool AskToPlay( void ) const;                           // Ask if the player wants to play again
        void PrintObjective( word* ) const;                     // Print the objective of the game
        void GetGuess( word* );                                 // Get guess from player and compare them to the hidden word
        EGuessStatus CheckGuess( std::string, word* ) const;    // Check the guess entered from the player
        bool CheckLength( std::string, word* ) const;           // Check wether or not the guess is the same length as the hidden word
        bool IsLowercase( std::string ) const;                  // Check wether or not the guess is in lowercase
        bool IsIsogram( std::string ) const;                    // Check wether or not the guess is an isogram
        void CompareGuess( std::string, word* );                // Compare the guess to the hidden word
        void PrintBullsCows( void ) const;                      // Print how many Bulls and Cows the player has scored
        void PrintGameSummary( void )const;                     // Print wether the player has won or lost

        word* ChooseClass( word*, word*, word*, word*, word*, word* ) const;    // Choose 1 of the words
};

#endif // GAME_H

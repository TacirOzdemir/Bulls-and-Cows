#ifndef WORD_H
#define WORD_H

#include <string>

class word {
    public:
        virtual std::string GetWord( void ) const{ return( "planet" ); }
        virtual char GetLength( void ) const{ return( 6 ); }
        virtual char GetTries( void ) const{ return( 16 ); }
};

class word1: public word{
    public:
        std::string GetWord( void ) const{ return( "gym" ); }
        char GetLength( void ) const{ return( 3 ); }
        char GetTries( void ) const{ return( 5 ); }
};

class word2: public word{
    public:
        std::string GetWord( void ) const{ return( "belt" ); }
        char GetLength( void ) const{ return( 4 ); }
        char GetTries( void ) const{ return( 7 ); }
};

class word3: public word{
    public:
        std::string GetWord( void ) const{ return( "pages" ); }
        char GetLength( void ) const{ return( 5 ); }
        char GetTries( void ) const{ return( 10 ); }
};

class word4: public word{
    public:
        std::string GetWord( void ) const{ return( "fedora" ); }
        char GetLength( void ) const{ return( 6 ); }
        char GetTries( void ) const{ return( 16 ); }
};

class word5: public word{
    public:
        std::string GetWord( void ) const{ return( "maestro" ); }
        char GetLength( void ) const{ return( 7 ); }
        char GetTries( void ) const{ return( 20 ); }
};

#endif // WORD_H

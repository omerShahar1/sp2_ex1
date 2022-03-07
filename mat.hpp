#include <iostream>
#include <string>

#ifndef _MAT_HPP_
	#define _MAT_HPP_
    namespace ariel 
    { 
        void addSymbols(char **matrix, int length, int width, int count, char symbol);
        std::string toString(char **matrix, int length, int width);
        std::string mat( int width, int length, char symbol1, char symbol2);
    };
    
#endif
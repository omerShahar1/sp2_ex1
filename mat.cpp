#include <iostream>
#include <string>
#include "mat.hpp"
using namespace std;


namespace ariel 
{
    void addSymbols(char **matrix, int length, int width, int count, char symbol)
    {// function will add the symbol to the matrix in 2 raws and 2 columns (top, button, right and left)
        for(int i=count; i<length-count; i++)
        {
            matrix[i][count] = symbol;
            matrix[i][width - 1 - count] = symbol;
        }

        for(int i=count; i<width-count; i++)
        {
            matrix[count][i] = symbol;
            matrix[length - 1 - count][i] = symbol;

        }
    }

    string toString(char **matrix, int length, int width)
    {//function will make the matrix to string
        string ans = "";
        for(int i=0; i< length; i++)
        {
            for(int j=0; j<width; j++)
            {
                ans += matrix[i][j];
            }
            ans += "\n";
        }
        return ans;
    }


    string mat(int width, int length, char symbol1, char symbol2) //create the matrix, call other functions, delete matrix and return the string answer.
    {
        if(width < 0 || length < 0)
        {
            throw invalid_argument( "mat size can't be negative" );
        }

        if(width%2 == 0 || length%2 == 0)
        {
            throw invalid_argument( "mat size is always add" );
        }
        
        if(width == 1)
        {
            string row = "";
            for(int i=0; i<length; i++)
        {
            row += symbol1;
            row += "\n";
        }
            return row;
        }

        if(length == 1)
        {
            string line = "";
            for(int i=0; i<width; i++)
                line += symbol1;
            return line;
        }

        char **matrix = new char *[length]; // dynamically create an array of pointers
        for (int i = 0; i < length; i++)  // dynamically allocate memory of size `width` for each row
            matrix[i] = new char[width];

        int count=0;
        while(length-count-1 != 0 && width-count-1 !=0)
        {
            if(count%2 == 0)
            {
                addSymbols(matrix, length, width, count, symbol1);
            }
            else
            {
                addSymbols(matrix, length, width, count, symbol2);
            }
            count++;
        }
        string ans = toString(matrix, length, width);

        for(int i = 0; i < length; i++) // deallocate memory using the `delete[]` operator
            delete[] matrix[i];
        delete[] matrix;

        return ans;
    }
}

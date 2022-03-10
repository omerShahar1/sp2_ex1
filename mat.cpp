#include <iostream>
#include <string>
#include <vector>
#include "mat.hpp"
using namespace std;


namespace ariel 
{
    string toString(vector<vector<char>> matrix, char symbol1, int length, int width)
    {//function will make the matrix to string
        string ans(1, symbol1);
        bool firstTime = true;

        for(int i=0; i < length; i++)
        {
            for(int j=0; j<width; j++)
            {
                if (!firstTime)
                {
                    ans += string(1, matrix[i][j]);
                }
                else
                {
                    firstTime = false;
                }
            }
            ans += "\n";
        }
        return ans;
    }


    string mat(int width, int length, char symbol1, char symbol2) //create the matrix, call other functions, delete matrix and return the string answer.
    {
        int i=0;
        int count=0;
        if(width < 0 || length < 0) // in case of negative size
        {
            throw invalid_argument( "mat size can't be negative" );
        }

        if(width%2 == 0 || length%2 == 0) // in case of ilegal size
        {
            throw invalid_argument( "mat size is always add" );
        }
        
        if(width == 1) // in case we only have 1 row to retuen
        {
            string row(1, symbol1);
            for(i=1; i<length; i++)
            {
                row.append("\n");
                row.append(string(1, symbol1));
            }
            return row;
        }

        if(length == 1)  // in case we only have 1 line to return
        {
            string line(1, symbol1);
            for(i=1; i<width; i++)
            {
                line.append(string(1, symbol1));
            }
            return line;
        }

        
        vector <vector<char> > matrix(length, vector<char>(width, '0'));
        count = 0;
        while(length-count-1 != 0 && width-count-1 !=0)
        {
            if(count%2 == 0)
            {
                for(int i=count; i<length-count; i++)
                {
                    matrix[i][count] = symbol1;
                    matrix[i][width - 1 - count] = symbol1;
                }

                for(int i=count; i<width-count; i++)
                {
                    matrix[count][i] = symbol1;
                    matrix[length - 1 - count][i] = symbol1;

                }
            }
            else
            {
                for(int i=count; i<length-count; i++)
                {
                    matrix[i][count] = symbol2;
                    matrix[i][width - 1 - count] = symbol2;
                }

                for(int i=count; i<width-count; i++)
                {
                    matrix[count][i] = symbol2;
                    matrix[length - 1 - count][i] = symbol2;

                }
            }
            count++;
        }
        string ans = toString(matrix, symbol1, length, width);
        return ans;
    }
}

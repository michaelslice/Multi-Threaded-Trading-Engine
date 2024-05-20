#include <iostream>
#include <fstream>
#include <string>
#include "test.h"

#include <sstream>

/**
 *  File format
 * 
 *  Side
 *  Time in Force
 *  Quantity
 *  Price
 *  
 * 
*/


int Test::readFile(const std::string& file)
{
    std::ifstream inputFile(file);

    if(!inputFile.is_open())
    {
        std::cout << "Error opening file";
        return 0;
    }

    std::string line;
    std::cout << "File Contents";

    while(std::getline(inputFile, line))
    {
        std::cout << line << '\n';

        std::stringstream linestream(line);
        std::string value;
        
        while(std::getline(linestream, value, ' '))
        {
            std::cout << "Value" << value << '\n';
        }
    }

    inputFile.close();
    return 0;
}

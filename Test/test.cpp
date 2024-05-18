#include <iostream>
#include <fstream>
#include <string>
#include "test.h"

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


int Test::readFile(std::string file)
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
        std::cout << line;
    }

    inputFile.close();

    return 0;
}

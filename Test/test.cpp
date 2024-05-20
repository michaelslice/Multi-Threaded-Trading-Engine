#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>


#include "test.h"


/**
 *  File format
 * 
 *  Side
 *  Time in Force
 *  Quantity
 *  Price
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
    std::cout << "Orders Placed" << '\n';

    while(inputFile)
    {
        std::stringstream linestream(line);
        
        std::string Side;
        std::string TimeInForce;
        std::string Price;
        std::string Quantity;
        
        std::getline(inputFile, Side, ' ');
        std::getline(inputFile, TimeInForce, ' ');
        std::getline(inputFile, Price, ' ');
        std::getline(inputFile, Quantity, ' ');


        std::cout << Side << " " << TimeInForce << " " << Price << " " << Quantity << " " << '\n';
    }




    inputFile.close();
    return 0;
}

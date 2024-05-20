#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include "test.h"


/**
 *  The method readFile(const std::string& file) is used to read orders from a file, and display their contents
 *
 *  @param const Order& order : A const reference to a existing order
 *
 *  @return int : Return wether there was error or not
 *
 *  @note Data from files consists of info in the order of Side, Time in Force, Quantity, and Price
 *
 */
int Test::readFile(std::string_view file)
{
    std::ifstream inputFile(static_cast<std::string>(file));
    std::string SideReader;
    std::string TimeInForceReader;
    std::string PriceReader;
    std::string QuantityReader;

    if(!inputFile.is_open())
    {
        std::cout << "Error opening file";
        return 0;
    }

    std::string line;
    std::cout << std::right << std::setw(31) << std::setfill(' ') << "Orders Placed" << '\n' << '\n'

    << "Side" << std::right << std::setw(16) << std::setfill(' ') 
    << "TimeInForce" << std::right << std::setw(14) << std::setfill(' ') 
    << "Quantity" << std::right << std::setw(10) << std::setfill(' ') 
    << "Price" << '\n';

    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);

        iss >> SideReader >> TimeInForceReader >> PriceReader >> QuantityReader;

        std::cout << std::setw(9) << std::left << SideReader
                  << std::setw(17) << std::left << TimeInForceReader
                  << std::setw(13) << std::left << PriceReader
                  << QuantityReader << '\n';
    }

    inputFile.close();
    return 0;
}
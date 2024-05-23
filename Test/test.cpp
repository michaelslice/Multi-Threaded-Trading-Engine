#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <string_view>


#include "test.h"
#include "../Orderbook/orderbook.h"
#include "../CurrentTime/current_time.h"
#include "../ModifyOrder/modifyorder.h"
#include "../MatchingEngine/matchingengine.h"

/**
 *  The method readFile(std::string_view file) is used to read orders from a file, and display their contents
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
    std::string OrderNumberReader;

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
    << "Price" << std::right << std::setw(12) << std::setfill(' ') 
    << "OrderId" <<'\n';

    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);

        iss >> SideReader >> TimeInForceReader >> PriceReader >> QuantityReader >> OrderNumberReader;

        std::cout << std::setw(9) << std::left << SideReader
                  << std::setw(17) << std::left << TimeInForceReader
                  << std::setw(13) << std::left << PriceReader
                  << std::setw(10) << std::left << QuantityReader << OrderNumberReader <<'\n';
    }

    inputFile.close();
    return 0;
}

void Test::printOrderbook(std::map<Price, OrderPointer>& _buyOrders, std::map<Price, OrderPointer>& _sellOrders)
{
    std::cout << '\n' << std::right << std::setw(31) << std::setfill(' ') << "BUY ORDERS" << '\n' << '\n'
    << "Side" << std::right << std::setw(16) << std::setfill(' ') 
    << "TimeInForce" << std::right << std::setw(14) << std::setfill(' ') 
    << "Quantity" << std::right << std::setw(10) << std::setfill(' ') 
    << "Price" << std::right << std::setw(12) << std::setfill(' ') 
    << "OrderId" <<'\n';
    for(auto& d : _buyOrders)
    {
        std::cout << std::setw(9) << std::left << getOrderSide(d.second->getSide())
            << std::setw(17) << std::left << getOrderTypeName(d.second->getOrderType())
            << std::setw(13) << std::left << d.first 
            << std::setw(10) << std::left << d.second->getQuantity()  <<d.second->getOrderId() <<'\n';
    }

    std::cout << '\n' << std::right << std::setw(31) << std::setfill(' ') << "SELL ORDERS" << '\n' << '\n'
    << "Side" << std::right << std::setw(16) << std::setfill(' ') 
    << "TimeInForce" << std::right << std::setw(14) << std::setfill(' ') 
    << "Quantity" << std::right << std::setw(10) << std::setfill(' ') 
    << "Price" << std::right << std::setw(12) << std::setfill(' ') 
    << "OrderId" <<'\n';
    for(auto& d : _sellOrders)
    {
        std::cout << std::setw(9) << std::left << getOrderSide(d.second->getSide())
            << std::setw(17) << std::left << getOrderTypeName(d.second->getOrderType())
            << std::setw(13) << std::left << d.first 
            << std::setw(10) << std::left << d.second->getQuantity()  <<d.second->getOrderId() <<'\n';
    }
}

void Test::printRemainingOrderbook(std::map<Price, OrderPointer>& _buyOrders, std::map<Price, OrderPointer>& _sellOrders)
{
    if(_buyOrders.size() == 0)
    {
        std::cout << '\n' << std::right << std::setw(31) << std::setfill(' ') << "BuyOrders are empty" << '\n';
    }
    else
    {
        std::cout << '\n' << std::right << std::setw(31) << std::setfill(' ') << "BUY ORDERS REMAINING" << '\n' << '\n'
        << "Side" << std::right << std::setw(16) << std::setfill(' ') 
        << "TimeInForce" << std::right << std::setw(14) << std::setfill(' ') 
        << "Quantity" << std::right << std::setw(10) << std::setfill(' ') 
        << "Price" << std::right << std::setw(12) << std::setfill(' ') 
        << "OrderId" <<'\n';
        for(auto& d : _buyOrders)
        {
            std::cout << std::setw(9) << std::left << getOrderSide(d.second->getSide())
                << std::setw(17) << std::left << getOrderTypeName(d.second->getOrderType())
                << std::setw(13) << std::left << d.first 
                << std::setw(10) << std::left << d.second->getQuantity()  <<d.second->getOrderId() <<'\n';
        }
    }
    
    if(_sellOrders.size() == 0)
    {
        std::cout << '\n' << std::right << std::setw(31) << std::setfill(' ') << "SellOrders are empty" << '\n';
    }
    else
    {
        std::cout << '\n' << std::right << std::setw(31) << std::setfill(' ') << "SELL ORDERS REMAINING" << '\n' << '\n'
        << "Side" << std::right << std::setw(16) << std::setfill(' ') 
        << "TimeInForce" << std::right << std::setw(14) << std::setfill(' ') 
        << "Quantity" << std::right << std::setw(10) << std::setfill(' ') 
        << "Price" << std::right << std::setw(12) << std::setfill(' ') 
        << "OrderId" <<'\n';
        for(auto& d : _sellOrders)
        {
            std::cout << std::setw(9) << std::left << getOrderSide(d.second->getSide())
                << std::setw(17) << std::left << getOrderTypeName(d.second->getOrderType())
                << std::setw(13) << std::left << d.first 
                << std::setw(10) << std::left << d.second->getQuantity()  <<d.second->getOrderId() <<'\n';
        }
    }
}
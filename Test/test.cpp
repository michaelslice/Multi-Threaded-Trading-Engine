#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <string_view>
#include "test.h"

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
    << "Price" << std::right << std::setw(7) << std::setfill(' ') 
    << "ID" <<'\n';

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


/**
 *  The method printOrderbook will print the orders stored in the buyOrders map, and sellOrders map
 *
 *  @param std::map<Price, OrderPointer>& _buyOrders : Map of all the buyOrders
 * 
 *  @param std::map<Price, OrderPointer>& _sellOrders : Map of all the sellOrders
 * 
 *  @return void
 *
 */
void Test::printOrderbook(std::map<Price, OrderPointer>& _buyOrders, std::map<Price, OrderPointer>& _sellOrders)
{
    std::cout << '\n' << std::right << std::setw(31) << std::setfill(' ') << "BUY ORDERS" << '\n' << '\n'
    << "Side" << std::right << std::setw(16) << std::setfill(' ') 
    << "TimeInForce" << std::right << std::setw(14) << std::setfill(' ') 
    << "Quantity" << std::right << std::setw(10) << std::setfill(' ') 
    << "Price" << std::right << std::setw(7) << std::setfill(' ') 
    << "ID" <<'\n';
    for(auto& order : _buyOrders)
    {
        std::cout << std::setw(9) << std::left << getOrderSide(order.second->getSide())
            << std::setw(17) << std::left << getOrderTypeName(order.second->getOrderType())
            << std::setw(13) << std::left << order.first 
            << std::setw(10) << std::left << order.second->getQuantity()  <<order.second->getOrderId() <<'\n';
    }

    std::cout << '\n' << std::right << std::setw(31) << std::setfill(' ') << "SELL ORDERS" << '\n' << '\n'
    << "Side" << std::right << std::setw(16) << std::setfill(' ') 
    << "TimeInForce" << std::right << std::setw(14) << std::setfill(' ') 
    << "Quantity" << std::right << std::setw(10) << std::setfill(' ') 
    << "Price" << std::right << std::setw(7) << std::setfill(' ') 
    << "ID" <<'\n';
    for(auto& d : _sellOrders)
    {
        std::cout << std::setw(9) << std::left << getOrderSide(d.second->getSide())
            << std::setw(17) << std::left << getOrderTypeName(d.second->getOrderType())
            << std::setw(13) << std::left << d.first 
            << std::setw(10) << std::left << d.second->getQuantity()  <<d.second->getOrderId() <<'\n';
    }
}


/**
 *  The method printRemainingOrderbook is used to print the results of the remaining orders within the Orderbook
 *
 *  @param std::map<Price, OrderPointer>& _buyOrders : Map of all the buyOrders
 * 
 *  @param std::map<Price, OrderPointer>& _sellOrders : Map of all the sellOrders
 * 
 *  @return void
 *
 */
void Test::printRemainingOrderbook(std::map<Price, OrderPointer>& _buyOrders, std::map<Price, OrderPointer>& _sellOrders)
{
    if(_buyOrders.size() == 0)
    {
        std::cout << '\n' << std::right << std::setw(31) << std::setfill(' ') << "All Buy Orders Filled" << '\n';
    }
    else
    {
        std::cout << '\n' << std::right << std::setw(31) << std::setfill(' ') << "BUY ORDERS REMAINING" << '\n' << '\n'
        << "Side" << std::right << std::setw(16) << std::setfill(' ') 
        << "TimeInForce" << std::right << std::setw(14) << std::setfill(' ') 
        << "Quantity" << std::right << std::setw(10) << std::setfill(' ') 
        << "Price" << std::right << std::setw(12) << std::setfill(' ') 
        << "ID" <<'\n';
        for(auto& order : _buyOrders)
        {
            std::cout << std::setw(9) << std::left << getOrderSide(order.second->getSide())
                << std::setw(17) << std::left << getOrderTypeName(order.second->getOrderType())
                << std::setw(13) << std::left << order.first 
                << std::setw(10) << std::left << order.second->getQuantity()  <<order.second->getOrderId() <<'\n';
        }
    }
    
    if(_sellOrders.size() == 0)
    {
        std::cout << '\n' << std::right << std::setw(31) << std::setfill(' ') << "All Sell Orders Filled" << '\n';
    }
    else
    {
        std::cout << '\n' << std::right << std::setw(31) << std::setfill(' ') << "SELL ORDERS REMAINING" << '\n' << '\n'
        << "Side" << std::right << std::setw(16) << std::setfill(' ') 
        << "TimeInForce" << std::right << std::setw(14) << std::setfill(' ') 
        << "Quantity" << std::right << std::setw(10) << std::setfill(' ') 
        << "Price" << std::right << std::setw(7) << std::setfill(' ') 
        << "ID" <<'\n';
        for(auto& d : _sellOrders)
        {
            std::cout << std::setw(9) << std::left << getOrderSide(d.second->getSide())
                << std::setw(17) << std::left << getOrderTypeName(d.second->getOrderType())
                << std::setw(13) << std::left << d.first 
                << std::setw(10) << std::left << d.second->getQuantity()  <<d.second->getOrderId() <<'\n';
        }
    }
}


/**
 *  The method printFilledBuyOrders will print the result of a trade that is initiated from the buy side(aggressive order)
 *
 *  @param std::map<Price, OrderPointer>::iterator buyIter :: A iterator of the buySide
 * 
 *  @return void
 *
 */
void Test::printFilledBuyOrders(std::map<Price, OrderPointer>::iterator buyIter)
{
    std::cout << '\n' << std::right << std::setw(52) << std::setfill('*') << '\n';
    std::cout << "* Side" << std::setfill(' ') << std::setw(15) << std::right << "Price" << std::setw(15) << std::right << "Quantity" << std::setw(15) << std::right << "ID *" << '\n'; 
    std::cout << "* " << getOrderSide(buyIter->second->getSide()) << std::setw(16) << std::right << buyIter->first << std::setw(15) << std::right << buyIter->second->getQuantity() << std::setw(13) << std::right << buyIter->second->getOrderId() << " *"; 
    std::cout << '\n' << std::right << std::setw(52) << std::setfill('*') << '\n';
}


/**
 *  The method printFilledSellOrders will print the result of a trade that is initiated from the sell side(passive order)
 *
 *  @param sstd::reverse_iterator<std::conditional<false, std::map<Price, OrderPointer>::const_iterator, std::_Rb_tree_iterator<std::pair<const Price, OrderPointer>>>::type> : Reverse iterator
 * 
 *  @return void
 *
 */
void Test::printFilledSellOrders(std::reverse_iterator<std::conditional<false, std::map<Price, OrderPointer>::const_iterator, std::_Rb_tree_iterator<std::pair<const Price, OrderPointer>>>::type> sellIter)
{
    std::cout << '\n' << std::right << std::setw(52) << std::setfill('*') << '\n';
    std::cout << "* Side" << std::setfill(' ') << std::setw(15) << std::right << "Price" << std::setw(15) << std::right << "Quantity" << std::setw(15) << std::right << "ID *" << '\n'; 
    std::cout << "* " << getOrderSide(sellIter->second->getSide()) << std::setw(15) << std::right << sellIter->first << std::setw(15) << std::right << sellIter->second->getQuantity() << std::setw(13) << std::right << sellIter->second->getOrderId() << " *"; 
    std::cout << '\n' << std::right << std::setw(52) << std::setfill('*') << '\n';
}
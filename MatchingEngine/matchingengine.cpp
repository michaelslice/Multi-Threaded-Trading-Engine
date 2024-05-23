#include <iostream>
#include <iomanip>

#include "matchingengine.h"

#include "../Test/test.h"

MatchingEngine::MatchingEngine(std::map<Price, OrderPointer>& buyOrders, std::map<Price, OrderPointer>& sellOrders)
{
    std::cout << '\n' << "TESTING MATCHING ENGINE" << '\n';
    
    while(!buyOrders.empty())
    {
        while(!sellOrders.empty())
        {
            if(buyOrders.size() == 0 || sellOrders.size() == 0) 
            {
                std::cout << "Size of buyOrders " << buyOrders.size() << '\n';
                std::cout << "Size of sellOrders " << sellOrders.size() << '\n';
                
                if(buyOrders.size() == 0) { std::cout << "Error no more buy orders" << '\n'; } else { std::cout << "Error no more sell orders" << '\n'; };
                break;
            }

            auto buyIter = buyOrders.begin();
            auto sellIter = sellOrders.rbegin();

            // If buy order is aggressive trade against the best ask price
            if(buyIter->second->getPrice() >= sellIter->second->getPrice())
            {
                std::cout << "TEST AGGRESSIVE ORDER" << '\n';

                std::cout << "Buy order price " << buyIter->first << " quantity " << buyIter->second->getQuantity() << '\n'; 
                std::cout << "sell order price " << sellIter->first << " quantity " << sellIter->second->getQuantity() << '\n'; 
            }
            else // If buy order is passive
            {
                std::cout << "TEST PASSIVE ORDER" << '\n';
                std::cout << "Buy order price " << buyIter->first << " quantity " << buyIter->second->getQuantity() << '\n'; 
                std::cout << "sell order price " << sellIter->first << " quantity " << sellIter->second->getQuantity() << '\n'; 
            }



            buyOrders.erase(buyIter);
            sellIter = std::reverse_iterator(sellOrders.erase(std::next(sellIter).base())); 

            buyIter++;
            sellIter++;
        }
    }
    std::cout << "Trading Session Completed" << '\n';

    Test test;
    test.printRemainingOrderbook(buyOrders, sellOrders);
}


void MatchingEngine::ExecuteTrade()
{
    // TODO perform actions to execute the trade, updating balances, logging
    // TODO update account balances, record the trade in a ledger
}


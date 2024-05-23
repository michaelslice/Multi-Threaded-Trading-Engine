#include <iostream>
#include <iomanip>
#include <stdlib.h>

#include "matchingengine.h"
#include "../Test/test.h"
#include "../Trade/trade.h" 


MatchingEngine::MatchingEngine(std::map<Price, OrderPointer>& buyOrders, std::map<Price, OrderPointer>& sellOrders)
{
    std::cout << '\n' << "TESTING MATCHING ENGINE" << '\n' << '\n';
    
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

            if(sellIter->second->getPrice() <= buyIter->second->getPrice())
            {         
                std::cout << "AGGRESSIVE ORDER" << '\n';

                std::cout << "Buy order: Price " << buyIter->first << " Quantity " << buyIter->second->getQuantity() << '\n'; 
                std::cout << "Sell order: Price " << sellIter->first << " Quantity " << sellIter->second->getQuantity() << '\n'; 

                int minQuantity = std::min(buyIter->second->getQuantity(), sellIter->second->getQuantity());
                auto b = buyIter->second->setTradeQuantity(minQuantity);
                auto s = sellIter->second->setTradeQuantity(minQuantity);
 
                if(b == 0)
                {
                    std::cout << "Sell filled" << '\n';
                    buyOrders.erase(buyIter);
                }
                else if(s == 0)
                {
                    std::cout << "Sell filled" << '\n';
                    sellIter = std::reverse_iterator(sellOrders.erase(std::next(sellIter).base())); 
                }
            }
            else 
            {
                std::cout << "PASSIVE ORDER" << '\n';
                
                std::cout << "Buy order: Price " << buyIter->first << " Quantity " << buyIter->second->getQuantity() << '\n'; 
                std::cout << "Sell order: Price " << sellIter->first << " Quantity " << sellIter->second->getQuantity() << '\n'; 

                int minQuantity = std::min(buyIter->second->getQuantity(), sellIter->second->getQuantity());
                auto b = buyIter->second->setTradeQuantity(minQuantity);
                auto s = sellIter->second->setTradeQuantity(minQuantity);

 
                if(b == 0)
                {
                    std::cout << "Buy filled" << '\n';
                    buyOrders.erase(buyIter);
                }
                else if(s == 0)
                {
                    std::cout << "Sell filled" << '\n';
                    sellIter = std::reverse_iterator(sellOrders.erase(std::next(sellIter).base())); 
                }
            }
            
            // buyOrders.erase(buyIter);
            // sellIter = std::reverse_iterator(sellOrders.erase(std::next(sellIter).base())); 
            buyIter++;
            sellIter++;
        }
    }
    
    std::cout << '\n' << "Trading Session Completed" << '\n';

    Test test;
    test.printRemainingOrderbook(buyOrders, sellOrders);
}


void MatchingEngine::ExecuteTrade()
{
    // TODO perform actions to execute the trade, updating balances, logging
    // TODO update account balances, record the trade in a ledger
}


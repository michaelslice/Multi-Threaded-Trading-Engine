#include <iostream>
#include <iomanip>
#include <stdlib.h>

#include "matchingengine.h"
#include "../Test/test.h"
#include "../Trade/trade.h" 


/**
 *  The method MatchingEngine will execute trades between the buy and sell side
 *
 *  @param std::map<Price, OrderPointer>& buyOrders : Map of all buy orders
 * 
 *  @param std::map<Price, OrderPointer>& sellOrders : Map of all sell orders
 * 
 *  @return Nothing
 *
 */
MatchingEngine::MatchingEngine(std::map<Price, OrderPointer>& buyOrders, std::map<Price, OrderPointer>& sellOrders)
{
    Test test;
    std::cout << '\n' << std::right << std::setw(31) << std::setfill(' ') << "Trade Feed" << '\n' << '\n';
    
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
                int minQuantity = std::min(buyIter->second->getQuantity(), sellIter->second->getQuantity());
                auto buyRemainingQuantity = buyIter->second->setTradeQuantity(minQuantity);
                auto sellRemainingQuantity = sellIter->second->setTradeQuantity(minQuantity);
                test.printFilledBuyOrders(buyIter);
                
                if(buyRemainingQuantity == 0)
                {
                    buyOrders.erase(buyIter);
                }
                else if(sellRemainingQuantity == 0)
                {
                    sellIter = std::reverse_iterator(sellOrders.erase(std::next(sellIter).base())); 
                }
            }
            else 
            {
                int minQuantity = std::min(buyIter->second->getQuantity(), sellIter->second->getQuantity());
                auto buyRemainingQuantity = buyIter->second->setTradeQuantity(minQuantity);
                auto sellRemainingQuantity = sellIter->second->setTradeQuantity(minQuantity);
                test.printFilledSellOrders(sellIter);
       
                if(buyRemainingQuantity == 0)
                {
                    buyOrders.erase(buyIter);
                }
                else if(sellRemainingQuantity == 0)
                {
                    sellIter = std::reverse_iterator(sellOrders.erase(std::next(sellIter).base())); 
                }
            }
            buyIter++;
            sellIter++;
        }
    }
    std::cout << '\n' << "Trading Session Completed" << '\n';
    test.printRemainingOrderbook(buyOrders, sellOrders);
}



void MatchingEngine::ExecuteTrade()
{
    // TODO perform actions to execute the trade, updating balances, logging
    // TODO update account balances, record the trade in a ledger
}
#include <iostream>
#include <iomanip>
#include <stdlib.h>

#include "matchingengine.h"
#include "../Test/test.h"
#include "../Trade/trade.h" 
#include "../TimeInForce/timeinforce.h"
#include "../TimeInForce/timeinforce.cpp"

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
    TimeInForce timeinforce;
    int tradeCount{0};
    std::cout << '\n' << std::right << std::setw(31) << std::setfill(' ') << "Trade Feed" << '\n' << '\n'; 
    
    while(!buyOrders.empty())
    {
        while(!sellOrders.empty())
        {
            auto buyIter = buyOrders.begin();
            auto sellIter = sellOrders.rbegin();

            if(buyOrders.size() == 0 || sellOrders.size() == 0) 
            {
                if(buyOrders.size() != 0) { timeinforce.DayBuyOrders(buyOrders), timeinforce.FillOrKillBuyOrders(buyOrders); };
                if(sellOrders.size() != 0) { timeinforce.DaySellOrders(sellOrders), timeinforce.FillOrKillSellOrders(sellOrders); };
                if(buyOrders.size() != 0) { timeinforce.MarketBuyOrders(buyOrders), timeinforce.MarketBuyOrders(buyOrders); };
                if(sellOrders.size() != 0) { timeinforce.MarketSellOrders(sellOrders), timeinforce.MarketSellOrders(sellOrders); };
                break;
            }

            if(sellIter->second->getPrice() <= buyIter->second->getPrice())
            {         
                test.printFilledBuyOrders(buyIter);
                tradeCount++;
                int minQuantity = std::min(buyIter->second->getQuantity(), sellIter->second->getQuantity());
                auto buyRemainingQuantity = buyIter->second->setTradeQuantity(minQuantity);
                auto sellRemainingQuantity = sellIter->second->setTradeQuantity(minQuantity);
         
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
                test.printFilledSellOrders(sellIter);
                tradeCount++;
                int minQuantity = std::min(buyIter->second->getQuantity(), sellIter->second->getQuantity());
                auto buyRemainingQuantity = buyIter->second->setTradeQuantity(minQuantity);
                auto sellRemainingQuantity = sellIter->second->setTradeQuantity(minQuantity);
                
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

    std::cout << '\n' << "Trading Session Report" << '\n' << '\n';
    std::cout << "Number of Trades Executed " << tradeCount << '\n';
    std::cout << "Buy Orders Remaining " << buyOrders.size() << '\n';
    std::cout << "Sell Orders Remaining " << sellOrders.size() << '\n';
    test.printRemainingOrderbook(buyOrders, sellOrders);
}
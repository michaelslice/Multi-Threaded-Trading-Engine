#include <iostream>
#include <iomanip>
#include <chrono>
#include <stdlib.h>
#include "matchingengine.h"


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
    int time_micro_seconds;
    int time_nano_seconds;

    std::cout << '\n' << std::right << std::setw(31) << std::setfill(' ') << "Trade Feed" << '\n'; 
    
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
                std::scoped_lock lock{mtx};
                std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
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

                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                time_micro_seconds += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
                time_nano_seconds += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
            }
            else 
            {
                std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
                std::scoped_lock lock{mtx};
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

                std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                time_micro_seconds += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
                time_nano_seconds += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
            }
            buyIter++;
            sellIter++;
        }
    }

    std::cout << '\n' << std::right << std::setw(35) << std::setfill(' ') << "Trading Session Report" << '\n'; 
    std::cout << '\n' << std::right << std::setw(52) << std::setfill('*') << '\n';
    std::cout << "* Number of Trades Executed " << tradeCount << std::right << std::setw(21) << std::setfill(' ') << "*" <<'\n';
    std::cout << "* Buy Orders Remaining " << buyOrders.size() << std::right << std::setw(27) << std::setfill(' ') << "*" << '\n';
    std::cout << "* Sell Orders Remaining " << sellOrders.size() << std::right << std::setw(26) << std::setfill(' ') << "*" << '\n';
    std::cout << "* AVG Time in Micro Seconds For Fills " << time_micro_seconds / tradeCount << std::right << std::setw(11) << std::setfill(' ') << "*" << '\n';
    std::cout << "* AVG Time in Nano Seconds For Fills " << time_nano_seconds / tradeCount << std::right << std::setw(9) << std::setfill(' ') << "*" << '\n';
    std::cout << std::right << std::setw(52) << std::setfill('*') << '\n';
    test.printRemainingOrderbook(buyOrders, sellOrders);
}
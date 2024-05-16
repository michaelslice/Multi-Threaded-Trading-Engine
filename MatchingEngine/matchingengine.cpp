#include <iostream>
#include "matchingengine.h"



MatchingEngine::MatchingEngine(PriveLevelMap buyOrders, PriveLevelMap sellOrders)
{
    for(const auto& buyLevel : buyOrders)
    {
        for(const auto& sellLevel : sellOrders)
        {
            if(buyLevel.first == sellLevel.first) // If bid and ask are on same level
            {
                const std::vector<Order>& buyOrderList = buyLevel.second;
                const std::vector<Order>& sellOrderList = sellLevel.second;
            
                while(!buyOrderList.empty() && !sellOrderList.empty())
                {
                    
                    const Order& oldestBuyOrder = buyOrderList.front();
                    const Order& oldestSellOrder = sellOrderList.front();

                    if(oldestBuyOrder.getPrice() == oldestSellOrder.getPrice())
                    {
                        // add the execute the trade
                        ExecuteTrade();

                        // Remove the orders from the orderbook if completed
                        buyOrders[buyLevel.first].erase(buyOrders[buyLevel.first].begin());
                        sellOrders[sellLevel.first].erase(sellOrders[sellLevel.first].begin());
                    }
                    else // If prices dont match exit loop
                    {
                        break;
                    }
                }
            }
        }
    }
}

void MatchingEngine::ExecuteTrade()
{
    // TODO perform actions to execute the trade, updating balances, logging
    // TODO update account balances, record the trade in a ledger
}
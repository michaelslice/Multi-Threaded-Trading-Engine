#include <iostream>
#include "matchingengine.h"


MatchingEngine::MatchingEngine(std::map<Price, OrderPointer> buyOrders, std::map<Price, OrderPointer> sellOrders)
{
    std::sort(buyOrders.begin(), buyOrders.end(), std::greater()); // Sort the keys in ascending 
    std::sort(sellOrders.begin(), sellOrders.end(), std::less()); // Sort the keys in descending


}

void MatchingEngine::ExecuteTrade()
{
    // TODO perform actions to execute the trade, updating balances, logging
    // TODO update account balances, record the trade in a ledger
}


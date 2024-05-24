#ifndef MATCHINGENGINE_H
#define MATCHINGENGINE_H
#include <iostream>

#include "../Orderbook/orderbook.h"
#include "../TimeInForce/timeinforce.h"

class MatchingEngine
{
private:
public:
    MatchingEngine(std::map<Price, OrderPointer>& buyOrders, std::map<Price, OrderPointer>& sellOrders);
    void ExecuteTrade();
};

#endif
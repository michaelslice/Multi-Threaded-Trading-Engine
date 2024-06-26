#ifndef MATCHINGENGINE_H
#define MATCHINGENGINE_H
#include <iostream>
#include <memory>
#include "../Orderbook/orderbook.h"
#include "../TimeInForce/timeinforce.h"
#include "../Test/test.h"
#include "../Trade/trade.h" 

class MatchingEngine
{
private:
    mutable std::mutex mtx;
public:
    MatchingEngine(std::map<Price, OrderPointer>& buyOrders, std::map<Price, OrderPointer>& sellOrders);
};

#endif
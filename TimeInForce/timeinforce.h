#ifndef TRADEINFORCE_H
#define TRADEINFORCE_H

#include "../Order/order.h"
#include "../OrderType/ordertype.h"
#include "../Orderbook/orderbook.h"
#include "../MatchingEngine/matchingengine.h"
#include "../Test/test.h"
#include "../Trade/trade.h" 

/*
    GoodTillCancel,
    FillAndKill,
    FillOrKill,
    GoodForDay,
    Market,
*/

class TimeInForce
{
public:
    void DaySellOrders(std::map<Price, OrderPointer>& _sellOrders);
    void DayBuyOrders(std::map<Price, OrderPointer>& _buyOrders);
    void FillOrKillSellOrders(std::map<Price, OrderPointer>& _sellOrders);
    void FillOrKillBuyOrders(std::map<Price, OrderPointer> &_buyOrders);
    void MarketSellOrders(std::map<Price, OrderPointer>& _sellOrders);
    void MarketBuyOrders(std::map<Price, OrderPointer> &_buyOrders);
};

#endif
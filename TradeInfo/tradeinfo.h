#ifndef TRADEINFO_H
#define TRADEINFO_H
#include <iostream>
#include "../Order/order.h"

struct TradeInfo
{
    Quantity quantity;
    Price price;
    OrderId orderid;    
};

#endif

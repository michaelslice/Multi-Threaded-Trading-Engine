#ifndef ORDERBOOKLEVEL_H
#define ORDERBOOKLEVEL_H
#include <iostream>
#include "../Order/order.h"

struct OrderbookLevel
{
    Quantity Quantity;
    Price price;
};

#endif
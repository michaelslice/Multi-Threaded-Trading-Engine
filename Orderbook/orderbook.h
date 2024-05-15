#ifndef ORDERBOOK_H
#define ORDERBOOK_H
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>

#include "../Order/order.h"

class Orderbook
{
private:
    std::map<double, std::vector<Order>> buyOrders;
    std::map<double, std::vector<Order>> sellOrders;
public:
    Orderbook();
    void ValidOrderDay();
    void AddOrder();
    
};

#endif
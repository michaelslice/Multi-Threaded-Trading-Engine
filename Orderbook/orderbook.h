#ifndef ORDERBOOK_H
#define ORDERBOOK_H
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

#include "../Order/order.h"

// Placing the price as the key allows for orders to be organized by price level
// Price is the index, Key is vector of orders

class Orderbook
{
 friend bool operator==(const Orderbook&, const Orderbook&);

private:
    std::map<double, std::vector<Order>> buyOrders; // Price as the key, and orders as the value
    std::map<double, std::vector<Order>> sellOrders;

    
public:
    Orderbook();
    void ValidOrderDay();
    void AddOrder(const Order& order);
    void CancelOrder(const Order& order);
    void ModifyOrder(const Order& order);

    


void Orderbook::InsertIntoPriceLevel(std::vector<Order>&);
};


#endif
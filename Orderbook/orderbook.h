#ifndef ORDERBOOK_H
#define ORDERBOOK_H
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

#include "../Order/order.h"

/**
 *  The class that will facilate the logic for buyers and sellers to submit trades
 * 
 * 
*/

// Placing the price as the key allows for orders to be organized by price level
// Price is the index, Key is vector of orders

using PriveLevelMap = std::map<double, std::vector<Order>>; 

class Orderbook
{

private:
    std::map<double, std::vector<Order>> buyOrders; 
    std::map<double, std::vector<Order>> sellOrders;

public:
    Orderbook() = default;
    Orderbook(PriveLevelMap _buyOrders, PriveLevelMap _sellOrders): buyOrders(_buyOrders), sellOrders(_sellOrders) {};  
    void ValidForDay();
    void AddOrder(const Order& order);
    void CancelOrder(const Order& order);
    void ModifyOrder(const Order& replaceOrder, const Order& newOrder);
};


#endif
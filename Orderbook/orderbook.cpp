#include <iostream>

#include <queue>
#include <vector>
#include "orderbook.h"

using namespace std;


/**
 *  Stores a list of buy and sell orders for financial securites 
 *  organized time price priority
 * 
*/

Orderbook::Orderbook()
{
    
};


/**
 * The AddOrder(const Order& order) is used to insert a order into the appropriate map for buy or sell orders.
 *
 * @param const Order& order : A const reference to a existing order
 *
 * @return void
 *
 * @note The maps are organized by price(key), and a vector of orders(value).  
 *
 */
void Orderbook::AddOrder(const Order& order)
{
    if(order.getSide() == Side::Buy)
    {   
        auto it = buyOrders.find(order.getPrice()); // Assign the key value of the order to the iterator

        if(it == buyOrders.end()) // If the price level does not exist insert into vector
        {
            buyOrders.insert({order.getPrice(), {order}});    
        }
        else // If the price level does exist insert into existing vector
        {
            it->second.push_back(order);
        }
    }
    else // If not buy order is a sell
    {
        auto it = sellOrders.find(order.getPrice());

        if(it == sellOrders.end())
        {
            sellOrders.insert({order.getPrice(), {order}});
        }
        else
        {
            it->second.push_back(order);
        }
    }
}


/**
 * The CancelOrder(const Order& order)
 *
 * @param const Order& order : A const reference to a existing order
 *
 * @return void
 *
 * @note 
 *
 */
void Orderbook::CancelOrder(const Order& order)
{
    std::vector<Order>& orders = order.getSide() == Side::Buy ? buyOrders[order.getPrice()] : sellOrders[order.getPrice()];

    for(auto it = orders.begin(); it != orders.end(); ++it)
    {
        if(it->getOrderId() == order.getOrderId())
        {
            orders.erase(it);
            return;
        }
        else
        {
            throw std::logic_error("Error that order does not exist");
        }
    }
}

void Orderbook::ValidOrderDay()
{
    std::queue<Order*> Orders;
}
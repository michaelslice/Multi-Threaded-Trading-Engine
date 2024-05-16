#include <iostream>
#include <queue>
#include <vector>
#include <chrono>

#include "orderbook.h"
#include "../CurrentTime/current_time.h"

using namespace std;

/**
 *  The method AddOrder(const Order& order) is used to insert a order into the appropriate map for buy or sell orders.
 *
 *  @param const Order& order : A const reference to a existing order
 *
 *  @return void
 *
 *  @note The maps are organized by price(key), and a vector of orders(value).  
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
 *  The method CancelOrder(const Order& order) is used cancel a order before it is filled 
 *
 *  @param const Order& order : A const reference to a existing order
 *
 *  @return void
 *
 *  @note The method iterates through buyOrders, or sellOrders and removes a order 
 *  the same OrderId before it is filled
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
            throw std::logic_error("Error: The requested order to be cancelled does not exist.");
        }
    }
}


/**
 *  The method ModifyOrder(const Order& order) is used to allow a user to modify an existing orders
 *  OrderType, Price, Quantity, and OrderType
 *
 *  @param const Order& order : A const reference to a existing order
 *
 *  @return void
 *
 *  @note The method will allow the user to change 
 *  
 */
void Orderbook::ModifyOrder(const Order& replaceOrder, const Order& newOrder)
{
    if(replaceOrder.getOrderStatus() != OrderStatus::Filled)
    {
        CancelOrder(replaceOrder);
        AddOrder(newOrder);
    }
    else
    {
        throw std::logic_error("Error: Order cannot be modified it has already been filled.");
    }
}


void Orderbook::ValidForDay()
{
    Time time;
    string hours = time.get_current_time();
    if(stoi(hours.substr(11, 2)) < 4 || stoi(hours.substr(11, 2)) > 16)
    {
        std::cout << '\n' << "Error: Not valid trading hours, valid-Hours 4:00AM-8:00PM." << '\n';
    }


}
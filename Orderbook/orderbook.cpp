#include <iostream>
#include <queue>
#include <vector>
#include <chrono>

#include "orderbook.h"
#include "../CurrentTime/current_time.h"
#include "../ModifyOrder/modifyorder.h"

using namespace std;


// using OrderPointer = std::shared_ptr<Order>;
// using OrderPointers = std::list<OrderPointer>; 

// std::map<double, OrderPointers> buyOrders; 
// std::map<double, OrderPointers> sellOrders;

/**
 *  The method AddOrder(OrderPointer order) is used to insert a order into the appropriate map for buy or sell orders.
 *
 *  @param const OrderPointer order : A const reference to a existing order
 *
 *  @return void
 *
 *  @note The maps are organized by price(key), and a vector of orders(value).  
 *
 */
void Orderbook::AddOrder(OrderPointer order)
{
   /*
    auto& orders = (order->getSide() == Side::Buy) ? buyOrders : sellOrders; 

    orders.emplace(order->getPrice(), order);
    orderIds.insert(orderIds.begin(), order->getOrderId());
*/
}


/**
 *  The method CancelOrder(Order orderid) is used cancel a order before it is filled 
 *
 *  @param const Order orderid : A const reference to a existing order
 *
 *  @return void
 *
 *  @note The method iterates through buyOrders, or sellOrders and removes a order 
 *  the same OrderId before it is filled
 *  
 */
void Orderbook::CancelOrder(Order orderid)
{
   /*
    auto& orders = (orderid.getSide() == Side::Buy) ? buyOrders : sellOrders; 
        
    for(auto& order : orders)
    {
        auto& orders_at_level = order.second;

        auto it = std::find_if(orders_at_level.begin(), orders_at_level.end(),
        [&](const auto& o) { return o->getOrderId() == orderid.getOrderId(); });
        
        if(it != orders_at_level.end())
        {
            orders_at_level.erase(it);
            break;
        }
    }
    */
}


/**
 *  The method ModifyOrder(Order orderid) is used to allow a user to modify an existing orders
 *  OrderType, Price, Quantity, and OrderType
 *
 *  @param const Order orderid : A const reference to a existing order
 *
 *  @return void
 *
 *  @note The method will allow the user to change 
 *  
 */
void Orderbook::ModifyOrder(OrderModify orderid)
{
    auto& orders = (orderid.getSide() == Side::Buy) ? buyOrders : sellOrders; 

}


/**
 *  The method Orderbook::ValidForDay()
 *  
 *
 *  @param const 
 *
 *  @return void
 *
 *  @note 
 *  
 */
void Orderbook::ValidForDay()
{
    Time time;
    string hours = time.get_current_time();

    /*
    
    if(stoi(hours.substr(11, 2)) < 4 || stoi(hours.substr(11, 2)) > 16)
    {
        std::cout << '\n' << "Error: Not valid trading hours, valid-Hours 4:00AM-8:00PM." << '\n';
    }
    
    */


    std::cout << "What mode would you like to run? Enter 1 for Test Mode, Enter 2 for interactive mode, Enter 3 for Cancel Mode ";
    int mode;
    std::cin >> mode;

    switch (mode)
    {
    case 1:
        std::cout << "Test Mode" << '\n';
        
        break;
    case 2:
        std::cout << "Interactive Mode" << '\n';
        
        break;
    case 3:
        std::cout << "Cancel Mode" << '\n';

        break;
    default:
    std::cout << "Error invalid option entered" << '\n';
        break;
    }
}
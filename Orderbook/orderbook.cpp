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
void Orderbook::AddOrder(OrderPointer order)
{
    // auto side_status = order ? order->getSide() == Side::Buy : order->getSide() == Side::Sell;  

    if(order->getSide() == Side::Buy)
    {
        buyOrders.insert(12.00, order);
    }
    else
    {

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
void Orderbook::CancelOrder(OrderPointer order)
{

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
void Orderbook::ModifyOrder(Order orderid)
{

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
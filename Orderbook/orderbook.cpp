#include <iostream>
#include <queue>
#include <vector>
#include <chrono>
#include <fstream>
#include <string>
#include <sstream>
#include <string_view>
#include <iomanip>
#include <map>



#include "orderbook.h"
#include "../CurrentTime/current_time.h"
#include "../ModifyOrder/modifyorder.h"

using namespace std;

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


// using OrderPointer = std::shared_ptr<Order>;
// using OrderPointers = std::list<OrderPointer>; 

// std::map<double, OrderPointers> buyOrders; 
// std::map<double, OrderPointers> sellOrders;


int Orderbook::AddOrder(OrderPointer order, std::string_view file)
{
    auto& orders = (order->getSide() == Side::Buy) ? buyOrders : sellOrders; 
    
    std::ifstream inputFile(static_cast<std::string>(file));
    std::string SideReader;
    std::string TimeInForceReader;
    std::string PriceReader;
    std::string QuantityReader;
    std::string line;
    
    if(!inputFile.is_open())
    {
        std::cout << "Error opening file";
        return 0;
    }

    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);

        iss >> SideReader >> TimeInForceReader >> PriceReader >> QuantityReader;

        bool sideLogic = SideReader == "B" ? sideLogic = true : sideLogic = false; 

        Price _price = std::stoi(PriceReader);
        Quantity _quantity = std::stoi(QuantityReader);
        Side price_;

        std::unordered_map<std::string, Side> const table = { {"B", Side::Buy}, {"S", Side::Sell} };
        auto it = table.find(SideReader);
        if(it != table.end()) { price_ = it->second; };

/*
        std::unordered_map<std::string, OrderType> const table = { 
                                                                  {"GTC", OrderType::GoodTillCancel}
                                                                , {"DAY", OrderType::GoodForDay}
                                                                , {"FAK", OrderType::FillAndKill}
                                                                , {"FOK", OrderType::FillOrKill}
                                                                , {"MKT", OrderType::Market}
        };
        auto it = table.find(SideReader);
       
  */     
       // if(it != table.end()) { _price1 = it->second; };




        // Side _price = static_cast<Side>(SideReader);
        // OrderType _price = static_cast<Side>(TimeInForceReader);
        

// using OrderPointer = std::shared_ptr<Order>;
// using OrderPointers = std::list<OrderPointer>; 

// std::map<double, OrderPointers> buyOrders; 
// std::map<double, OrderPointers> sellOrders;


        if(sideLogic)
        {
            buyOrders.insert(std::make_pair(_price, order));

            for(auto& d : buyOrders)
            {
                std::cout << d.first << d.second;
            }
        }
        else
        {

        }



    }

    inputFile.close();
    return 0;
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
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
 *  The method AddOrder(std::string_view file) reads orders from a file, and based off the 
 *  side of the order Bid or Ask, it will be mapped to BuyOrders, or SellOrders.
 *
 *  @param const std::string_view file : A file that contains orders
 *
 *  @return int : Will return if 
 *
 *  @note The maps are organized by price(key), and a vector of orders(value).  
 *
 */
using OrderBook = std::map<Price, OrderPointer>;

int Orderbook::AddOrder(std::string_view file)
{   
    std::ifstream inputFile(static_cast<std::string>(file));
    std::string SideReader;
    std::string TimeInForceReader;
    std::string PriceReader;
    std::string QuantityReader;
    std::string OrderIdReader;
    std::string line;
    
    if(!inputFile.is_open())
    {
        std::cout << "Error opening file";
        return 0;
    }

    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);

        iss >> SideReader >> TimeInForceReader >> PriceReader >> QuantityReader >> OrderIdReader;

        bool sideLogic = SideReader == "B" ? sideLogic = true  : sideLogic = false; 
        
        Price filePrice = std::stod(PriceReader); 
        Quantity fileQuantity = std::stod(QuantityReader);
        Side fileSide;
        OrderType fileOrderType;
        OrderId fileOrderId = std::stoi(OrderIdReader);

        std::unordered_map<std::string, Side> const sideTable = { {"B", Side::Buy}, {"S", Side::Sell} };
        auto sideIterator = sideTable.find(SideReader);
        if(sideIterator != sideTable.end()) { fileSide = sideIterator->second; };

        std::unordered_map<std::string, OrderType> const orderTypeTable = { 
                                                                  {"GTC", OrderType::GoodTillCancel}
                                                                , {"DAY", OrderType::GoodForDay}
                                                                , {"FAK", OrderType::FillAndKill}
                                                                , {"FOK", OrderType::FillOrKill}
                                                                , {"MKT", OrderType::Market}
        };
        auto orderTypeIterator = orderTypeTable.find(TimeInForceReader);   
        if(orderTypeIterator != orderTypeTable.end()) { fileOrderType = orderTypeIterator->second; };     

        // OrderBook& orders = sideLogic ? buyOrders : sellOrders; // Initialize as reference to maintain throughout program
        OrderBook& orders = sideLogic ? buyOrders : sellOrders; 
        
        
        OrderPointer ptr (new Order(filePrice, fileQuantity, fileSide, fileOrderType, fileOrderId));
        orders.insert(std::make_pair(filePrice, ptr));

        for(auto& d : orders)
        {
            std::cout << "First Value " << d.first << " Second Value " << d.second->getQuantity() << '\n';
        }
    }

    inputFile.close();
    return 0;
}


/**
 *  The method CancelOrder(Order orderid) is used cancel a order before it is filled 
 *
 *  @param const OrderPointer orderid : A shared pointer to a Order object
 *
 *  @return void
 *
 *  @note 
 *  
 */
void Orderbook::CancelOrder(OrderPointer orderid)
{    
    auto& orders = (orderid->getSide() == Side::Buy) ? buyOrders : sellOrders; 
    if(orders.size() == 0) { throw std::logic_error("Error: the OrderBook does not contain any orders to remove."); };

    std::cout << "TESTING REMOVAL ORDER" << '\n';

    bool ans = false;

    for(auto it = orders.begin(); it != orders.end(); ++it)
    {
        if(orderid->getOrderId() == it->second->getOrderId())
        {
            std::cout << "Success order removed" << '\n';
            orders.erase(it);
            ans = true;
            break;
        }
    }

    if(ans == false)
    {
        throw std::logic_error("Error: The requested order to remove does not exist in the OrderBook");
    }
    
    for(auto& d : orders)
    {
        std::cout << "First Value " << d.first << " Second Value " << d.second->getQuantity() << '\n';
    }
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
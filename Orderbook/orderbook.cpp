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


using namespace std;
using OrderBook = std::map<Price, OrderPointer>;

/**
 *  The method AddOrder(std::string_view file) reads Orders from a file, and 
 *  add Orders to the BuyOrders, or SellOrders map.
 *
 *  @param const std::string_view file : A file that contains orders
 *
 *  @return int 
 *
 *  @note The maps are organized by price, and a shared ptr to the Order class.  
 *
 */
int Orderbook::AddOrder(std::string_view file)
{   
    ClearBook(buyOrders, sellOrders);
    
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

        OrderBook& orders = sideLogic ? buyOrders : sellOrders; // Initialize as reference to maintain throughout program
        
        OrderPointer ptr (new Order(filePrice, fileQuantity, fileSide, fileOrderType, fileOrderId));
        orders.insert(std::make_pair(filePrice, ptr));        
    }

    Test test;
    test.printOrderbook(buyOrders, sellOrders);

    inputFile.close();
    return 0;
}


/**
 *  The method CancelOrder(Order order) is used cancel a Order before it is filled 
 *
 *  @param const OrderPointer order : A shared pointer to a Order object
 *
 *  @return void
 *  
 */
void Orderbook::CancelOrder(OrderPointer order)
{    
    auto& orders = (order->getSide() == Side::Buy) ? buyOrders : sellOrders; 
    if(orders.size() == 0) { throw std::logic_error("Error: the OrderBook does not contain any orders to remove."); };
    bool validId = false;

    std::cout << "TESTING REMOVAL ORDER" << '\n';

    for(auto it = orders.begin(); it != orders.end(); ++it)
    {
        if(order->getOrderId() == it->second->getOrderId())
        {
            std::cout << "Success order removed" << '\n';
            orders.erase(it);
            validId = true;
            break;
        }
    }

    if(validId == false) { throw std::logic_error("Error: The requested order to remove does not exist in the OrderBook"); }
}


/**
 *  The method ModifyOrder(OrderPointer order) is used to find a Order in the Orderbook
 *  and change data for Price, Quantity, Side, and OrderType
 *
 *  @param const OrderPointer order : A shared pointer to a Order object
 *
 *  @return void
 *
 *  @note If the OrderId is valid, the order will be cancelled and replaced, I did it 
 *  this way because if a order is modified it will lose priority in the matching
 *  engine, due to the FIFO priority.
 * 
 *  CME FIFO Documentation: https://www.cmegroup.com/confluence/display/EPICSANDBOX/Supported+Matching+Algorithms
 *  
 */
void Orderbook::ModifyOrder(OrderPointer order)
{
    auto& orders = (order->getSide() == Side::Buy) ? buyOrders : sellOrders; 

    for(auto it = orders.begin(); it != orders.end(); ++it)
    {
        if(it->second->getOrderId() == order->getOrderId())
        {
            orders.erase(it);
            orders.insert(std::make_pair(order->getPrice(), order));
        }
    }
}


/**
 *  The method ClearBook is used to erase all orders from both sides of the Orderbook
 *  
 *  @param std::map<Price, OrderPointer>& _buyOrders : Buy side of Orderbook 
 *
 *  @param std::map<Price, OrderPointer>& _sellOrders : Sell side of Orderbook
 *  
 * @return void
 *  
 */
void Orderbook::ClearBook(std::map<Price, OrderPointer>& _buyOrders, std::map<Price, OrderPointer>& _sellOrders)
{
    for(auto buyIter = _buyOrders.begin(); buyIter != _buyOrders.end(); ++buyIter)
    {
        _buyOrders.erase(buyIter);
    }
        for(auto sellIter = _sellOrders.begin(); sellIter != _sellOrders.end(); ++sellIter)
    {
        _sellOrders.erase(sellIter);
    }
}


/**
 *  The method Orderbook getOrderBookSize returns the size of the passed in Orderbook
 *  
 *  @param std::map<Price, OrderPointer>& orderbook : One side of the Orderbook
 *
 *  @return void
 *  
 */
int getOrderBookSize(std::map<Price, OrderPointer>& orderbook)
{
    return orderbook.size();
}


/**
 *  The method Orderbook::ValidForDay()
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
    Test test;
    std::string_view filepath = "Multi-Threaded-Trading-Engine/Test/TestFiles/orders.txt";
    test.readFile("orders.txt");
    AddOrder("orders.txt");
    MatchingEngine(buyOrders, sellOrders);
}

Orderbook::~Orderbook()
{

};  
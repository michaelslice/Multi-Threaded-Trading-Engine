#ifndef ORDERBOOK_H
#define ORDERBOOK_H
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <thread>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include "../Order/order.h"

/**
 *  The class that will facilate the logic for buyers and sellers to submit trades
 * 
 * 
*/

// Placing the price as the key allows for orders to be organized by price level
// Price is the index, Key is vector of orders

using PriveLevelMap = std::map<double, OrderPointers>; 

class Orderbook
{

private:
    std::map<double, OrderPointers> buyOrders; 
    std::map<double, OrderPointers> sellOrders;

    mutable std::mutex mtx;
    std::thread orderThread;
    std::condition_variable shutdownConditionVariable_;
    std::atomic<bool> shutdown_{ false };


public:
    Orderbook() = default;
    Orderbook(PriveLevelMap _buyOrders, PriveLevelMap _sellOrders)
    : buyOrders(_buyOrders)
    , sellOrders(_sellOrders)
    {};



    // If the compiler matches a function call to any of the following, generate a compilation error 
    Orderbook(const Orderbook& other) = delete; // Copy constructor
    Orderbook& operator=(const Orderbook& other) = delete; // Copy assignment operator
    Orderbook(Orderbook&& other) = delete; // Move constructor
    Orderbook& operator=(Orderbook&& other) = delete; // Move assignment operator    
    ~Orderbook();    
    
    void ValidForDay();
    
    // TODO NEED TO IMPLEMENT A BETTER SOLUTION
    void AddOrder(OrderPointer order);
    void CancelOrder(OrderPointer order);
    void ModifyOrder();
};


#endif
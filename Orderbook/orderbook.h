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
#include "../OrderId/orderid.h"
#include "../ModifyOrder/modifyorder.h"
#include "../Using/using.h"

class Orderbook
{

private:
    std::map<Price, OrderPointer> buyOrders; 
    std::map<Price, OrderPointer> sellOrders;

    std::vector<OrderId> orderIds;

    mutable std::mutex mtx;
    std::thread orderThread;
    std::condition_variable shutdownConditionVariable_;
    std::atomic<bool> shutdown_{ false };
public:
    Orderbook() = default;
    // If the compiler matches a function call to any of the following, generate a compilation error 
    Orderbook(const Orderbook& other) = delete; // Copy constructor
    Orderbook& operator=(const Orderbook& other) = delete; // Copy assignment operator
    Orderbook(Orderbook&& other) = delete; // Move constructor
    Orderbook& operator=(Orderbook&& other) = delete; // Move assignment operator    
    ~Orderbook() { };    
    
    void ValidForDay();
    int AddOrder(std::string_view file);
    void CancelOrder(OrderPointer order);
    void ModifyOrder(OrderPointer order);
};

#endif
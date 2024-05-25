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
#include <chrono>
#include <string_view>
#include "../CurrentTime/current_time.h"
#include "../Orderbook/orderbook.h"
#include "../Test/test.h"
#include "../MatchingEngine/matchingengine.h"
#include "../Order/order.h"
#include "../OrderId/orderid.h"
#include "../ModifyOrder/modifyorder.h"
#include "../Using/using.h"
#include "../Trade/trade.h" 
#include "../TimeInForce/timeinforce.h"

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
    Orderbook();
    // If the compiler matches a function call to any of the following, generate a compilation error 
    Orderbook(const Orderbook& other) = delete; 
    Orderbook& operator=(const Orderbook& other) = delete; 
    Orderbook(Orderbook&& other) = delete; 
    Orderbook& operator=(Orderbook&& other) = delete;    
    ~Orderbook();    
    
    void ValidForDay();
    int AddOrder(std::string_view file);
    void CancelOrder(OrderPointer order);
    void ModifyOrder(OrderPointer order);

    void ClearBook(std::map<Price, OrderPointer>& _buyOrders, std::map<Price, OrderPointer>& _sellOrders);
    int getOrderBookSize(std::map<Price, OrderPointer>& orderbook);
};

#endif
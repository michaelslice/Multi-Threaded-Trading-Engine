#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include "orderid.h"

void OrderID::get_OrderId()
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    std::srand(time(&now_time)); 
    this->OrderId = std::rand();
}

bool operator==(const OrderID& lhs, const OrderID& rhs) 
{
    return lhs.OrderId == rhs.OrderId;
}
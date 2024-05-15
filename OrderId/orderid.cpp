#include <iostream>

#include <chrono>
#include <ctime>
#include <cstdlib>

#include "orderid.h"


void OrderId::get_OrderId()
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    
    std::srand(time(&now_time)); // Use to current time as the seed value
    this->OrderId = std::rand();
}
#include <iostream>
#include <chrono>  
#include <ctime>   
#include <sstream> 
#include <iomanip> 
#include <string>  
#include "current_time.h"

using namespace std;
using namespace std::chrono;

std::string Time::get_current_time()
{   
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    
    this->time = ss.str();

    return ss.str();
}
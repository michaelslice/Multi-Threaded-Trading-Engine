#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>

using namespace std;
using namespace std::chrono;

class Time
{
private:
    string time;
public:
    auto get_current_time();
};


#endif
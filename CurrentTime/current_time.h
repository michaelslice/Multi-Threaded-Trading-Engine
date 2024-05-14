#ifndef CURRENT_TIME_H
#define CURRENT_TIME_H
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>

using namespace std;
using namespace std::chrono;

class Time
{
private:

public:
    string get_current_time();
};


#endif
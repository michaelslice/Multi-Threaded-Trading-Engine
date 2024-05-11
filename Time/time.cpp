#include <iostream>
#include <chrono>
#include <ctime>

#include "time.h"

using namespace std;
using namespace std::chrono;


auto Time::get_current_time()
{   
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_second = end - start;

    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "Finished Computation at " << std::ctime(&end_time)
    << "elapsed seconds " << elapsed_seconds.count() << "s" << std::endl; 
};


#include <iostream>
#include <iomanip>
#include "CurrentTime/current_time.h"

using namespace std;

int main()
{
    Time time;

    string data = time.get_current_time(); 
    std::cout << std::endl;
    std::cout << data << std::endl;

    return 0;
}

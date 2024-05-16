#include <iostream>
#include <iomanip>
#include "CurrentTime/current_time.h"

#include "Orderbook/orderbook.h"

using namespace std;

int main()
{
    Time time;
    Orderbook orderbook;

    orderbook.ValidForDay();

    return 0;
}

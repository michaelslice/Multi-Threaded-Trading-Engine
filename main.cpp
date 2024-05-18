#include <iostream>
#include <iomanip>
#include "CurrentTime/current_time.h"

#include "Orderbook/orderbook.h"


#include "Test/test.h"




using namespace std;

int main()
{
//    Time time;
  //  Orderbook orderbook;

    //orderbook.ValidForDay();


    Test test;

    test.readFile("orders.txt");

    return 0;
}

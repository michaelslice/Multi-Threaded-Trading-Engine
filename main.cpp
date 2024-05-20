#include <iostream>
#include <iomanip>
#include <chrono>
#include <string_view>
#include "CurrentTime/current_time.h"
#include "Orderbook/orderbook.h"
#include "Test/test.h"


using namespace std;

int main()
{
  // Time time;
  // Orderbook orderbook;
  //orderbook.ValidForDay();


  Test test;

  std::string_view filepath = "Multi-Threaded-Trading-Engine/Test/TestFiles/orders.txt";
  test.readFile("orders.txt");

  return 0;
}

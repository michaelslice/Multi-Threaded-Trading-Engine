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


  Orderbook book;

  Price p = 120;
  Quantity q = 50;
  Side s= Side::Buy;
  OrderType ot = OrderType::GoodTillCancel;
  OrderId oi = 1;

  OrderPointer ptr (new Order(p, q, s, ot, oi));

  book.AddOrder("orders.txt");
  book.CancelOrder(ptr);

  return 0;
}

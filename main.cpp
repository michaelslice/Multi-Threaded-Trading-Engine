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

  Price p1 =  2120;
  Quantity q1 = 250;
  Side s1 = Side::Buy;
  OrderType ot1 = OrderType::GoodTillCancel;
  OrderId oi1 = 5;

OrderPointer ptr1 (new Order(p1, q1, s1, ot1, oi1));

  book.ModifyOrder(ptr1);

  return 0;
}

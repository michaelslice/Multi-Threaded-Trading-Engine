#ifndef ORDER_H
#define ORDER_H
#include <iostream>

#include "../Side/side.h"
#include "../OrderType/ordertype.h"
#include "../OrderId/orderid.h"
#include "../OrderStatus/orderstatus.h"
#include "../CurrentTime/current_time.h"
#include "../Using/using.h"


/**
 * 
 *  The class Order represents all characteristics of a valid order
 * 
 *  uint32_t price : Represents a unsigned integer value of a price
 * 
 *  uint32_t quantity : Represents a quantity of a valid security
 * 
 *  Side orderside; : Buy order (bid), or sell order (ask)
 * 
 *  OrderId orderid : A stochastic value that is used to identify a particular order
 * 
 *  Timestamp timestamp : The timestamp of the order being placed
 * 
 *  OrderStatus orderstatus : Wether the order is oepn, filled, partially filled 
 * 
 *  OrderType ordertype : Refers to the specific type of order being placed by the trader, 
 *  such as limit order, market order, stop order, stop-limit order 
 * 
 * 
*/

class Order
{
private:
    Price price;
    Quantity quantity;
    Side orderside; 
    OrderId orderid;
    Time timestamp;
    OrderStatus orderstatus;
    OrderType ordertype;
public:
    Order(Price _price, Quantity _quantity, Side _orderside, OrderId _orderid, Time _timestamp, OrderStatus _orderstatus, OrderType _ordertype):
    price(_price), quantity(_quantity), orderside(_orderside), orderid(_orderid), timestamp(_timestamp), orderstatus(_orderstatus), ordertype(_ordertype) {};

    Price getPrice() { return price; };
    Quantity getQuantity() { return quantity; };
    Side getSide() { return orderside; };
    OrderId getOrderId() { return orderid; };
    Time getTimestamp() { return timestamp; };
    OrderStatus getOrderStatus() { return orderstatus; };
    OrderType getOrderType() { return ordertype; };
};

#endif
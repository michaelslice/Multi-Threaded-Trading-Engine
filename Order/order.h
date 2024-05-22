#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <memory>
#include <algorithm>
#include <list>

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
 *  Price price : Represents a unsigned integer value of a price
 * 
 *  Quantity quantity : Represents a quantity of a valid security
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
 *  Can also be considered time in force
*/

class Order
{
 
private:
    Price price;
    Side orderside; 
    OrderId orderid;
    Time timestamp;
    OrderStatus orderstatus;
    OrderType ordertype;

    Quantity initialQuantity;
    Quantity remainingQuantity;
public:
    Order(Price _price, Quantity _quantity, Side _orderside, OrderId _orderid, Time _timestamp, OrderStatus _orderstatus, OrderType _ordertype)
        : price(_price)
        , orderside(_orderside)
        , orderid(_orderid)
        , timestamp(_timestamp)
        , orderstatus(_orderstatus)
        , ordertype(_ordertype)
        , initialQuantity(_quantity)
        , remainingQuantity(_quantity) 
    {};

    // If a order is modifed during trade this constructor should be used
    Order(Price _price, Quantity _quantity, Side _orderside, OrderId _orderid)
        : price(_price)
        , orderside(_orderside)
        , orderid(_orderid)
        , initialQuantity(_quantity)
        , remainingQuantity(_quantity) 
    {};

    // If order is added from a file this constructor should be used
    Order(Price _price, Quantity _quantity, Side _orderside, OrderType _ordertype, OrderId _orderid)
        : price(_price)
        , orderside(_orderside)
        , orderid(_orderid)
        , ordertype(_ordertype)
        , initialQuantity(_quantity)
        , remainingQuantity(_quantity) 
    {};

    Price getPrice() const { return price; };
    Side getSide() const { return orderside; };
    OrderId getOrderId() const { return orderid; };
    Time getTimestamp() const { return timestamp; };
    OrderStatus getOrderStatus() const { return orderstatus; };
    OrderType getOrderType() const { return ordertype; };







    Quantity getQuantity() const { return initialQuantity; };
    Quantity getRemainingQuantity() const { return remainingQuantity; };
    Quantity getFilledQuantity() const { return getFilledQuantity() - getRemainingQuantity(); };
};

using OrderPointer = std::shared_ptr<Order>;
using OrderPointers = std::list<OrderPointer>; 
using OrderIds = std::vector<OrderId>;

#endif
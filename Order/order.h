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


class Order
{
    friend std::ostream& operator<<(std::ostream& os, const Order& obj);
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

    // If a order is modifed during a trade this constructor should be used
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
    Quantity setTradeQuantity(Quantity buy) { initialQuantity -= buy; return initialQuantity; };
};

using OrderPointer = std::shared_ptr<Order>;
using OrderPointers = std::list<OrderPointer>; 
using OrderIds = std::vector<OrderId>;

#endif
#ifndef MODIFYORDER_H
#define MODIFYORDER_H
#include <iostream>
#include <memory>
#include "../Side/side.h"
#include "../OrderType/ordertype.h"
#include "../OrderId/orderid.h"
#include "../OrderStatus/orderstatus.h"
#include "../CurrentTime/current_time.h"
#include "../Using/using.h"
#include "../Order/order.h"

class OrderModify
{
private:
    Price _price;
    Quantity _quantity;
    Side _side;
    OrderId _orderid;
public:
    Price getPrice() const { return _price; };
    Side getSide() const { return _side; };
    OrderId getOrderId() const { return _orderid; };
    Quantity getQuantity() const { return _quantity; };

    OrderModify(Price __price, Quantity __quantity, Side __side, OrderId __orderid)
        : _price(__price)
        , _quantity(__quantity)
        , _side(__side)
        , _orderid(__orderid) 
    { };

    OrderPointer ModifyAOrder(OrderModify order) const
    {
       return std::make_shared<Order>(getPrice(), getQuantity(), getSide(), getOrderId());
    };

};

#endif
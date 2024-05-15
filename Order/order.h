#ifndef ORDER_H
#define ORDER_H
#include <iostream>

#include "../Side/side.h"
#include "../OrderType/ordertype.h"
#include "../OrderId/orderid.h"

/**
 * @uint32_t price : Represents a unsigned integer value representing a   
 * 
 * 
*/

class Order
{
private:
    uint32_t price;
    uint32_t quantity;
    Side orderside; // Buy order (bid), or sell order (ask)
    OrderId orderid;
    Timestamp;
    OrderStatus;
    OrderType ordertype;
};

#endif
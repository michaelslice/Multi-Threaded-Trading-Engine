#ifndef ORDERID_H
#define ORDERID_H
#include <iostream>

class OrderID
{
    friend bool operator==(const OrderID&, const OrderID&);
private:
    uint64_t OrderId;
public:
    void get_OrderId();
};

#endif
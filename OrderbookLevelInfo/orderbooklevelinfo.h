#ifndef ORDERBOOKINFO_H
#define ORDERBOOKINFO_H
#include <iostream>
#include "../Using/using.h"

class OrderbookLevelInfo
{
private:
    Price bids;
    Price asks;
public:
    OrderbookLevelInfo(const Price& bids_, const Price& asks_)
        : bids(bids_)
        , asks(asks_)
    {};

    const Price& getBids() const { return bids; };
    const Price& getAsks() const { return asks; };
};

#endif
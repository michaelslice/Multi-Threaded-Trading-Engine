#include <iostream>

enum OrderType
{
    MarketOrder,
    LimitOrder,
    StopLossOrder,
    StopLimitOrder,
    AON, // All Or None
    IOC, // Immediate Or Cancel
    FOK, // Fill Or Kill
    GTC, // Good Till Cancelled
    Day, 
    TakeProfit,
};
#include <iostream>

enum class OrderType
{
    Market,
    Limit,
    StopLoss,
    StopLimit,
    AON, // All Or None
    IOC, // Immediate Or Cancel
    FOK, // Fill Or Kill
    FAK, // Fill And Kill
    GTC, // Good Till Cancelled
    GoodForDay, 
    TakeProfit,
};
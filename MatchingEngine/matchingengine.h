#ifndef MATCHINGENGINE_H
#define MATCHINGENGINE_H
#include <iostream>

#include "../Orderbook/orderbook.h"

/**
 *  The class that will facilate the logic for executing trades between buyers and sellers
 * 
 * 
*/

class MatchingEngine
{
private:
public:
    MatchingEngine(PriveLevelMap buyOrders, PriveLevelMap sellOrders);
    void ExecuteTrade();
};



#endif
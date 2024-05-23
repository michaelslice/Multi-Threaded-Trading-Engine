#ifndef TEST_H
#define TEST_H
#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <map>
#include <memory>

#include "test.h"
#include "../Orderbook/orderbook.h"
#include "../CurrentTime/current_time.h"
#include "../ModifyOrder/modifyorder.h"
#include "../MatchingEngine/matchingengine.h"


class Test
{
private:
public:
    int readFile(std::string_view file);
    void printOrderbook(std::map<Price, OrderPointer>& _buyOrders, std::map<Price, OrderPointer>& _sellOrders);
    void printRemainingOrderbook(std::map<Price, OrderPointer>& _buyOrders, std::map<Price, OrderPointer>& _sellOrders);
    void printFile();
};


#endif
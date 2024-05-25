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
#include "../CurrentTime/current_time.h"
#include "../Order/order.h" 

class Test
{
public:
    int readFile(std::string_view file);
    void printOrderbook(std::map<Price, OrderPointer>& _buyOrders, std::map<Price, OrderPointer>& _sellOrders);
    void printRemainingOrderbook(std::map<Price, OrderPointer>& _buyOrders, std::map<Price, OrderPointer>& _sellOrders);
    void printFilledBuyOrders(std::map<Price, OrderPointer>::iterator buyIter);
    void printFilledSellOrders(std::reverse_iterator<std::conditional<false, std::map<Price, OrderPointer>::const_iterator, std::_Rb_tree_iterator<std::pair<const Price, OrderPointer>>>::type> sellIter);
};

#endif
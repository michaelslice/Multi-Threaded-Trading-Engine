#include <iostream>
#include "timeinforce.h"
#include <map>


void TimeInForce::DaySellOrders(std::map<Price, OrderPointer>& _sellOrders)
{
    for (auto it = _sellOrders.begin(); it != _sellOrders.end(); ++it)
    {
        if (it->second->getOrderType() == OrderType::GoodForDay)
        {
            _sellOrders.erase(it);
        }
    }
}


void TimeInForce::DayBuyOrders(std::map<Price, OrderPointer>& _buyOrders)
{
    for (auto it = _buyOrders.begin(); it != _buyOrders.end(); ++it)
    {
        if (it->second->getOrderType() == OrderType::GoodForDay)
        {
            _buyOrders.erase(it);
        }
    }
}


void TimeInForce::FillOrKillSellOrders(std::map<Price, OrderPointer>& _sellOrders)
{
    for (auto it = _sellOrders.begin(); it != _sellOrders.end(); ++it)
    {
        if (it->second->getOrderType() == OrderType::FillOrKill)
        {
            _sellOrders.erase(it);
        }
    }
}


void TimeInForce::FillOrKillBuyOrders(std::map<Price, OrderPointer>& _buyOrders)
{
    for (auto it = _buyOrders.begin(); it != _buyOrders.end(); ++it)
    {
        if (it->second->getOrderType() == OrderType::FillOrKill)
        {
            _buyOrders.erase(it);
        }
    }
}


void TimeInForce::MarketSellOrders(std::map<Price, OrderPointer>& _sellOrders)
{
    for (auto it = _sellOrders.begin(); it != _sellOrders.end(); ++it)
    {
        if(it->second->getOrderType() == OrderType::Market || it->second->getPrice() == 0)
        {
            _sellOrders.erase(it);
        }
    }
}


void TimeInForce::MarketBuyOrders(std::map<Price, OrderPointer>& _buyOrders)
{
    for(auto it = _buyOrders.begin(); it != _buyOrders.end(); ++it)
    {
        if(it->second->getOrderType() == OrderType::Market && it->second->getPrice() == 0)
        {
            _buyOrders.erase(it);
        }
    }
}
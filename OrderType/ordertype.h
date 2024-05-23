#ifndef ORDERTYPE_H
#define ORDERTYPE_H
#include <iostream>
#include <string_view>

enum class OrderType
{
	GoodTillCancel,
	FillAndKill,
	FillOrKill,
	GoodForDay,
	Market,
};

constexpr std::string_view getOrderTypeName(OrderType ordertype)
{
	switch (ordertype)
    {
		case OrderType::GoodTillCancel: return "GoodTillCancel";
		case OrderType::FillAndKill:   return "FillAndKill";
		case OrderType::FillOrKill:  return "FillOrKill";
		case OrderType::GoodForDay:  return "GoodForDay";
		case OrderType::Market:  return "Market";
		default:    return "???";
    }
};

#endif
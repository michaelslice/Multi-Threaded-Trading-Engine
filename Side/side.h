#ifndef SIDE_H
#define SIDE_H

#include <iostream>
#include <string_view>

enum class Side
{
    Buy,
    Sell,
};

constexpr std::string_view getOrderSide(Side ordertype)
{
	switch (ordertype)
    {
		case Side::Buy: return "Buy";
		case Side::Sell:   return "Sell";
		default:    return "???";
    }
};


#endif
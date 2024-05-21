#ifndef ORDERTYPE_H
#define ORDERTYPE_H


#include <iostream>

enum class OrderType
{
	GoodTillCancel,
	FillAndKill,
	FillOrKill,
	GoodForDay,
	Market,
};

#endif
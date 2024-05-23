#ifndef ORDERBOOKINFO_H
#define ORDERBOOKINFO_H
#include <iostream>

#include "../TradeInfo/tradeinfo.h"

// Show info regarding a trade info

class Trade
{
private:
    TradeInfo bidTrade;
    TradeInfo bidAsk;
public:
    Trade() = default;
    
    Trade(const TradeInfo& bidTrade_, const TradeInfo& bidAsk_)
        : bidTrade(bidTrade_)
        , bidAsk(bidAsk_)
    {};

    const TradeInfo& getbidTrade() const { return bidTrade; };
    const TradeInfo& getbidAsk() const { return bidAsk; };

};

#endif
#include <iostream>
#include <iomanip>

#include "matchingengine.h"
#include "../Test/test.h"


//    std::cout << "Buy order: Price " << buyIter->first << " Quantity " << buyIter->second->getQuantity() << '\n'; 
//    std::cout << "Sell order: Price " << sellIter->first << " Quantity " << sellIter->second->getQuantity() << '\n'; 

//  buyOrders.erase(buyIter);
// sellIter = std::reverse_iterator(sellOrders.erase(std::next(sellIter).base())); 



MatchingEngine::MatchingEngine(std::map<Price, OrderPointer>& buyOrders, std::map<Price, OrderPointer>& sellOrders)
{
    std::cout << '\n' << "TESTING MATCHING ENGINE" << '\n';
    
    while(!buyOrders.empty())
    {
        while(!sellOrders.empty())
        {
            if(buyOrders.size() == 0 || sellOrders.size() == 0) 
            {
                std::cout << "Size of buyOrders " << buyOrders.size() << '\n';
                std::cout << "Size of sellOrders " << sellOrders.size() << '\n';
                
                if(buyOrders.size() == 0) { std::cout << "Error no more buy orders" << '\n'; } else { std::cout << "Error no more sell orders" << '\n'; };
                break;
            }

            auto buyIter = buyOrders.begin();
            auto sellIter = sellOrders.rbegin();

            // If the bid is aggressive
            if(sellIter->second->getPrice() <= buyIter->second->getPrice())
            {
                std::cout << "TEST AGGRESSIVE ORDER" << '\n';

                auto ans = std::min(buyIter->second->getQuantity(), sellIter->second->getQuantity() );
                std::cout << "MIN VALUE " <<  ans << '\n';
                buyIter->second->getQuantity()& - ans;
                sellIter->second->getQuantity()& - ans;

    std::cout << "Buy order: Price " << buyIter->first << " Quantity " << buyIter->second->getQuantity() << '\n'; 
    std::cout << "Sell order: Price " << sellIter->first << " Quantity " << sellIter->second->getQuantity() << '\n'; 


                if(buyIter->second->getQuantity() == 0)
                {
                  
                  std::cout << "buy filled" << '\n';
                    buyOrders.erase(buyIter);
                }
                else if(  sellIter->second->getQuantity() == 0)
                {
                   std::cout << "sell filled" << '\n';
                   
                    sellIter = std::reverse_iterator(sellOrders.erase(std::next(sellIter).base())); 
                }
            }
            // If bid is passive
            else 
            {
                std::cout << "TEST PASSIVE ORDER" << '\n';
                
                auto ans = std::min(buyIter->second->getQuantity(), sellIter->second->getQuantity() );
                std::cout << "MIN VALUE " <<  ans << '\n';
                buyIter->second->getQuantity()& - ans;
                sellIter->second->getQuantity()& - ans;
                
    std::cout << "Buy order: Price " << buyIter->first << " Quantity " << buyIter->second->getQuantity() << '\n'; 
    std::cout << "Sell order: Price " << sellIter->first << " Quantity " << sellIter->second->getQuantity() << '\n'; 



                if(buyIter->second->getQuantity() == 0)
                {
                  
                  std::cout << "buy filled" << '\n';
                    buyOrders.erase(buyIter);
                }
                else if(  sellIter->second->getQuantity() == 0)
                {
                   std::cout << "sell filled" << '\n';
                   
                    sellIter = std::reverse_iterator(sellOrders.erase(std::next(sellIter).base())); 
                }
            }
            
            buyOrders.erase(buyIter);
            sellIter = std::reverse_iterator(sellOrders.erase(std::next(sellIter).base())); 



            buyIter++;
            sellIter++;
        }
    }
    std::cout << "Trading Session Completed" << '\n';

    Test test;
    test.printRemainingOrderbook(buyOrders, sellOrders);
}


void MatchingEngine::ExecuteTrade()
{
    // TODO perform actions to execute the trade, updating balances, logging
    // TODO update account balances, record the trade in a ledger
}


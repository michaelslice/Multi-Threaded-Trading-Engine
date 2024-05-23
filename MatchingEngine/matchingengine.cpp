#include <iostream>
#include "matchingengine.h"



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
            

            std::cout << buyOrders.size() << '\n';
            std::cout << sellOrders.size() << '\n';
  
                
            auto buyIter = buyOrders.begin();
            auto sellIter = sellOrders.rbegin();



               buyOrders.erase(buyIter);
               sellIter = std::reverse_iterator(sellOrders.erase(std::next(sellIter).base())); 


            buyIter++;
            sellIter++;

        
         

        }
        
    }
}


void MatchingEngine::ExecuteTrade()
{
    // TODO perform actions to execute the trade, updating balances, logging
    // TODO update account balances, record the trade in a ledger
}


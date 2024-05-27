# Multi-Threaded-Trading-Engine
A simple implementation of an Orderbook and Matching Engine designed to read orders from a file, and then execute a trading session between the bid and ask side.

## Supported Orders
- Add
- Remove
- Modify
## Supported Order Types
- GoodTillCancel
- FillAndKill
- FillOrKill
- GoodForDay
- Market

## First Time User
1. ```git clone https://github.com/michaelslice/Multi-Threaded-Trading-Engine.git```
2. ```cd Multi-Threaded-Trading-Engine```
3. ```cd Build```
4. ```cmake ..```
5. ```CMake --build .```
6. ```./TRADING```

## Changing Project
If any changes are made in the project 
1. ```cd Build```
2. ```make```
3. ```./TRADING```

# Example Trading Session
## Orders Placed
All orders within orders.txt will be displayed.

![OrdersPlaced](https://github.com/michaelslice/Multi-Threaded-Trading-Engine/assets/110714088/71cb5a59-0c9e-47fe-8b34-71b9820ddc8f)
### Bid Side
All buy side orders will be displayed, and added to the BuyOrders map. <br>

![image](https://github.com/michaelslice/Multi-Threaded-Trading-Engine/assets/110714088/8b77a9d3-f58e-48c9-a106-98ba38dcfe75)
### Ask Side
All sell side orders will be displayed, and added to the SellOrders map. <br>

![image](https://github.com/michaelslice/Multi-Threaded-Trading-Engine/assets/110714088/4aba34f6-6bac-493c-872a-20bedf5233ef)
### Trade Feed
Every trade executed will be printed, in the format of <br>
- Side: The side that executed the trade.
- Price: The price traded at.
- Quantity: The amount of shares traded.
- The ID of the order that executed the trade. <br>

![image](https://github.com/michaelslice/Multi-Threaded-Trading-Engine/assets/110714088/7716f0f6-5f7b-4833-bb70-c9f0f03ee3a0)
### Trade Report
Information for the trading session will be displayed. <br>

![image](https://github.com/michaelslice/Multi-Threaded-Trading-Engine/assets/110714088/556f3cbd-7f7e-4307-8ae5-672700776e8b)

## Remaining Unfilled Orders
If there are no more orders on either side, the user will be alerted of orders that were unable to be filled. <br>

![image](https://github.com/michaelslice/Multi-Threaded-Trading-Engine/assets/110714088/2e398d6d-3f04-40bf-871f-b2196509f571)


## Resources

- An Introduction to Limit Order Books : [Link](https://www.machow.ski/posts/2021-07-18-introduction-to-limit-order-books/) <br>
- Nasdaq TotalView-ITCH 5.0 : [Link](https://www.nasdaqtrader.com/content/technicalsupport/specifications/dataproducts/NQTVITCHSpecification.pdf) <br>
- CME Globex Matching Algorithms : [Link](https://www.cmegroup.com/confluence/display/EPICSANDBOX/CME+Globex+Matching+Algorithms) <br>
- CME Supported Matching Algorithms : [Link](https://www.cmegroup.com/confluence/display/EPICSANDBOX/Supported+Matching+Algorithms) <br>
- CME Globex Matching Algorithms Steps : [Link](https://www.cmegroup.com/confluence/display/EPICSANDBOX/CME+Globex+Matching+Algorithm+Steps)  <br>

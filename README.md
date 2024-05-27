# Multi-Threaded-Trading-Engine
A simple implementation of an Orderbook and Matching Engine designed to read orders from a file, and then execute a trading session between the bid side and ask side.

# Supported Orders
- Add
- Remove
- Modify
# Supported Order Types
- GoodTillCancel
- FillAndKill
- FillOrKill
- GoodForDay
- Market

# First Time User
1. git clone https://github.com/michaelslice/Multi-Threaded-Trading-Engine.git
2. cd Multi-Threaded-Trading-Engine
3. cd Build
4. cmake ..
5. CMake --build .
6. ./TRADING

# Adding Changing
If any changes are made simply run make, then run the command ./TRADING <br>

# Resources

- An Introduction to Limit Order Books : [Link](https://www.machow.ski/posts/2021-07-18-introduction-to-limit-order-books/) <br>
- Nasdaq TotalView-ITCH 5.0 : [Link](https://www.nasdaqtrader.com/content/technicalsupport/specifications/dataproducts/NQTVITCHSpecification.pdf) <br>
- CME Globex Matching Algorithms : [Link](https://www.cmegroup.com/confluence/display/EPICSANDBOX/CME+Globex+Matching+Algorithms) <br>
- CME Supported Matching Algorithms : [Link](https://www.cmegroup.com/confluence/display/EPICSANDBOX/Supported+Matching+Algorithms) <br>
- CME Globex Matching Algorithms Steps : [Link](https://www.cmegroup.com/confluence/display/EPICSANDBOX/CME+Globex+Matching+Algorithm+Steps)  <br>

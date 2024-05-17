#ifndef TEST_H
#define TEST_H
#include <iostream>
#include <fstream>
#include <string>

class Test
{
private:
public:
    Test();
    int readFile(std::string file);
};


#endif
#ifndef TEST_H
#define TEST_H
#include <iostream>
#include <fstream>
#include <string>

class Test
{
private:
public:
    int readFile(std::string_view file);
    void printFile();
};


#endif
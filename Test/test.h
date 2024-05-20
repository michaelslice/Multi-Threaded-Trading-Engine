#ifndef TEST_H
#define TEST_H
#include <iostream>
#include <fstream>
#include <string>

class Test
{
private:
public:

    int readFile(const std::string& file);
    void printFile();
};


#endif
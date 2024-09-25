#ifndef A_DS_STATION_H
#define A_DS_STATION_H

#include "stack.h"
#include <string>
#include <iostream>


class SortStation {
public:
    std::string getStr();

    int priority(char c);

    std::string toRPN(std::string &inputStr);
};


#endif

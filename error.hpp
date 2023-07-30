#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <string>
#include "common.hpp"

bool hadError = false;

//ERROR HANDLING
void error(int line, std::string message) {
    report(line, "", message);
}

void report(int line, std::string where, std::string message) {
    std::cout<<"[line "<<line<<"] Error"<<where<<": "<<message;
    hadError = true;
}

#endif
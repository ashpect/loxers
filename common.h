#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <string>

//ensure that there is only one instance of the hadError variable shared
//across multiple source files. 
extern bool hadError = false; // Declaration of hadError as extern

// ERROR HANDLING
void error(int line, std::string message);
void report(int line, std::string where, std::string message);

#endif
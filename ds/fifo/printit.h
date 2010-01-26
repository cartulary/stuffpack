#ifndef PRINTIT_H
#define PRINTIT_H
#include <iostream>
struct Printit
{
    void operator() (int i);
} doprint;
#endif
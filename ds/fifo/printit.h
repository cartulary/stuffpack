#ifndef PRINTIT_H
#define PRINTIT_H
#include <iostream>
template <class T> struct Printit
{
    void operator() (T i);
};
#endif

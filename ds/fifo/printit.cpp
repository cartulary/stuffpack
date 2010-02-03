#include <iostream>
#include "printit.h"
template <class T> void Printit<T>::operator() (T i)
{
    std::cout << i <<' ';
}

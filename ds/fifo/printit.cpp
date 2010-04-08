#include <iostream>
#include "printit.h"
template <class T> void Printit<T>::operator() (const T i) const
{
    std::cout << i <<' ';
}

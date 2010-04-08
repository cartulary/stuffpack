#include <iostream>
#include "printit.h"
template <class T> void Printit<T>::operator() (T const &i) const
{
    std::cout << i <<' ';
}

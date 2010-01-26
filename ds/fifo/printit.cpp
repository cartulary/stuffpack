#include <iostream>
#include "printit.h"
   void Printit::operator() (int i)
   {
       std::cout << i <<' ';
   }
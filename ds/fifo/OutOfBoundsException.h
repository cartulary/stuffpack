#ifndef OUT_OF_BOUNDS_EXCEPTION
#define OUT_OF_BOUNDS_EXCEPTION
#include <stdexcept>
class OutOfBoundsException : public std::range_error
{
	public:
		OutOfBoundsException();
};
#endif

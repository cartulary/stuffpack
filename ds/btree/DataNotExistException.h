#ifndef DATA_NOT_EXIST_EXCEPTION
#define DATA_NOT_EXIST_EXCEPTION

#include <stdexcept>
class DataNotExistException : public std::runtime_error
{
	public:
		DataNotExistException();
};
#endif

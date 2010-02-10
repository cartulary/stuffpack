#ifndef DUP_ENTRY_EXCEPTION
#define DUP_ENTRY_EXCEPTION
#include <stdexcept>
class DuplicateEntryException : public std::runtime_error
{
	public:
		DuplicateEntryException();
};
#endif

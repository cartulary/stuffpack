#include "DuplicateEntry.h"
DuplicateEntryException::DuplicateEntryException() : runtime_error("Entry already exists")
{}

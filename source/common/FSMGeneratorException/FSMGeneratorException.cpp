#include "FSMGeneratorException.h"

FSMGeneratorException::FSMGeneratorException() 
	: std::runtime_error("")
{
}

FSMGeneratorException::FSMGeneratorException(const char * pMessage)
	: std::runtime_error(pMessage)
{
}
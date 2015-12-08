#ifndef FSMGeneratorException_H
#define FSMGeneratorException_H

#include "stdexcept"

class FSMGeneratorException : public std::runtime_error
{
public:
	FSMGeneratorException();
};

#endif //FSMGeneratorException_H
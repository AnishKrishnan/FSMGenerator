#ifndef FSMGeneratorException_H
#define FSMGeneratorException_H

#include "stdexcept"

class FSMGeneratorException : public std::runtime_error
{
public:

	/**
	 * @brief Constructor for FSMGeneratorException
	 * @details Default constructor which results in empty message
	 */
	FSMGeneratorException();

	/**
	 * @brief Constructor for FSMGeneratorException with const char message
	 * 
	 * @param pMessage Exception message
	 */
	explicit FSMGeneratorException(const char * pMessage);
};

#endif //FSMGeneratorException_H
/** \addtogroup Common
 *  @{
 * Implemenation of the file reader interface
 */

#ifndef FileReader_H
#define FileReader_H

#include <string>
#include <fstream>
#include "IFileReader.h"
#include "FSMGeneratorException.h"

class FileReader : public IFileReader
{
private:
	std::ifstream _inStream;


public:

	/**
	 * @brief Constructor for File reader
	 * @details constructs the object and reads the contents of the file
	 * 
	 * @param pFile name of the file to open
	 */
	FileReader (const char * pFile);

	/**
	 * @brief Implementation of the IFileReader method
	 */
	virtual bool IsOpen (void);

	/**
	 * @brief Implementation of the IFileReader method
	 */
	virtual void Close (void);
};

#endif //FileReader_H
/** @}*/
/** \addtogroup Common
 *  @{
 * Simple implementation of the IFileWriter to dump all logs to the stdout
 */

#ifndef StdOutFileWriter_H
#define StdOutFileWriter_H

#include <string>
#include <iostream>
#include "IFileWriter.h"

class StdOutFileWriter : public IFileWriter
{

public:

	/**
	 * @brief Constructor for StdOutFileWriter
	 */
	StdOutFileWriter ();

	/**
	 * @brief Implements IFileWriter::Write
	 * 
	 * @param pData const string of data to write
	 */
	virtual void Write (const std::string & pData);

	/**
	 * @brief Implements IFileWriter::WriteLine
	 * 
	 * @param pData data to write
	 */
	virtual void WriteLine (const std::string & pData);

	/**
	 * @brief Implements IFileWriter::Flush
	 */
	virtual void Flush ();
};

#endif //StdOutFileWriter_H
/** @}*/
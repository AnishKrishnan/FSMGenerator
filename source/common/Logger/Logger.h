/** \addtogroup Common
 *  @{
 * Singleton class to provide logging capabilities for all modules
 */

#ifndef Logger_H
#define Logger_H

#include "stdexcept"
#include "ConfigManager.h"
#include "IFileWriter.h"
class Logger
{

private:
	static Logger * _instance;
	IFileWriter * _writer;
	bool _fullTrace;
	
	/**
	 * @brief Private constructor 
	 * @param pFileWriter file writer interface used to write logs
	 * @param pTrace boolean indicating whether full trace should be enabled
	 */
	Logger (IFileWriter * pFileWriter, bool pTrace = false);

public:

	/**
	 * @brief Returns the singleton instance of the Logger class
	 * 
	 * @param pFileWriter file writer interface used to write logs
	 * @param pTrace boolean indicating whether full trace should be enabled
	 * @return pointer to the logger instance
	 */
	static Logger * GetInstance (IFileWriter * pFileWriter, bool pTrace = false);
};

#endif //Logger_H
/** @}*/
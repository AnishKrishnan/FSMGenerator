/** \addtogroup Common
 *  @{
 * Singleton class to provide logging capabilities for all modules
 */

#ifndef Logger_H
#define Logger_H

#include "stdexcept"
#include "ConfigManager.h"

class Logger
{

private:
	static Logger * _instance;
	std::string _filePath;
	bool _fullTrace;
	
	/**
	 * @brief Private constructor 
	 * @param pFilePath string specifying the path to store the logs
	 * @param pTrace boolean indicating whether full trace should be enabled
	 */
	Logger (const char * pFilePath, bool pTrace = false);

public:

	/**
	 * @brief Returns the singleton instance of the Logger class
	 * 
	 * @param pFilePath string specifying the path to store the logs
	 * @param pTrace boolean indicating whether full trace should be enabled
	 * @return pointer to the logger instance
	 */
	static Logger * GetInstance (const char * pFilePath, bool pTrace);
};

#endif //Logger_H
/** @}*/
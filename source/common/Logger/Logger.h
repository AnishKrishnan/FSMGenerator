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
	ConfigManager * _configManager;
	
	/**
	 * @brief Private constructor 
	 * @param pFile string specifying the config file to use
	 */
	explicit Logger (ConfigManager * pConfigManager);

public:

	/**
	 * @brief Returns the singleton instance of the Logger class
	 * 
	 * @param pConfigManager pointer to the config manager object
	 * @return pointer to the logger instance
	 */
	static Logger * GetInstance (ConfigManager * pConfigManager);
};

#endif //Logger_H
/** @}*/
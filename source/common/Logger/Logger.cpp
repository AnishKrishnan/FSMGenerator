#include "Logger.h"

// Initialising static instance pointer
Logger * Logger::_instance = NULL;

/** public methods **/

Logger * Logger::GetInstance(ConfigManager * pConfigManager)
{
	if (pConfigManager == NULL)
	{
		throw std::runtime_error("Logger::GetInstance - pConfigManager is null");
	}

	if (Logger::_instance == NULL)
	{
		_instance = new Logger(pConfigManager);
	}

	return _instance;
}

/** private methodNs **/
Logger::Logger(ConfigManager * pConfigManager)
{
	if (pConfigManager == NULL)
	{
		throw std::runtime_error("Logger::ctor - pConfigManager is null");
	}

	_configManager = pConfigManager;
}
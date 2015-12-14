#include "Logger.h"

// Initialising static instance pointer
Logger * Logger::_instance = NULL;

/** public methods **/

Logger * Logger::GetInstance(const char * pFilePath, bool pTrace)
{
	if (pFilePath == NULL)
	{
		throw std::runtime_error("Logger::GetInstance - pConfigManager is null");
	}

	if (Logger::_instance == NULL)
	{
		_instance = new Logger(pFilePath, pTrace);
	}

	return _instance;
}

/** private methodNs **/
Logger::Logger(const char * pFilePath, bool pTrace)
{
	if (pFilePath == NULL)
	{
		throw std::runtime_error("Logger::ctor - pConfigManager is null");
	}

	_filePath = std::string(pFilePath);
	_fullTrace = pTrace;
}
#include "Logger.h"

// Initialising static instance pointer
Logger * Logger::_instance = NULL;

/** public methods **/

Logger * Logger::GetInstance(IFileWriter * pFileWriter, bool pTrace)
{
	if (pFileWriter == NULL)
	{
		throw std::runtime_error("Logger::GetInstance - pFileWriter is null");
	}

	if (Logger::_instance == NULL)
	{
		_instance = new Logger(pFileWriter, pTrace);
	}

	return _instance;
}

/** private methodNs **/
Logger::Logger(IFileWriter * pFileWriter, bool pTrace)
{
	if (pFileWriter == NULL)
	{
		throw std::runtime_error("Logger::ctor - pConfigManager is null");
	}

	_writer = pFileWriter;
	_fullTrace = pTrace;
}
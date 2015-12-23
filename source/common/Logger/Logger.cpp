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

void Logger::Log(LogLevel pLogLevel, const std::string& pLogData)
{
	if (pLogLevel < 0 || pLogLevel > LOGLEVEL_COUNT)
	{
		throw std::runtime_error("Logger::Log - pLogLevel is out of valid range");
	}

	std::string logLevelString;

	switch (pLogLevel)
	{
		case LOGLEVEL_INFO:
			logLevelString = "INFO";
			break;
		case LOGLEVEL_WARNING:
			logLevelString = "WARNING";
			break;
		case LOGLEVEL_ERROR:
			logLevelString = "ERROR";
			break;
		default:
			break;
	};

	_writer->WriteLine(std::string(logLevelString + ": " + pLogData));
}

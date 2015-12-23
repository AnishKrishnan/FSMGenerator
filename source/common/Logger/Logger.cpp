#include "Logger.h"

// Initialising static variables
Logger * Logger::_instance = NULL;
int Logger::MAX_LOG_BUFFER_SIZE = 1024;
int Logger::MAX_LOG_SIZE = 1000;

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

void Logger::Log(LogLevel pLogLevel, const char * pLogFormat, ...)
{
	if (pLogFormat == NULL)
	{
		throw std::runtime_error("Logger::Log - pLogFormat is null");
	}

	if (pLogLevel < 0 || pLogLevel > LOGLEVEL_COUNT)
	{
		throw std::runtime_error("Logger::Log - pLogLevel is out of valid range");
	}

	if (strlen(pLogFormat) > MAX_LOG_SIZE)
	{
		throw std::runtime_error("Logger::Log - pLogFormat is too long");
	}

	//get variadic data
	va_list args;
	va_start(args, pLogFormat);

	char buffer[MAX_LOG_SIZE];

	vsprintf(buffer, pLogFormat, args);

	this->Log(pLogLevel, std::string(buffer));

	va_end(args);
}

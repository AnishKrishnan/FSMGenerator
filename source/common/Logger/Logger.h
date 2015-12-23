/** \addtogroup Common
 *  @{
 * Singleton class to provide logging capabilities for all modules
 */

#ifndef Logger_H
#define Logger_H

#include "stdexcept"
#include "ConfigManager.h"
#include "IFileWriter.h"
#include "string.h"
#include "stdarg.h"
typedef enum
{
	LOGLEVEL_ERROR,
	LOGLEVEL_WARNING,
	LOGLEVEL_INFO,
	LOGLEVEL_COUNT

} LogLevel;

class Logger
{

private:
	static Logger * _instance;
	IFileWriter * _writer;
	bool _fullTrace;
	static int MAX_LOG_BUFFER_SIZE;
	/**
	 * @brief Private constructor 
	 * @param pFileWriter file writer interface used to write logs
	 * @param pTrace boolean indicating whether full trace should be enabled
	 */
	Logger (IFileWriter * pFileWriter, bool pTrace = false);

public:

	/**
	 * Max size of the log string 
	 */
	static int MAX_LOG_SIZE;

	/**
	 * @brief Returns the singleton instance of the Logger class
	 * 
	 * @param pFileWriter file writer interface used to write logs
	 * @param pTrace boolean indicating whether full trace should be enabled
	 * @return pointer to the logger instance
	 */
	static Logger * GetInstance (IFileWriter * pFileWriter, bool pTrace = false);

	/**
	 * @brief Writes the log data to file with the given log level
	 * 
	 * @param pLogLevel severity level of the log
	 * @param pLogData data to log
	 */
	void Log (LogLevel pLogLevel, const std::string& pLogData);

	/**
	 * @brief Writes teh log data to file given the log level and formatted string
	 * @details uses standard sprintf string formats
	 * 
	 * @param pLogLevel severity level of the log
	 * @param pLogFormat string format to use
	 */
	void Log (LogLevel pLogLevel, const char * pLogFormat, ...);
};

#endif //Logger_H
/** @}*/
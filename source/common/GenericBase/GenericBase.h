/** \addtogroup Common
 *  @{
 * Custom base class to be used for all other classes
 */

#ifndef GenericBase_H
#define GenericBase_H

#include "ConfigManager.h"
#include "Logger.h"
#include "StdOutFileWriter.h"

class GenericBase
{
private:
	Logger * _logger;
	StdOutFileWriter _output;
	ConfigManager * _configManager;

public:

	GenericBase ();
	
};

#endif //GenericBase_H
/** @}*/
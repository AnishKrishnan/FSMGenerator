/** \addtogroup Common
 *  @{
 * Abstraction layer to provide an interface into the configuration file(s) of the program
 */

#ifndef ConfigManager_H
#define ConfigManager_H

#include "stddef.h"

class ConfigManager
{

private:
	static ConfigManager * _instance;

	/**
	 * @brief Private constructor 
	 * @details [long description]
	 */
	ConfigManager ();
public:

	/**
	 * @brief Returns the singleton instancce of the config manager
	 */
	static ConfigManager * GetInstance ();

};

#endif //ConfigManager_H
/** @}*/
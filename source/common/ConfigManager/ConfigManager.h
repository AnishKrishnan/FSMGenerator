/** \addtogroup Common
 *  @{
 * Abstraction layer to provide an interface into the configuration file(s) of the program
 */

#ifndef ConfigManager_H
#define ConfigManager_H

#include "stddef.h"
#include "stdexcept"
#include "string"
#include "sstream"
#include "fstream"
#include "rapidxml.hpp"

class ConfigManager
{

private:
	static ConfigManager * _instance;
	rapidxml::xml_document<> _doc;
	std::string _configText;

	/**
	 * @brief Private constructor 
	 * @param pFile string specifying the config file to use
	 */
	ConfigManager (const char * pFile);
public:

	/**
	 * @brief Returns the singleton instancce of the config manager
	 * @param pFile string specifying the config file to use
	 * 
	 * @return pointer to the instance of the config manager
	 */
	static ConfigManager * GetInstance (const char * pFile);

};

#endif //ConfigManager_H
/** @}*/
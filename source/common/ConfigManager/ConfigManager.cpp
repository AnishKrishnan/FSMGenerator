#include "ConfigManager.h"

// Initialising static instance pointer
ConfigManager * ConfigManager::_instance = NULL;

/** public methods **/

ConfigManager * ConfigManager::GetInstance()
{
	if (ConfigManager::_instance == NULL)
	{
		_instance = new ConfigManager();
	}

	return _instance;
}

/** private methods **/
ConfigManager::ConfigManager()
{
}
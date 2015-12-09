#include "ConfigManager.h"

// Initialising static instance pointer
ConfigManager * ConfigManager::_instance = NULL;

/** public methods **/

ConfigManager * ConfigManager::GetInstance(const char * pFile)
{
	if (pFile == NULL)
	{
		throw std::runtime_error("ConfigManager::GetInstance - pFile is null");
	}

	if (ConfigManager::_instance == NULL)
	{
		_instance = new ConfigManager(pFile);
	}

	return _instance;
}

/** private methods **/
ConfigManager::ConfigManager(const char * pFile)
{
	if (pFile == NULL)
	{
		throw std::runtime_error("ConfigManager::ctor - pFile is null");
	}

	std::stringstream buffer;
	
	std::ifstream file(pFile);
	buffer << file.rdbuf();
	file.close();

	_configText = std::string(buffer.str());

	_doc.parse<0>(&_configText[0]);
}
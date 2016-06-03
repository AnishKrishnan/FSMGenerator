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

/** private methodNs **/
ConfigManager::ConfigManager(const char * pFile)
{
	if (pFile == NULL)
	{
		throw std::runtime_error("ConfigManager::ctor - pFile is null");
	}

	std::stringstream buffer;
	
	std::ifstream file(pFile);
	if (!file.is_open())
	{
		throw std::runtime_error("Could not open the file provided");
	}

	buffer << file.rdbuf();
	file.close();

	_configText = std::string(buffer.str());

	_doc.parse<0>(&_configText[0]);

	_root = _doc.first_node();
	if (_root == NULL)
	{
		throw std::runtime_error("config file does not contain a root node");
	}
}

std::string ConfigManager::GetConfigValue(const char * pConfigItemName)
{
	if (pConfigItemName == NULL)
	{
		throw std::runtime_error("ConfigManager::GetConfigValue - pConfigItemName is null");
	}


	rapidxml::xml_node<> * node = _root->first_node("configGroup");

	if (node == NULL)
	{
		throw std::runtime_error("config file must have at least one configGroup tag");
	}

	rapidxml::xml_node<> * desiredNode = NULL;
	do
	{
		desiredNode = node->first_node(pConfigItemName);
		if (desiredNode == NULL)
		{
			continue;
		}
		
		return desiredNode->value();
	}
	while((node = node->next_sibling()));

	throw std::runtime_error("could not find a config item with the provided tag name");
}

int ConfigManager::GetConfigValueAsInt(const char * pConfigItemName)
{
	if (pConfigItemName == NULL)
	{
		throw std::runtime_error("ConfigManager::GetConfigValueAsInt - pConfigItemName is null");
	}

	std::string configValue = this->GetConfigValue(pConfigItemName);

	return atoi(configValue.c_str());
}

void ConfigManager::Delete(void)
{
	delete _instance;
	_instance = NULL;
}
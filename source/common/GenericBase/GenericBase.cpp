#include "GenericBase.h"

GenericBase::GenericBase (const char * pConfigFile)
{
	if (pConfigFile == NULL)
	{
		throw std::runtime_error("GenericBase::ctor - pConfigFile is null");
	}

	_configManager = ConfigManager::GetInstance(pConfigFile);

	if (_configManager == NULL)
	{
		throw std::runtime_error("Could not instantiate config manager instance");
	}

	_logger = Logger::GetInstance(&_output, true);

	if (_logger == NULL)
	{
		throw std::runtime_error("Could not instantiate logger instance");
	}
}

GenericBase::~GenericBase()
{
	_logger->Delete();
	_configManager->Delete();
}
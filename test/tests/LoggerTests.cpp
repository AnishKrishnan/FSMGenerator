#include "ConfigManager.h"
#include "Logger.h"
#include <gtest/gtest.h>
#include "unistd.h"
#include "iostream"

class LoggerTests : public::testing::Test
{
public:
	ConfigManager * configManager;

	Logger * logger;

	LoggerTests()
	{
	}

	void SetUp()
	{
		configManager = ConfigManager::GetInstance("../data/ConfigManagerTestData/testConfig.config");
		logger = Logger::GetInstance(configManager);
	}

	void TearDown()
	{
	}

	~LoggerTests()
	{
	}
};

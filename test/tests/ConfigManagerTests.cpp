#include "ConfigManager.h"
#include <gtest/gtest.h>
#include "unistd.h"
#include "iostream"

class ConfigManagerTests : public::testing::Test
{
public:
	ConfigManager * configManager;

	ConfigManagerTests()
	{
	}

	void SetUp()
	{
		configManager = ConfigManager::GetInstance("../data/ConfigManagerTestData/testConfig.config");
	}

	void TearDown()
	{
		configManager->Delete();
	}

	~ConfigManagerTests()
	{
	}
};

TEST_F(ConfigManagerTests, GetItemSimple)
{
	std::string expectedData("value1");

	std::string actualData = configManager->GetConfigValue("configItem1");

	EXPECT_EQ(0, expectedData.compare(actualData));
}

TEST_F(ConfigManagerTests, GetItemSimpleIncorrectKey)
{
	bool exceptionThrown = false;

	try
	{
		(void)configManager->GetConfigValue("abcdefg");
	}
	catch(const std::runtime_error& err)
	{
		exceptionThrown = true;
	}

	EXPECT_EQ(true, exceptionThrown);
}

TEST_F(ConfigManagerTests, GetItemSimpleNullKey)
{
	bool exceptionThrown = false;

	try
	{
		(void)configManager->GetConfigValue(NULL);
	}
	catch(const std::runtime_error& err)
	{
		exceptionThrown = true;
	}

	EXPECT_EQ(true, exceptionThrown);
}

TEST_F(ConfigManagerTests, GetItemAsInt)
{
	int expectedData = 42;

	int actualData = configManager->GetConfigValueAsInt("configItem2");

	EXPECT_EQ(expectedData, actualData);
}
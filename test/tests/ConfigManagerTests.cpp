#include "ConfigManager.h"
#include <gtest/gtest.h>

class ConfigManagerTests : public::testing::Test
{
public:
	ConfigManager * configManager;

	ConfigManagerTests()
	{
		configManager = ConfigManager::GetInstance("../data/ConfigManagerTestsData/testConfig.config");
	}

	void SetUp()
	{
	}

	void TearDown()
	{
	}

	~ConfigManagerTests()
	{
	}
};

TEST_F(ConfigManagerTests, random)
{
	EXPECT_EQ(1,1);
}
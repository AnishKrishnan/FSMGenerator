#include <gtest/gtest.h>

class RandomTests : public::testing::Test 
{
public:
	RandomTests()
	{
	}

	void SetUp()
	{
	}

	void TearDown()
	{
	}

	~RandomTests()
	{
	}
};

TEST_F(RandomTests, FailTest)
{
	ASSERT_EQ(0,1);
}
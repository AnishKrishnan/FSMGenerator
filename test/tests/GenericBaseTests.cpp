#include "GenericBase.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "unistd.h"
#include "iostream"

class GenericBaseTests : public::testing::Test
{
public:
	class ExampleClass : public GenericBase
	{
	public:
		int testValue;
		ExampleClass () : GenericBase()
		{
			testValue = 1;
		}
	};

	ExampleClass * exampleClass;
	
	GenericBaseTests()
	{
	};

	void SetUp(void)
	{
		exampleClass = NULL;
	}

	void TearDown(void)
	{
	}

	~GenericBaseTests()
	{
	}

};

TEST_F(GenericBaseTests, ConstructorTests)
{
	exampleClass = new ExampleClass();

	EXPECT_EQ(1, exampleClass->testValue);
}
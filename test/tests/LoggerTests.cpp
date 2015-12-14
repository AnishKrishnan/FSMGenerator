#include "Logger.h"
#include <gtest/gtest.h>
#include "unistd.h"
#include "iostream"

class LoggerTests : public::testing::Test
{
public:

	Logger * logger;

	LoggerTests()
	{
	}

	void SetUp()
	{
		logger = Logger::GetInstance("../logs/", true);
	}

	void TearDown()
	{
	}

	~LoggerTests()
	{
	}
};

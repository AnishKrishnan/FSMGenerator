#include "Logger.h"
#include "MockFileWriter.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "unistd.h"
#include "iostream"

class LoggerTests : public::testing::Test
{
public:

	Logger * logger;
	MockFileWriter mockFileWriter;
	LoggerTests()
	{
	}

	void SetUp()
	{
		logger = Logger::GetInstance(&mockFileWriter, true);
	}

	void TearDown()
	{
	}

	~LoggerTests()
	{
	}
};

TEST_F(LoggerTests, LogInfoTest)
{
	EXPECT_CALL(mockFileWriter, WriteLine(std::string("INFO: Test String")))
		.Times(1);
	logger->Log(LOGLEVEL_INFO, "Test String");
}

TEST_F(LoggerTests, LogWarningTest)
{
	EXPECT_CALL(mockFileWriter, WriteLine(std::string("WARNING: Test String")))
		.Times(1);
	logger->Log(LOGLEVEL_WARNING, "Test String");
}
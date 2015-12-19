#include "Logger.h"
#include "MockFileWriter.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "unistd.h"
#include "iostream"

using ::testing::tuple;

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

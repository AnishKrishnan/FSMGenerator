#include "FileReader.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "unistd.h"
#include "iostream"

class FileReaderTests : public::testing::Test
{
public:
	
	FileReader * fileReader;

	FileReaderTests()
	{
	}

	void SetUp(void)
	{
		fileReader = new FileReader("../data/FileReaderTestData/simpleTestData.txt");
	}

	void TearDown(void)
	{
		delete fileReader;
	}

	~FileReaderTests()
	{
	}

};

TEST_F(FileReaderTests, FileOpenOnConstructor)
{
	EXPECT_EQ(true, fileReader->IsOpen());
}
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
		fileReader = NULL;
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
	fileReader = new FileReader("../data/FileReaderTestData/simpleTestData.txt");
	EXPECT_EQ(true, fileReader->IsOpen());
}
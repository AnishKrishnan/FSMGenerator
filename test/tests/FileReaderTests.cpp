#include "FileReader.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "unistd.h"
#include "iostream"
#include "FSMGeneratorException.h"
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

TEST_F(FileReaderTests, CheckFileNameIsNull)
{
	bool errorThrown = false;
	try
	{
		fileReader = new FileReader(NULL);
	}
	catch (const FSMGeneratorException & err)
	{
		errorThrown = true;
	}

	EXPECT_EQ(true, errorThrown);
}
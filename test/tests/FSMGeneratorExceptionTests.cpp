#include "FSMGeneratorException.h"
#include <gtest/gtest.h>

TEST(FSMGeneratorExceptionTests, CanBeCaught)
{
	bool exceptionCaught = false;		
	try
	{
		throw FSMGeneratorException();
	}
	catch (const FSMGeneratorException & err)
	{
		exceptionCaught = true;
	}
	
	ASSERT_EQ(true, exceptionCaught);
}

TEST(FSMGeneratorExceptionTests, CharConstErrorMessage)
{
	const char * testString = "Test String";
	try
	{
		throw FSMGeneratorException(testString);
	}
	catch (const FSMGeneratorException & err)
	{
		EXPECT_EQ(0, strcmp(testString, err.what()));
	}
}
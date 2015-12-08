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
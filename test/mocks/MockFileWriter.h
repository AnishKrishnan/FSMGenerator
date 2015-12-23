#ifndef MockFileWriter_H
#define MockFileWriter_H

#include "IFileWriter.h"
#include "gmock/gmock.h"

class MockFileWriter : public IFileWriter
{
public:
	 // MOCK_METHOD1(Write, void(const char * pData));

	 MOCK_METHOD1(Write, void(const std::string & pData));
	
	 // MOCK_METHOD1(WriteLine, void(const char * pData));
	
	 MOCK_METHOD1(WriteLine, void(const std::string & pData));

	 MOCK_METHOD0(Flush, void());
};

#endif //MockFileWriter_H
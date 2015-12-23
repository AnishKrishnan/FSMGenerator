#include "StdOutFileWriter.h"

StdOutFileWriter::StdOutFileWriter()
{
}

void StdOutFileWriter::Write(const std::string & pData)
{
	std::cout << pData;
}

void StdOutFileWriter::WriteLine(const std::string & pData)
{
	std::cout << pData << std::endl;
}

void StdOutFileWriter::Flush()
{
	std::cout.flush();
}
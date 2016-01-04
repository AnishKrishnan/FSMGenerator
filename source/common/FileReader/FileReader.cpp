#include "FileReader.h"

FileReader::FileReader(const char * pFile)
{
	if (pFile == NULL)
	{
		throw FSMGeneratorException("FileReader::ctor - pFile is null");
	}
	_inStream.open(pFile);

	if (!this->IsOpen())
	{
		throw FSMGeneratorException("File could not be opened");
	}
}

bool FileReader::IsOpen(void)
{
	return _inStream.is_open();
}


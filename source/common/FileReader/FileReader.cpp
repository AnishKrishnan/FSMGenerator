#include "FileReader.h"

FileReader::FileReader(const char * pFile)
{
	if (pFile == NULL)
	{
		throw FSMGeneratorException("FileReader::ctor - pFile is null");
	}
	_inStream.open(pFile);
}

bool FileReader::IsOpen(void)
{
	return _inStream.is_open();
}


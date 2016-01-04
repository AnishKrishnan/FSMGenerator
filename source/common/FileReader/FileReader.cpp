#include "FileReader.h"

FileReader::FileReader(const char * pFile)
{
	_inStream.open(pFile);
}

bool FileReader::IsOpen(void)
{
	return _inStream.is_open();
}


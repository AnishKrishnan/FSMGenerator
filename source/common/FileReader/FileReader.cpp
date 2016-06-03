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

void FileReader::Close(void)
{
	_inStream.close();
}

char * FileReader::GetAllData(void)
{
	//get size of the file
	_inStream.seekg(0, _inStream.end);
	int size = _inStream.tellg();
	_inStream.seekg(0, _inStream.beg);

	char * buffer = (char *) calloc(size, sizeof(char));

	//read data as block
	_inStream.read(buffer, size);

	return buffer;
}
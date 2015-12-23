/** \addtogroup Interfaces
 *  @{
 * interface for file writer class
 */
 
#ifndef IFileWriter_H
#define IFileWriter_H

class IFileWriter
{
public:
	virtual ~IFileWriter() {}
	/**
	 * @brief Write the provided data to the end of the file
	 * 
	 * @param pData const char string of data to write
	 */
	// virtual void Write (const char * pData)= 0;

	/**
	 * @brief Write the provided data to the end of the file
	 * 
	 * @param pData const string of data to write
	 */
	virtual void Write (const std::string & pData) = 0;

	/**
	 * @brief Writes the provided data to the end of the file followed by a new line
	 * 
	 * @param pData data to write
	 */
	// virtual void WriteLine (const char * pData) = 0;

	/**
	 * @brief Writes the provided data to the end of the file followed by a new line
	 * 
	 * @param pData data to write
	 */
	virtual void WriteLine (const std::string & pData) = 0;

	/**
	 * @brief Fluses the file buffer
	 */
	virtual void Flush () = 0;
};

#endif //IFileWriter_H

 /** @}*/
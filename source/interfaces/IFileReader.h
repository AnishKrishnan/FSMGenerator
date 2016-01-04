/** \addtogroup Interfaces
 *  @{
 * interface for file reader class
 */
 
#ifndef IFileReader_H
#define IFileReader_H

class IFileReader
{
public:
	virtual ~IFileReader() {}
	
/**
	 * @brief Determines if the file is open
	 * @return bool indicating if the file is open
	 */
	virtual bool IsOpen (void) = 0;

	/**
	 * @brief Closes the open file
	 */
	virtual void Close (void) = 0;

	/**
	 * @brief Returns a char buffer to the all the contents of the file
	 * 
	 * @return pointer to the data buffer
	 */
	virtual char * GetAllData (void) = 0;
};

#endif //IFileReader_H

 /** @}*/
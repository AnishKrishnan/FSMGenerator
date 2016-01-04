#set source locations
set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/source)
set(COMMON_DIR ${SOURCE_DIR}/common)

include(${COMMON_DIR}/GenericBase/GenericBase.cmake)
include(${COMMON_DIR}/Logger/Logger.cmake)
include(${COMMON_DIR}/ConfigManager/ConfigManager.cmake)
include(${COMMON_DIR}/FSMGeneratorException/FSMGeneratorException.cmake)
include(${COMMON_DIR}/StdOutFileWriter/StdOutFileWriter.cmake)
include(${COMMON_DIR}/FileReader/FileReader.cmake)

include(${SOURCE_DIR}/interfaces/interfaces.cmake)
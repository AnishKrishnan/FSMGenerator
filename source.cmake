#set source locations
set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/source)
set(COMMON_DIR ${SOURCE_DIR}/common)

include(${COMMON_DIR}/Logger/Logger.cmake)
include(${COMMON_DIR}/ConfigManager/ConfigManager.cmake)
include(${COMMON_DIR}/FSMGeneratorException/FSMGeneratorException.cmake)

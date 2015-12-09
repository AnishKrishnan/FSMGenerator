##### Files #####

# Headers
include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${CMAKE_CURRENT_LIST_DIR}/rapidxml)

# Source files
FILE(GLOB SRC ${CMAKE_CURRENT_LIST_DIR}/*.cpp ${CMAKE_CURRENT_LIST_DIR}/rapidxml/*.hpp)

##### Outputs #####

# Create emlib library
add_library(ConfigManager ${SRC})
set(LIBS ${LIBS} ConfigManager)
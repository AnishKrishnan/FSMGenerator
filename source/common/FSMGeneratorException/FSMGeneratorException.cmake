##### Files #####

# Headers
include_directories(${CMAKE_CURRENT_LIST_DIR})

# Source files
FILE(GLOB SOURCES ${CMAKE_CURRENT_LIST_DIR}/*.cpp)

##### Outputs #####

# Create emlib library
add_library(FSMGeneratorException ${SOURCES})
set(LIBS ${LIBS} FSMGeneratorException)
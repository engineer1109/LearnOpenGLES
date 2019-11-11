cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(LearnOpenGLES)

include(${PROJECT_SOURCE_DIR}/cmake/GCC.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/FindOpenGLES.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/FindOpenMP.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/Platform.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/Config.cmake)

if(WIN32)
    SET(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/)
    SET(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/)
else()
    SET(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin/)
    SET(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin/)
endif()

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/openglesbase)
link_directories(${PROJECT_SOURCE_DIR}/lib)

if(UNIX)
    include_directories(/usr/local/include)
    link_directories(/usr/local/lib)
endif()

add_subdirectory(src)
add_subdirectory(examples)

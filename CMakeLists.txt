cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(LearnOpenGLES)

option(USE_GLFW "Use OpenGL" OFF)

if (USE_GLFW)
    add_definitions(-DUSE_OPENGL)
endif()
if (NOT USE_GLFW)
    add_definitions(-DUSE_OPENGLES)
endif()

if (UNIX)
set(GL_LIBRARIES GL)
endif()

include(${PROJECT_SOURCE_DIR}/cmake/Config.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/GCC.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/FindOpenGLES.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/FindOpenMP.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/FindQt.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/Platform.cmake)

if(WIN32)
    SET(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/)
    SET(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/)
else()
    SET(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin/)
    SET(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin/)
endif()

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/openglesbase)
include_directories(${PROJECT_SOURCE_DIR}/include/qtopengleswindow)
link_directories(${PROJECT_SOURCE_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}/third_party/gli)
include_directories(${PROJECT_SOURCE_DIR}/third_party/glm)
include_directories(${PROJECT_SOURCE_DIR}/third_party/imgui)
include_directories(${PROJECT_SOURCE_DIR}/third_party/stb_image/include)

if(UNIX)
    include_directories(/usr/local/include)
    link_directories(/usr/local/lib)
endif()

add_definitions(-DPROJECT_ABSOLUTE_PATH="${PROJECT_SOURCE_DIR}")

add_subdirectory(src)
add_subdirectory(examples)

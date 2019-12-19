cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
SET(LIB_NAME qtopengleswindow)

add_definitions(-DQTOPENGLESWINDOW_EXPORT_API)

set(CMAKE_INCLUDE_CURRENT_DIR True)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

FILE(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*)
FILE(GLOB HEAD_FILES ${PROJECT_SOURCE_DIR}/include/qtopengleswindow/*)

include_directories(${PROJECT_SOURCE_DIR}/include/qtopengleswindow)

add_library(${LIB_NAME} SHARED ${SRC_FILES} ${HEAD_FILES} ${STB_IMAGE} ${IMGUI})
target_link_libraries(${LIB_NAME} Qt5::Widgets Qt5::Core opengles_basicengine)

INSTALL(TARGETS ${LIB_NAME} DESTINATION "${PROJECT_SOURCE_DIR}/bin")

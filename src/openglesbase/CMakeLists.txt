cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
SET(LIB_NAME opengles_basicengine)

add_definitions(-DOPENGLESBASE_EXPORT_API)
add_definitions(-DSTBI_NO_DDS)
add_definitions(-DSTB_IMAGE_EXPORT_API)

FILE(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*)
FILE(GLOB HEAD_FILES ${PROJECT_SOURCE_DIR}/include/openglesbase/*)
#FILE(GLOB_RECURSE IMGUI ${CMAKE_SOURCE_DIR}/third_party/imgui/*)

FILE(GLOB STB_IMAGE ${PROJECT_SOURCE_DIR}/third_party/stb_image/src/*
                     ${PROJECT_SOURCE_DIR}/third_party/stb_image/include/*)

FILE(GLOB_RECURSE IMGUI ${CMAKE_SOURCE_DIR}/third_party/imgui/*)

add_library(${LIB_NAME} SHARED ${SRC_FILES} ${HEAD_FILES} ${STB_IMAGE} ${IMGUI})
target_link_libraries(${LIB_NAME} ${OPENGLES3_LIBRARY} ${EGL_LIBRARY} ${NativeWindow})

INSTALL(TARGETS ${LIB_NAME} DESTINATION "${PROJECT_SOURCE_DIR}/bin")

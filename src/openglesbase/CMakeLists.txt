cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
SET(LIB_NAME opengles_basicengine)

add_definitions(-DOPENGLESBASE_EXPORT_API)
add_definitions(-DSTBI_NO_DDS)
add_definitions(-DSTB_IMAGE_EXPORT_API)
# add_definitions(-DIMGUI_IMPL_OPENGL_ES3)
# add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_CUSTOM)

FILE(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*)
FILE(GLOB HEAD_FILES ${PROJECT_SOURCE_DIR}/include/openglesbase/*)
#FILE(GLOB_RECURSE IMGUI ${CMAKE_SOURCE_DIR}/third_party/imgui/*)

FILE(GLOB STB_IMAGE ${PROJECT_SOURCE_DIR}/third_party/stb_image/src/*
                     ${PROJECT_SOURCE_DIR}/third_party/stb_image/include/*)

if (USE_GLFW)                     
FILE(GLOB IMGUI ${CMAKE_SOURCE_DIR}/third_party/imgui/* 
${CMAKE_SOURCE_DIR}/third_party/imgui/imgui_widgets.cpp
${CMAKE_SOURCE_DIR}/third_party/imgui/imgui_impl_opengl3.cpp
${CMAKE_SOURCE_DIR}/third_party/imgui/imgui_impl_glfw.cpp)
else()
FILE(GLOB IMGUI ${CMAKE_SOURCE_DIR}/third_party/imgui/* 
${CMAKE_SOURCE_DIR}/third_party/imgui/imgui_widgets.cpp
${CMAKE_SOURCE_DIR}/third_party/imgui/backends/imgui_impl_opengl3.cpp)
add_definitions(-DIMGUI_IMPL_OPENGL_ES3)
add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_CUSTOM)
endif()

add_library(${LIB_NAME} SHARED ${SRC_FILES} ${HEAD_FILES} ${STB_IMAGE} ${IMGUI})
#target_link_libraries(${LIB_NAME} ${OPENGLES3_LIBRARY} ${EGL_LIBRARY} ${NativeWindow} ${SYS_LIB})
if (USE_GLFW)
    target_link_libraries(${LIB_NAME} glfw GLEW ${SYS_LIB})
else()
    target_link_libraries(${LIB_NAME} ${OPENGLES3_LIBRARY} ${EGL_LIBRARY} ${NativeWindow} ${SYS_LIB})
endif()

INSTALL(TARGETS ${LIB_NAME} DESTINATION "${PROJECT_SOURCE_DIR}/bin")

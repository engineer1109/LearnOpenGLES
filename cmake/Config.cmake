if(UNIX)
    option(USE_XCB "X11 xcb" ON)
endif()
option(GIT_ThirdParty "git submodule the thirdparty" ON)
option(USE_OpenMP "Use CPU Multithread OpenMP" ON)
option(BUILD_BASE "Build libopenglesbase.so" ON)
option(BUILD_SimpleExamples "Build SimpleExamples" ON)


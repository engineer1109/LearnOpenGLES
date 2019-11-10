find_library( OPENGLES3_LIBRARY GLESv2 "OpenGL ES v3.0 library")
find_library( EGL_LIBRARY EGL "EGL 1.4 library" )
message("Find OpenGLES ${OPENGLES3_LIBRARY}")
message("Find EGL ${EGL_LIBRARY}")

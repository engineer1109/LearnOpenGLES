# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_definitions(-DGLM_FORCE_RADIANS)
add_definitions(-DGLM_FORCE_DEPTH_ZERO_TO_ONE)
add_definitions(-DSTBI_NO_DDS)

include_directories(
        ${PROJECT_SOURCE_DIR}/base
        ${PROJECT_SOURCE_DIR}/common
        ${PROJECT_SOURCE_DIR}/engine
        ${PROJECT_SOURCE_DIR}/utils
        ${PROJECT_SOURCE_DIR}/third_party/glm
        ${PROJECT_SOURCE_DIR}/third_party/stb_image/include
)


add_library( # Sets the name of the library.
        OpenGLESBase

        # Sets the library as a shared library.
        SHARED
        # Provides a relative path to your source file(s).
        base/OpenGLESBase.cxx

        engine/ThirdPersonEngine.cxx
        )

add_library(
        stb_image
        SHARED
        ${PROJECT_SOURCE_DIR}/third_party/stb_image/src/stb_image_aug.c
)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        OpenGLESBase

        # Links the target library to the log library
        # included in the NDK.
        stb_image
        ${log-lib}
        EGL
        GLESv3
        android
        )

# Examples

include_directories(
        examples/Triangle
        examples/Texture2DCube
        examples/PhongLighting
        examples/VolumeCloud
        ./template
        ./template/mesh
        ./template/texture
        ./template/uniform
        ./template/camera
        ./template/material
)

add_library(
        BaseRender

        SHARED

        native-lib.cpp

        template/uniform/OpenGLESUniform.cxx
        template/uniform/UniformCamera.cxx
        template/mesh/OpenGLESMeshObject.cxx
        template/texture/OpenGLESTexture.cxx
        template/texture/OpenGLESTexture2D.cxx
        template/texture/OpenGLESTexture3D.cxx
        template/mesh/OpenGLESCube.cxx
        template/material/OpenGLESMaterial.cxx

        examples/Triangle/Triangle.cpp
        examples/Triangle/myobjects/TriangleObject.cpp

        examples/Texture2DCube/Texture2DCube.cpp

        examples/PhongLighting/PhongLighting.cpp
        examples/VolumeCloud/VolumeCloud.cxx

)

target_link_libraries(
        BaseRender
        OpenGLESBase
)

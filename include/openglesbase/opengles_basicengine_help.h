#ifndef OPENGLES_BASICENGINE_HELP_H
#define OPENGLES_BASICENGINE_HELP_H
// C++17 include
#include <iostream>
#include <algorithm>
#include <memory>
#include <thread>
#include <numeric>
#include <assert.h>
#include <vector>
#include <random>
#include <ctime>
#include <ciso646>
#if defined(__GNUC__) && __GNUC__ > 7
    #include <filesystem>
    using fs=std::filesystem::path;
#else
    #include <experimental/filesystem>
    using fs=std::experimental::filesystem::path;
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//GLM

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//OpenGLES
#include <GLES3/gl3.h>

#define BEGIN_NAMESPACE(n) namespace n {

#define END_NAMESPACE(n) }

#endif // OPENGLES_BASICENGINE_HELP_H

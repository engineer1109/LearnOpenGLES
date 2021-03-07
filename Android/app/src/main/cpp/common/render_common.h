//
// Created by wjl on 20-9-6.
//

#ifndef OPENGLESTEST_RENDER_COMMON_H
#define OPENGLESTEST_RENDER_COMMON_H

//Base
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <array>
#include <numeric>
#include <string>
#include <memory>
#include <algorithm>
#include <map>

//Unix
#include <unistd.h>

//GL
#include <GLES3/gl3.h>
#include <EGL/egl.h>

//Android
#include <android/log.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <android/asset_manager_jni.h>

//Define

#define interface class

#define BEGIN_NAMESPACE(n) namespace n {

#define END_NAMESPACE(n) }

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "opengles", __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, "opengles", __VA_ARGS__))
#define LOGD(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, "opengles", __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, "opengles", __VA_ARGS__))

#define DELETE_PTR(x) if(x) { delete x; x = nullptr; }

#endif //OPENGLESTEST_RENDER_COMMON_H

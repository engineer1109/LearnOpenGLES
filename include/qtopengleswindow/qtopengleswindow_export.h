#ifndef QTOPENGLESWINDOW_EXPORT_H
#define QTOPENGLESWINDOW_EXPORT_H

#ifdef QTOPENGLESWINDOW_EXPORT_API
    #ifdef WIN32
    #define QTOPENGLESWINDOW_EXPORT __declspec(dllexport)
    #else
    #define QTOPENGLESWINDOW_EXPORT
    #endif
#else
#define QTOPENGLESWINDOW_EXPORT
#endif

#endif

/*--------------------------------------------------------------
 * do not modify this file, which is generate by cmake
 *-------------------------------------------------------------*/
#ifndef OBJECT_EXPORT_OPENGL_H
#define OBJECT_EXPORT_OPENGL_H

#ifdef OBJECT_EXPORTS
    #define OBJECT_API __declspec(dllexport)
#else
    #define OBJECT_API __declspec(dllimport)
#endif

#endif //OBJECT_EXPORT_OPENGL_H

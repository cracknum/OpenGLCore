/*--------------------------------------------------------------
 * do not modify this file, which is generate by cmake
 *-------------------------------------------------------------*/
#ifndef CONTEXT_EXPORT_OPENGL_H
#define CONTEXT_EXPORT_OPENGL_H

#ifdef CONTEXT_EXPORTS
    #define CONTEXT_API __declspec(dllexport)
#else
    #define CONTEXT_API __declspec(dllimport)
#endif

#endif //CONTEXT_EXPORT_OPENGL_H

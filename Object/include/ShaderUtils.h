#ifndef SHADER_UTILS_H
#define SHADER_UTILS_H
#include <string>
#include "ObjectExport.h"

namespace ShaderUtils
{
OBJECT_API std::string loadShaderSource(const char* path);

};
#endif // SHADER_UTILS_H
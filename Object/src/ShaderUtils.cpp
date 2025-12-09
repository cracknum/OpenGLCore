#include "ShaderUtils.h"
#include <fstream>
#include <sstream>

namespace ShaderUtils
{
 std::string loadShaderSource(const char* path)
{
	std::ifstream ifs(path);
  if (!ifs.is_open())
  {
    std::ostringstream oss;
    oss << "file not exists: " << path;
    throw std::runtime_error(oss.str());
  }
  
  return std::string(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>());
}
}
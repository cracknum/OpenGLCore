#ifndef SHADER_PROGRAM_MANAGER_OPENGL_H
#define SHADER_PROGRAM_MANAGER_OPENGL_H
#include "ObjectExport.h"
#include "ShaderProgram.h"
#include "unordered_map"
#include <memory>
#include <vector>

class OBJECT_API ShaderProgramManager final
{
public:
  explicit ShaderProgramManager();
  ~ShaderProgramManager();
  using ShaderProgramPointer = std::shared_ptr<ShaderProgram>;

  /**
   * @brief 获取shader程序
   */
  ShaderProgramPointer getShaderProgram(const std::unordered_map<GLenum, std::string>& shaderSources);

private:
  static size_t hash(const std::unordered_map<GLenum, std::string>& shaderSources);
  static void hash_combine(size_t& seed, const size_t& v);
private:
  struct Impl;
  std::unique_ptr<Impl> m_Impl;
};
#endif // SHADER_PROGRAM_MANAGER_OPENGL_H
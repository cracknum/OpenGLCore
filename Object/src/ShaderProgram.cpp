#include "ShaderProgram.h"

#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <spdlog/spdlog.h>
#include <sstream>
#include "GLFunctions.h"

struct ShaderProgram::Impl
{
  GLuint m_Program;
  std::vector<GLuint> m_Shaders;

  Impl()
    : m_Program(0)
  {
  }
};

void ShaderProgram::deleteShaders() const
{
  for (const auto& shaderId : m_Impl->m_Shaders)
  {
    GL::DeleteShader(shaderId);
  }

  m_Impl->m_Shaders.clear();
}
void ShaderProgram::deleteProgram() const
{
  deleteShaders();
  GL::DeleteProgram(m_Impl->m_Program);
  m_Impl->m_Program = 0;
}
ShaderProgram::ShaderProgram(const std::unordered_map<GLenum, std::string>& shaderSources)
{
  m_Impl = std::make_unique<Impl>();
  m_Impl->m_Program = GL::CreateProgram();
  std::ostringstream oss;

  for (const auto& pair : shaderSources)
  {
    oss.str("");
    try
    {
      if (pair.second.empty())
      {
        continue;
      }

      GLuint shader = GL::CreateShader(pair.first);
      const auto sourceStr = pair.second.c_str();
      GLint sourceLength = pair.second.length();
      GL::ShaderSource(shader, 1, &sourceStr, &sourceLength);
      GL::CompileShader(shader);
      GLint compileStatus = 0;
      GL::GetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);
      if (compileStatus != GL_TRUE)
      {
        GLint logLength = 0;
        GL::GetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
        if (logLength > 1)
        {
          std::vector<GLchar> log;
          GL::GetShaderInfoLog(shader, logLength, nullptr, log.data());
          oss << "compile error: " << log.data();
        }
        else
        {
          oss << "unknown shader compile error" << pair.second;
        }
        SPDLOG_ERROR(oss.str());
        throw std::runtime_error(oss.str());
      }

      oss << "load shader: " << pair.second;
      GL::AttachShader(m_Impl->m_Program, shader);
      m_Impl->m_Shaders.push_back(shader);
    }
    catch (std::exception& e)
    {
      oss << e.what() << std::endl;
      deleteProgram();
    }

    SPDLOG_DEBUG(oss.str());
  }

  GL::LinkProgram(m_Impl->m_Program);
  GLint linkStatus;
  GL::GetProgramiv(m_Impl->m_Program, GL_LINK_STATUS, &linkStatus);
  if (linkStatus == GL_FALSE)
  {
    GLsizei logLength;
    GL::GetProgramiv(m_Impl->m_Program, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 1)
    {
      std::vector<GLchar> log(logLength);
      GL::GetProgramInfoLog(m_Impl->m_Program, logLength, nullptr, log.data());
      deleteProgram();
      std::ostringstream logOss;
      logOss << "program link error: " << log.data();
      spdlog::error(logOss.str());
      throw std::runtime_error(logOss.str());
    }

    throw std::runtime_error("error unknown");
  }

  deleteShaders();
}
ShaderProgram::~ShaderProgram() {}
void ShaderProgram::use() const
{
  GL::UseProgram(m_Impl->m_Program);
}
void ShaderProgram::unuse() const
{
  GL::UseProgram(0);
}
bool ShaderProgram::setMat4(const glm::mat4& mat4, const char* name) const
{
  const GLint location = GL::GetUniformLocation(m_Impl->m_Program, name);
  if (location == -1)
  {
    return false;
  }
  GL::UniformMatrix4fv(location, 1, false, glm::value_ptr(mat4));
  return true;
}
bool ShaderProgram::setInt1(int v, const char* name) const
{
  const GLint location = GL::GetUniformLocation(m_Impl->m_Program, name);
  if (location == -1)
  {
    return false;
  }
  GL::Uniform1i(location, v);
  return true;
}
bool ShaderProgram::setFloat1(float v, const char* name) const
{
  const GLint location = GL::GetUniformLocation(m_Impl->m_Program, name);
  if (location == -1)
  {
    return false;
  }
  GL::Uniform1f(location, v);
  return true;
}
bool ShaderProgram::setFloat3(float a, float b, float c, const char* name) const
{
  const GLint location = GL::GetUniformLocation(m_Impl->m_Program, name);
  if (location == -1)
  {
    return false;
  }
  GL::Uniform3f(location, a, b, c);

  return true;
}
bool ShaderProgram::setVec3(const glm::vec3& vec3, const char* name) const
{
  const GLint location = GL::GetUniformLocation(m_Impl->m_Program, name);
  if (location == -1)
  {
    return false;
  }
  GL::Uniform3f(location, vec3.x, vec3.y, vec3.z);

  return true;
}

bool ShaderProgram::setVec2(const glm::vec2& vec2, const char* name) const
{
  const GLint location = GL::GetUniformLocation(m_Impl->m_Program, name);
  if (location == -1)
  {
    return false;
  }
  GL::Uniform2f(location, vec2.x, vec2.y);

  return true;
}
bool ShaderProgram::setVec4(const glm::vec4& vec4, const char* name) const
{
  const GLint location = GL::GetUniformLocation(m_Impl->m_Program, name);
  if (location == -1)
  {
    return false;
  }
  GL::Uniform4f(location, vec4.x, vec4.y, vec4.z, vec4.w);

  return true;
}
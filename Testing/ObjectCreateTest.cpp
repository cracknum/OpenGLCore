#include "FrameBuffer.h"
#include "OpenGLContext.hpp"
#include "OpenGLWindow.h"
#include "ShaderProgram.h"
#include "ShaderProgramManager.h"
#include "ShaderUtils.h"
#include <gtest/gtest.h>
#include <memory>
#include <unordered_map>
#include "Vertices.h"
#include "VertexIndexBuffer.h"

class CoreTest : public ::testing::Test
{
protected:
  void SetUp() override
  {
    mWindow = std::make_unique<OpenGLWindow>();
    mWindow->init(100, 100, "title");
  }
  std::unique_ptr<OpenGLWindow> mWindow;
};

TEST_F(CoreTest, TestFramebufferCreate)
{
  auto frameBuffer = std::make_shared<FrameBuffer>(100, 100);
}

TEST_F(CoreTest, TestShaderProgramCreate)
{
  auto shaderProgramManager = std::make_unique<ShaderProgramManager>();
  std::unordered_map<GLenum, std::string> shaderSources;
  auto fragmentShaderSource =
    ShaderUtils::loadShaderSource("F:/Workspace/Projects/OpenGLCore/Testing/shader/line.frag");
  auto vertexShaderSource =
    ShaderUtils::loadShaderSource("F:/Workspace/Projects/OpenGLCore/Testing/shader/Line.vert");
  auto geometryShaderSource =
    ShaderUtils::loadShaderSource("F:/Workspace/Projects/OpenGLCore/Testing/shader/Line.geom");
  shaderSources[GL_VERTEX_SHADER] = vertexShaderSource;
  shaderSources[GL_GEOMETRY_SHADER] = geometryShaderSource;
  shaderSources[GL_FRAGMENT_SHADER] = fragmentShaderSource;
  auto shaderProgram = shaderProgramManager->getShaderProgram(shaderSources);

  EXPECT_EQ(shaderProgram != nullptr, true);
}

TEST_F(CoreTest, VerticeCreate)
{
  auto vertices = std::make_shared<Vertices>();
  // clang-format off
  vertices->m_Data = new GLfloat[32]
  {
    // point              // texture     // normal
    -1.0f, -1.0f, 0.0f,   0.0f, 0.0f,   0.0f, 0.0f, 1.0f,
     1.0f, -1.0f, 0.0f,   1.0f, 0.0f,   0.0f, 0.0f, 1.0f,
     1.0f,  1.0f, 0.0f,   1.0f, 1.0f,   0.0f, 0.0f, 1.0f,
    -1.0f,  1.0f, 0.0f,   0.0f, 1.0f,   0.0f, 0.0f, 1.0f
  };
  vertices->m_Indices = new GLuint[6]
  {
    0, 1, 3,
    1, 2, 3
  };
  // clang-format on

  vertices->m_DataSize = 32;
  vertices->m_PointAttribute.first = true;
  vertices->m_PointAttribute.second = 3;
  vertices->m_TextureAttribute.first = true;
  vertices->m_TextureAttribute.second = 2;
  vertices->m_NormalAttribute.first = true;
  vertices->m_NormalAttribute.second = 3;
  vertices->m_IndicesSize = 6;

  const auto vertexBuffer = std::make_shared<VertexIndexBuffer>();
  vertexBuffer->createBuffer(*vertices);
  vertexBuffer->draw(GL_TRIANGLES);
}
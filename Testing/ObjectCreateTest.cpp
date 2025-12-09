#include "FrameBuffer.h"
#include "OpenGLContext.hpp"
#include <gtest/gtest.h>
#include <memory>
#include "OpenGLWindow.h"
#include "ShaderProgramManager.h"
#include "ShaderProgram.h"
#include <unordered_map>
#include "ShaderUtils.h"

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
	auto fragmentShaderSource = ShaderUtils::loadShaderSource("D:/Workspace/github/OpenGLCore/Testing/shader/line.frag");
	auto vertexShaderSource = ShaderUtils::loadShaderSource("D:/Workspace/github/OpenGLCore/Testing/shader/Line.vert");
	auto geometryShaderSource = ShaderUtils::loadShaderSource("D:/Workspace/github/OpenGLCore/Testing/shader/Line.geom");
	shaderSources[GL_VERTEX_SHADER] = vertexShaderSource;
	shaderSources[GL_GEOMETRY_SHADER] = geometryShaderSource;
	shaderSources[GL_FRAGMENT_SHADER] = fragmentShaderSource;
	auto shaderProgram = shaderProgramManager->getShaderProgram(shaderSources);

	EXPECT_EQ(shaderProgram != nullptr, true);
}
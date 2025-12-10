#include "FrameBuffer.h"
#include "GLFunctions.h"
#include <glad/glad.h>
#include <spdlog/spdlog.h>

struct FrameBuffer::Impl
{
  GLuint m_FrameBuffer;
  GLuint m_Texture;
  int m_Width;
  int m_Height;

  Impl(int width, int height)
    : m_FrameBuffer(0)
    , m_Texture(0)
    , m_Width(width)
    , m_Height(height)
  {
  }
};

FrameBuffer::FrameBuffer(int width, int height)
{
  m_Impl = std::make_unique<Impl>(width, height);
  createFrameBuffer();
}

FrameBuffer::~FrameBuffer() = default;

void FrameBuffer::bind() const {}

void FrameBuffer::unbind() const {}

unsigned int FrameBuffer::texture() const
{
    return m_Impl->m_Texture;
}

int FrameBuffer::textureWidth() const
{
    return m_Impl->m_Width;
}

int FrameBuffer::textureHeight() const
{
    return m_Impl->m_Height;
}

void FrameBuffer::createFrameBuffer()
{
  GL::GenFramebuffers(1, &m_Impl->m_FrameBuffer);
  GL::BindFramebuffer(GL_FRAMEBUFFER, m_Impl->m_FrameBuffer);

  GL::GenTextures(1, &m_Impl->m_Texture);
  GL::BindTexture(GL_TEXTURE_2D, m_Impl->m_Texture);
  GL::TexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Impl->m_Width, m_Impl->m_Height, 0, GL_RGB,
    GL_UNSIGNED_BYTE, nullptr);
  GL::TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  GL::TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  GL::TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
  GL::TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
  float borderColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
  GL::TexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
  GL::FramebufferTexture2D(
    GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_Impl->m_Texture, 0);

  auto status = GL::CheckFramebufferStatus(GL_FRAMEBUFFER);
  if (status != GL_FRAMEBUFFER_COMPLETE)
  {
    SPDLOG_DEBUG("Framebuffer is not complete! Error code: ");
    switch (status)
    {
      case GL_FRAMEBUFFER_UNDEFINED:
        SPDLOG_DEBUG("GL_FRAMEBUFFER_UNDEFINED");
        break;
      case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
        SPDLOG_DEBUG("GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT");
        break;
      case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
        SPDLOG_DEBUG("GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT");
        break;
      case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER:
        SPDLOG_DEBUG("GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER");
        break;
      case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER:
        SPDLOG_DEBUG("GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER");
        break;
      case GL_FRAMEBUFFER_UNSUPPORTED:
        SPDLOG_DEBUG("GL_FRAMEBUFFER_UNSUPPORTED");
        break;
      case GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE:
        SPDLOG_DEBUG("GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE");
        break;
      case GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS:
        SPDLOG_DEBUG("GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS");
        break;
      default:
        SPDLOG_DEBUG("Unknown error ({})", status);
        break;
    }
  }
  else
  {
    SPDLOG_DEBUG("complete create FrameBuffer");
  }

  GL::BindFramebuffer(GL_FRAMEBUFFER, 0);
}

void FrameBuffer::updateBufferSize(int width, int height)
{
  if (width != m_Impl->m_Width || height != m_Impl->m_Height)
  {
    deleteBuffer();
    createFrameBuffer();
  }
}

void FrameBuffer::deleteBuffer()
{
  if (m_Impl->m_FrameBuffer)
  {
    GL::DeleteFramebuffers(1, &m_Impl->m_FrameBuffer);
    GL::DeleteTextures(1, &m_Impl->m_Texture);
    m_Impl->m_FrameBuffer = 0;
    m_Impl->m_Texture = 0;
  }
}

#include "FrameBuffer.h"
#include <glad/glad.h>
#include "GLFunctions.h"

struct FrameBuffer::Impl
{
  GLuint m_FrameBuffer;
  GLuint m_Texture;
  int m_Width;
  int m_Height;

  Impl(int width, int height)
    : m_FrameBuffer(0)
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

FrameBuffer::~FrameBuffer() {}

void FrameBuffer::bind() const {}

void FrameBuffer::unbind() const {}

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
  GL::TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
  GL::TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  GL::TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  GL::FramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_Impl->m_Texture, 0);
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

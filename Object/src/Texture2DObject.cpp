#include "Texture2DObject.h"
#include "GLFunctions.h"
struct Texture2DObject::Private
{
  int mWidth;
  int mHeight;
  GLuint mTexture;
  GLfloat mBorderColor[4];

  Private(int width, int height)
    : mWidth(width)
    , mHeight(height)
    , mTexture(0)
    , mBorderColor{ 0.0f, 0.0f, 0.0f, 1.0f }
  {
  }
};

Texture2DObject::Texture2DObject(int width, int height)
{
  mPrivate = std::make_unique<Private>(width, height);
  createTexture();
}

Texture2DObject::~Texture2DObject() {}

void Texture2DObject::bind(GLenum textureUnit) const
{
  GL::ActiveTexture(textureUnit);
  GL::BindTexture(GL_TEXTURE_2D, mPrivate->mTexture);
}

void Texture2DObject::unbind() const
{
  GL::BindTexture(GL_TEXTURE_2D, 0);
}

int Texture2DObject::width() const
{
  return mPrivate->mWidth;
}

int Texture2DObject::height() const
{
  return mPrivate->mHeight;
}

void Texture2DObject::uploadTexture(const float* textureData)
{
  GL::BindTexture(GL_TEXTURE_2D, mPrivate->mTexture);
  GL::TexImage2D(GL_TEXTURE_2D, 0, GL_R32F, mPrivate->mWidth, mPrivate->mHeight, 0, GL_RED,
    GL_FLOAT, static_cast<const void*>(textureData));
  GL::BindTexture(GL_TEXTURE_2D, 0);
}

void Texture2DObject::updateBufferSize(int width, int height)
{
  mPrivate->mWidth = width;
  mPrivate->mHeight = height;
  deleteBuffer();
  createTexture();
}

void Texture2DObject::deleteBuffer()
{
  if (!mPrivate->mTexture)
  {
    return;
  }

  GL::DeleteTextures(1, &mPrivate->mTexture);
  mPrivate->mTexture = 0;
}

void Texture2DObject::createTexture()
{
  GL::GenTextures(1, &mPrivate->mTexture);
  GL::BindTexture(GL_TEXTURE_2D, mPrivate->mTexture);
  GL::TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  GL::TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  GL::TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
  GL::TexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
  GL::TexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, mPrivate->mBorderColor);
  GL::TexImage2D(
    GL_TEXTURE_2D, 0, GL_R32F, mPrivate->mWidth, mPrivate->mHeight, 0, GL_RED, GL_FLOAT, nullptr);
  GL::BindTexture(GL_TEXTURE_2D, 0);
}

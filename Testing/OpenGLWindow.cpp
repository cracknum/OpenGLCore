#include "OpenGLWindow.h"
#include "OpenGLContext.hpp"

struct OpenGLWindow::WindowPrivate final
{
  bool mIsRunning;
  void* mWindow;
  std::unique_ptr<OpenGLContext> mOpenGLContext;
  WindowPrivate()
    : mIsRunning(false)
    , mWindow(nullptr)
  {
  }
};

OpenGLWindow::OpenGLWindow()
{
  mPrivate = std::make_unique<WindowPrivate>();
  mPrivate->mIsRunning = true;
  mPrivate->mWindow = nullptr;
  mPrivate->mOpenGLContext = std::make_unique<OpenGLContext>();
}

OpenGLWindow::~OpenGLWindow() = default;

bool OpenGLWindow::init(int width, int height, const std::string& title)
{
  mWidth = width;
  mHeight = height;
  mTitle = title;

  mPrivate->mOpenGLContext->init(this);
  return mPrivate->mIsRunning;
}

void* OpenGLWindow::getNativeWindow()
{
  return mPrivate->mWindow;
}

void OpenGLWindow::setNativeWindow(void* window)
{
  mPrivate->mWindow = window;
}

void OpenGLWindow::onResize(int width, int height)
{
  mWidth = width;
  mHeight = height;
}

void OpenGLWindow::close()
{
  mPrivate->mIsRunning = false;
}

void OpenGLWindow::setWindowIcon(const std::string& iconPath) {}
void OpenGLWindow::resize(int width, int height) {}
void OpenGLWindow::fullScreen() {}
void OpenGLWindow::maximum() {}
void OpenGLWindow::exit(){}
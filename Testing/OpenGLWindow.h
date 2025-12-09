#ifndef OPENGL_WINDOW_H
#define OPENGL_WINDOW_H
#include "IWindow.hpp"
#include <string>
#include <memory>

class OpenGLWindow : public IWindow
{
public:
  OpenGLWindow();
  ~OpenGLWindow();
  bool init(int width, int height, const std::string& title);
  void* getNativeWindow() override;
  void setNativeWindow(void* window) override;
  void onResize(int width, int height) override;
  void close() override;
  void setWindowIcon(const std::string& iconPath) override;

  private:
  struct WindowPrivate;
  std::unique_ptr<WindowPrivate> mPrivate;
};
#endif // OPENGL_WINDOW_H
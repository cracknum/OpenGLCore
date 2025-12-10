#ifndef INTERFACE_WINDOW_H
#define INTERFACE_WINDOW_H
#include "ContextExport.h"
#include <string>

class CONTEXT_API IWindow
{
public:
  virtual ~IWindow() = default;
  virtual void* getNativeWindow() = 0;
  virtual void setNativeWindow(void* window) = 0;
  /**
   * @brief 调整尺寸的回调函数
   */
  virtual void onResize(int width, int height) = 0;
  /**
   * @brief 主动调整窗口尺寸
   */
  virtual void resize(int width, int height) = 0;
  virtual void fullScreen() = 0;
  virtual void maximum() = 0;
  virtual void close() = 0;
  virtual void setWindowIcon(const std::string& iconPath) = 0;
  virtual void exit() = 0;

  unsigned int mWidth{};
  unsigned int mHeight{};
  std::string mTitle;
};
#endif // INTERFACE_WINDOW_H
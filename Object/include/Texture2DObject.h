#ifndef TEXTURE_2D_OBJECT_H
#define TEXTURE_2D_OBJECT_H
#include "ObjectExport.h"
#include <glad/glad.h>
#include <memory>
class OBJECT_API Texture2DObject final
{
public:
  Texture2DObject(int width, int height);
  ~Texture2DObject();

  /**
   * @brief 绑定到哪个单元上
   */
  void bind(GLenum textureUnit) const;
  void unbind() const;
  int width() const;
  int height() const;
  GLuint textureId() const;

  void uploadTexture(const float* textureData);

  void updateBufferSize(int width, int height);
  void deleteBuffer();

private:
  void createTexture();

private:
  struct Private;
  std::unique_ptr<Private> mPrivate;
};
#endif // TEXTURE_2D_OBJECT_H
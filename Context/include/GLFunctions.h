#ifndef OPENGL_FUNCTIONS_HELPER
#define OPENGL_FUNCTIONS_HELPER

#include "ContextExport.h"
#include <glad/glad.h>

namespace GL
{

// --- 纹理相关 ---
CONTEXT_API void TexParameterf(GLenum target, GLenum pname, GLfloat param);
CONTEXT_API void TexParameterfv(GLenum target, GLenum pname, const GLfloat* params);
CONTEXT_API void TexParameteri(GLenum target, GLenum pname, GLint param);
CONTEXT_API void TexParameteriv(GLenum target, GLenum pname, const GLint* params);
CONTEXT_API void TexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width,
  GLint border, GLenum format, GLenum type, const void* pixels);
CONTEXT_API void TexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width,
  GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels);
CONTEXT_API void GetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void* pixels);
CONTEXT_API void GetTexParameterfv(GLenum target, GLenum pname, GLfloat* params);
CONTEXT_API void GetTexParameteriv(GLenum target, GLenum pname, GLint* params);
CONTEXT_API void GetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat* params);
CONTEXT_API void GetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint* params);

// --- 清屏与缓冲区 ---
CONTEXT_API void Clear(GLbitfield mask);
CONTEXT_API void ClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
CONTEXT_API void ClearStencil(GLint s);
CONTEXT_API void ClearDepth(GLdouble depth);
CONTEXT_API void DrawBuffer(GLenum buf);
CONTEXT_API void ReadBuffer(GLenum src);
CONTEXT_API void ReadPixels(
  GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels);

// --- 状态设置 ---
CONTEXT_API void Enable(GLenum cap);
CONTEXT_API void Disable(GLenum cap);
CONTEXT_API void IsEnabled(GLenum cap);
CONTEXT_API void CullFace(GLenum mode);
CONTEXT_API void FrontFace(GLenum mode);
CONTEXT_API void Hint(GLenum target, GLenum mode);
CONTEXT_API void LineWidth(GLfloat width);
CONTEXT_API void PointSize(GLfloat size);
CONTEXT_API void PolygonMode(GLenum face, GLenum mode);
CONTEXT_API void Scissor(GLint x, GLint y, GLsizei width, GLsizei height);
CONTEXT_API void ColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
CONTEXT_API void DepthMask(GLboolean flag);
CONTEXT_API void StencilMask(GLuint mask);
CONTEXT_API void DepthFunc(GLenum func);
CONTEXT_API void BlendFunc(GLenum sfactor, GLenum dfactor);
CONTEXT_API void LogicOp(GLenum opcode);
CONTEXT_API void StencilFunc(GLenum func, GLint ref, GLuint mask);
CONTEXT_API void StencilOp(GLenum fail, GLenum zfail, GLenum zpass);
CONTEXT_API void PixelStoref(GLenum pname, GLfloat param);
CONTEXT_API void PixelStorei(GLenum pname, GLint param);

// --- 视口与深度范围 ---
CONTEXT_API void Viewport(GLint x, GLint y, GLsizei width, GLsizei height);
CONTEXT_API void DepthRange(GLdouble n, GLdouble f);

// --- 同步 ---
CONTEXT_API void Flush();
CONTEXT_API void Finish();

// --- 查询 ---
CONTEXT_API void GetBooleanv(GLenum pname, GLboolean* data);
CONTEXT_API void GetDoublev(GLenum pname, GLdouble* data);
CONTEXT_API void GetFloatv(GLenum pname, GLfloat* data);
CONTEXT_API void GetIntegerv(GLenum pname, GLint* data);
CONTEXT_API const GLubyte* GetString(GLenum name);
CONTEXT_API GLenum GetError();

// --- 显示列表（Legacy）---
CONTEXT_API void NewList(GLuint list, GLenum mode);
CONTEXT_API void EndList();
CONTEXT_API void CallList(GLuint list);
CONTEXT_API void CallLists(GLsizei n, GLenum type, const void* lists);
CONTEXT_API void DeleteLists(GLuint list, GLsizei range);
CONTEXT_API GLuint GenLists(GLsizei range);
CONTEXT_API void ListBase(GLuint base);

// --- 顶点、颜色、法线等（Immediate Mode, Legacy）---
CONTEXT_API void Begin(GLenum mode);
CONTEXT_API void End();
CONTEXT_API void Vertex2d(GLdouble x, GLdouble y);
CONTEXT_API void Vertex2f(GLfloat x, GLfloat y);
CONTEXT_API void Vertex2i(GLint x, GLint y);
CONTEXT_API void Vertex2s(GLshort x, GLshort y);
CONTEXT_API void Vertex3d(GLdouble x, GLdouble y, GLdouble z);

CONTEXT_API void Color3b(GLbyte red, GLbyte green, GLbyte blue);
CONTEXT_API void Color3f(GLfloat red, GLfloat green, GLfloat blue);
CONTEXT_API void Color4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);

CONTEXT_API void Normal3f(GLfloat nx, GLfloat ny, GLfloat nz);

CONTEXT_API void TexCoord2f(GLfloat s, GLfloat t);

CONTEXT_API void EdgeFlag(GLboolean flag);
CONTEXT_API void RasterPos2f(GLfloat x, GLfloat y);
CONTEXT_API void Rectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);

CONTEXT_API void GenFramebuffers(GLsizei n, GLuint* framebuffers);
CONTEXT_API void DeleteFramebuffers(GLsizei n, const GLuint* framebuffers);
CONTEXT_API void GenTextures(GLsizei n, GLuint* textures);
CONTEXT_API void DeleteTextures(GLsizei n, const GLuint* textures);
CONTEXT_API void BindFramebuffer(GLenum target, GLuint framebuffer);
CONTEXT_API void BindTexture(GLenum target, GLuint texture);
CONTEXT_API GLenum CheckFramebufferStatus(GLenum target);

CONTEXT_API void FramebufferTexture2D(
  GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);

CONTEXT_API void DeleteShader(GLuint shader);
CONTEXT_API void DeleteProgram(GLuint program);

CONTEXT_API void ShaderSource(
  GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length);
CONTEXT_API void GetShaderiv(GLuint shader, GLenum pname, GLint* params);
CONTEXT_API void GetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
CONTEXT_API void AttachShader(GLuint program, GLuint shader);
CONTEXT_API void LinkProgram(GLuint program);
CONTEXT_API void GetProgramiv(GLuint program, GLenum pname, GLint* params);
CONTEXT_API void GetProgramInfoLog(
  GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
CONTEXT_API void UseProgram(GLuint program);
CONTEXT_API GLint GetUniformLocation(GLuint program, const GLchar* name);
CONTEXT_API void UniformMatrix4fv(
  GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
CONTEXT_API void Uniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
CONTEXT_API void Uniform2f(GLint location, GLfloat v0, GLfloat v1);
CONTEXT_API void Uniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
CONTEXT_API void Uniform1i(GLint location, GLint v0);
CONTEXT_API void Uniform1f(GLint location, GLfloat v0);
CONTEXT_API GLuint CreateProgram(void);
CONTEXT_API GLuint CreateShader(GLenum type);
CONTEXT_API void CompileShader(GLuint shader);

CONTEXT_API void BindVertexArray(GLuint array);
CONTEXT_API void DrawElements(GLenum mode, GLsizei count, GLenum type, const void* indices);
CONTEXT_API void GenVertexArrays(GLsizei n, GLuint* arrays);
CONTEXT_API void GenBuffers(GLsizei n, GLuint* buffers);
CONTEXT_API void BindBuffer(GLenum target, GLuint buffer);
CONTEXT_API void BufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage);
CONTEXT_API void EnableVertexAttribArray(GLuint index);
CONTEXT_API void VertexAttribPointer(
  GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
CONTEXT_API void DisableVertexAttribArray(GLuint index);
CONTEXT_API void DeleteBuffers(GLsizei n, const GLuint* buffers);
CONTEXT_API void DeleteVertexArrays(GLsizei n, const GLuint* arrays);
} // namespace GL

#endif // OPENGL_FUNCTIONS_HELPER
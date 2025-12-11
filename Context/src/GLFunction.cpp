#include "GLFunctions.h"

namespace GL
{

void TexParameterf(GLenum target, GLenum pname, GLfloat param)
{
  glTexParameterf(target, pname, param);
}
void TexParameterfv(GLenum target, GLenum pname, const GLfloat* params)
{
  glTexParameterfv(target, pname, params);
}
void TexParameteri(GLenum target, GLenum pname, GLint param)
{
  glTexParameteri(target, pname, param);
}
void TexParameteriv(GLenum target, GLenum pname, const GLint* params)
{
  glTexParameteriv(target, pname, params);
}
void TexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border,
  GLenum format, GLenum type, const void* pixels)
{
  glTexImage1D(target, level, internalformat, width, border, format, type, pixels);
}
void TexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height,
  GLint border, GLenum format, GLenum type, const void* pixels)
{
  glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}
void GetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void* pixels)
{
  glGetTexImage(target, level, format, type, pixels);
}
void GetTexParameterfv(GLenum target, GLenum pname, GLfloat* params)
{
  glGetTexParameterfv(target, pname, params);
}
void GetTexParameteriv(GLenum target, GLenum pname, GLint* params)
{
  glGetTexParameteriv(target, pname, params);
}
void GetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat* params)
{
  glGetTexLevelParameterfv(target, level, pname, params);
}
void GetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint* params)
{
  glGetTexLevelParameteriv(target, level, pname, params);
}

// --- 清屏与缓冲区 ---
void Clear(GLbitfield mask)
{
  glClear(mask);
}
void ClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
  glClearColor(red, green, blue, alpha);
}
void ClearStencil(GLint s)
{
  glClearStencil(s);
}
void ClearDepth(GLdouble depth)
{
  glClearDepth(depth);
}
void DrawBuffer(GLenum buf)
{
  glDrawBuffer(buf);
}
void ReadBuffer(GLenum src)
{
  glReadBuffer(src);
}
void ReadPixels(
  GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels)
{
  glReadPixels(x, y, width, height, format, type, pixels);
}

// --- 状态设置 ---
void Enable(GLenum cap)
{
  glEnable(cap);
}
void Disable(GLenum cap)
{
  glDisable(cap);
}
void IsEnabled(GLenum cap)
{
  glIsEnabled(cap);
}
void CullFace(GLenum mode)
{
  glCullFace(mode);
}
void FrontFace(GLenum mode)
{
  glFrontFace(mode);
}
void Hint(GLenum target, GLenum mode)
{
  glHint(target, mode);
}
void LineWidth(GLfloat width)
{
  glLineWidth(width);
}
void PointSize(GLfloat size)
{
  glPointSize(size);
}
void PolygonMode(GLenum face, GLenum mode)
{
  glPolygonMode(face, mode);
}
void Scissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
  glScissor(x, y, width, height);
}
void ColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
  glColorMask(red, green, blue, alpha);
}
void DepthMask(GLboolean flag)
{
  glDepthMask(flag);
}
void StencilMask(GLuint mask)
{
  glStencilMask(mask);
}
void DepthFunc(GLenum func)
{
  glDepthFunc(func);
}
void BlendFunc(GLenum sfactor, GLenum dfactor)
{
  glBlendFunc(sfactor, dfactor);
}
void LogicOp(GLenum opcode)
{
  glLogicOp(opcode);
}
void StencilFunc(GLenum func, GLint ref, GLuint mask)
{
  glStencilFunc(func, ref, mask);
}
void StencilOp(GLenum fail, GLenum zfail, GLenum zpass)
{
  glStencilOp(fail, zfail, zpass);
}
void PixelStoref(GLenum pname, GLfloat param)
{
  glPixelStoref(pname, param);
}
void PixelStorei(GLenum pname, GLint param)
{
  glPixelStorei(pname, param);
}

// --- 视口与深度范围 ---
void Viewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
  glViewport(x, y, width, height);
}
void DepthRange(GLdouble n, GLdouble f)
{
  glDepthRange(n, f);
}

// --- 同步 ---
void Flush()
{
  glFlush();
}
void Finish()
{
  glFinish();
}

// --- 查询 ---
void GetBooleanv(GLenum pname, GLboolean* data)
{
  glGetBooleanv(pname, data);
}
void GetDoublev(GLenum pname, GLdouble* data)
{
  glGetDoublev(pname, data);
}
void GetFloatv(GLenum pname, GLfloat* data)
{
  glGetFloatv(pname, data);
}
void GetIntegerv(GLenum pname, GLint* data)
{
  glGetIntegerv(pname, data);
}
const GLubyte* GetString(GLenum name)
{
  return glGetString(name);
}
GLenum GetError()
{
  return glGetError();
}

// --- 显示列表（Legacy）---
void NewList(GLuint list, GLenum mode)
{
  glNewList(list, mode);
}
void EndList()
{
  glEndList();
}
void CallList(GLuint list)
{
  glCallList(list);
}
void CallLists(GLsizei n, GLenum type, const void* lists)
{
  glCallLists(n, type, lists);
}
void DeleteLists(GLuint list, GLsizei range)
{
  glDeleteLists(list, range);
}
GLuint GenLists(GLsizei range)
{
  return glGenLists(range);
}
void ListBase(GLuint base)
{
  glListBase(base);
}

// --- 顶点、颜色、法线等（Immediate Mode, Legacy）---
void Begin(GLenum mode)
{
  glBegin(mode);
}
void End()
{
  glEnd();
}
void Vertex2d(GLdouble x, GLdouble y)
{
  glVertex2d(x, y);
}
void Vertex2f(GLfloat x, GLfloat y)
{
  glVertex2f(x, y);
}
void Vertex2i(GLint x, GLint y)
{
  glVertex2i(x, y);
}
void Vertex2s(GLshort x, GLshort y)
{
  glVertex2s(x, y);
}
void Vertex3d(GLdouble x, GLdouble y, GLdouble z)
{
  glVertex3d(x, y, z);
}

void Color3b(GLbyte red, GLbyte green, GLbyte blue)
{
  glColor3b(red, green, blue);
}
void Color3f(GLfloat red, GLfloat green, GLfloat blue)
{
  glColor3f(red, green, blue);
}
void Color4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
  glColor4f(red, green, blue, alpha);
}

void Normal3f(GLfloat nx, GLfloat ny, GLfloat nz)
{
  glNormal3f(nx, ny, nz);
}

void TexCoord2f(GLfloat s, GLfloat t)
{
  glTexCoord2f(s, t);
}

void EdgeFlag(GLboolean flag)
{
  glEdgeFlag(flag);
}
void RasterPos2f(GLfloat x, GLfloat y)
{
  glRasterPos2f(x, y);
}
void Rectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
  glRectf(x1, y1, x2, y2);
}

void GenFramebuffers(GLsizei n, GLuint* framebuffers)
{
  glGenFramebuffers(n, framebuffers);
}

void DeleteFramebuffers(GLsizei n, const GLuint* framebuffers)
{
  glDeleteFramebuffers(n, framebuffers);
}
inline GLenum CheckFramebufferStatus(GLenum target)
{
  return glCheckFramebufferStatus(target);
}

void GenTextures(GLsizei n, GLuint* textures)
{
  glGenTextures(n, textures);
}

void DeleteTextures(GLsizei n, const GLuint* textures)
{
  glDeleteTextures(n, textures);
}

void ActiveTexture(GLenum texture)
{
	glActiveTexture(texture);
}

void BindFramebuffer(GLenum target, GLuint framebuffer)
{
  glBindFramebuffer(target, framebuffer);
}

void BindTexture(GLenum target, GLuint texture)
{
  glBindTexture(target, texture);
}

void FramebufferTexture2D(
  GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
  glFramebufferTexture2D(target, attachment, textarget, texture, level);
}

void DeleteShader(GLuint shader)
{
  glDeleteShader(shader);
}

void DeleteProgram(GLuint program)
{
  glDeleteProgram(program);
}

void ShaderSource(GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length)
{
  glShaderSource(shader, count, string, length);
}

void GetShaderiv(GLuint shader, GLenum pname, GLint* params)
{
  glGetShaderiv(shader, pname, params);
}

void GetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog)
{
  glGetShaderInfoLog(shader, bufSize, length, infoLog);
}

void AttachShader(GLuint program, GLuint shader)
{
  glAttachShader(program, shader);
}

void LinkProgram(GLuint program)
{
  glLinkProgram(program);
}

void GetProgramiv(GLuint program, GLenum pname, GLint* params)
{
  glGetProgramiv(program, pname, params);
}

void GetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog)
{
  glGetProgramInfoLog(program, bufSize, length, infoLog);
}

void UseProgram(GLuint program)
{
  glUseProgram(program);
}

GLint GetUniformLocation(GLuint program, const GLchar* name)
{
  return glGetUniformLocation(program, name);
}

void UniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value)
{
  glUniformMatrix4fv(location, count, transpose, value);
}

void Uniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
{
  glUniform3f(location, v0, v1, v2);
}

void Uniform2f(GLint location, GLfloat v0, GLfloat v1)
{
  glUniform2f(location, v0, v1);
}

void Uniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
  glUniform4f(location, v0, v1, v2, v3);
}

void Uniform1i(GLint location, GLint v0)
{
  glUniform1i(location, v0);
}
void Uniform1f(GLint location, GLfloat v0)
{
  glUniform1f(location, v0);
}

GLuint CreateProgram(void)
{
  return glCreateProgram();
}

GLuint CreateShader(GLenum type)
{
  return glCreateShader(type);
}

void CompileShader(GLuint shader)
{
  glCompileShader(shader);
}

void BindVertexArray(GLuint array)
{
  glBindVertexArray(array);
}

void DrawElements(GLenum mode, GLsizei count, GLenum type, const void* indices)
{
  glDrawElements(mode, count, type, indices);
}

void GenVertexArrays(GLsizei n, GLuint* arrays)
{
  glGenVertexArrays(n, arrays);
}

void GenBuffers(GLsizei n, GLuint* buffers)
{
  glGenBuffers(n, buffers);
}

void BindBuffer(GLenum target, GLuint buffer)
{
  glBindBuffer(target, buffer);
}

void BufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage)
{
  glBufferData(target, size, data, usage);
}

void EnableVertexAttribArray(GLuint index)
{
  glEnableVertexAttribArray(index);
}

void VertexAttribPointer(
  GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer)
{
  glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}

void DisableVertexAttribArray(GLuint index)
{
  glDisableVertexAttribArray(index);
}

void DeleteBuffers(GLsizei n, const GLuint* buffers)
{
  glDeleteBuffers(n, buffers);
}

void DeleteVertexArrays(GLsizei n, const GLuint* arrays)
{
  glDeleteVertexArrays(n, arrays);
}

} // namespace GL
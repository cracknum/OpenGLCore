#include "VertexIndexBuffer.h"
#include "Vertices.h"
#include <glm/glm.hpp>
#include <sstream>
#include "GLFunctions.h"

struct VertexIndexBuffer::Impl
{
  GLuint m_VBO;
  GLuint m_VAO;
  GLuint m_EBO;
  Vertices m_Vertices;
  glm::mat4 m_IndexToWorldMatrix;

  explicit Impl()
    : m_VBO(0)
    , m_VAO(0)
    , m_EBO(0)
    , m_IndexToWorldMatrix(1.0f)
  {
  }
};

VertexIndexBuffer::VertexIndexBuffer()
{
  m_Impl = std::make_unique<Impl>();
}

VertexIndexBuffer::~VertexIndexBuffer()
{
  deleteBuffer();
}

void VertexIndexBuffer::bind()
{
  if (!m_Impl->m_VAO)
  {
    throw std::runtime_error("vao is nullptr");
  }
  GL::BindVertexArray(m_Impl->m_VAO);
}

void VertexIndexBuffer::draw(GLenum drawMode)
{
  if (m_Impl->m_Vertices.m_Indices == nullptr || m_Impl->m_Vertices.m_IndicesSize == 0)
  {
    throw std::runtime_error("vertices' indices not set");
  }

  bind();

  GL::DrawElements(drawMode, m_Impl->m_Vertices.m_IndicesSize, GL_UNSIGNED_INT, nullptr);

  unbind();
}

void VertexIndexBuffer::unbind()
{
  GL::BindVertexArray(0);
}

void VertexIndexBuffer::createBuffer(Vertices& vertices) const
{
  const bool isDataInvalid = vertices.m_Data == nullptr;
  const bool isDataSizeInvalid = vertices.m_DataSize == 0;
  const bool isIndicesInvalid = vertices.m_Indices == nullptr;
  const bool isIndicesSizeInvalid = vertices.m_IndicesSize == 0;
  if (isDataInvalid || isDataSizeInvalid || isIndicesInvalid || isIndicesSizeInvalid)
  {
    std::ostringstream oss;
    oss << "vertices setting error: status{dataValid:" << !isDataInvalid
        << " dataSizeValid: " << !isDataSizeInvalid << " indicesValid: " << !isIndicesInvalid
        << " indicesSizeValid: " << !isIndicesSizeInvalid << "}";
    throw std::runtime_error(oss.str());
  }
  m_Impl->m_Vertices = std::move(vertices);

  GL::GenVertexArrays(1, &m_Impl->m_VAO);
  GL::BindVertexArray(m_Impl->m_VAO);

  GL::GenBuffers(1, &m_Impl->m_VBO);
  GL::BindBuffer(GL_ARRAY_BUFFER, m_Impl->m_VBO);
  GL::BufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * m_Impl->m_Vertices.m_DataSize,
    m_Impl->m_Vertices.m_Data, GL_STATIC_DRAW);

  GL::GenBuffers(1, &m_Impl->m_EBO);
  GL::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Impl->m_EBO);
  GL::BufferData(GL_ELEMENT_ARRAY_BUFFER, m_Impl->m_Vertices.m_IndicesSize * sizeof(GLuint),
    m_Impl->m_Vertices.m_Indices, GL_STATIC_DRAW);

  GL::EnableVertexAttribArray(0);

  GLsizei offset = 0;
  GLuint index = 0;
  GLsizei stride = m_Impl->m_Vertices.m_PointAttribute.second * sizeof(GLfloat);
  if (m_Impl->m_Vertices.m_NormalAttribute.first)
  {
    stride += m_Impl->m_Vertices.m_NormalAttribute.second * sizeof(GLfloat);
  }
  if (m_Impl->m_Vertices.m_TextureAttribute.first)
  {
    stride += m_Impl->m_Vertices.m_TextureAttribute.second * sizeof(GLfloat);
  }

  GL::VertexAttribPointer(
    index, m_Impl->m_Vertices.m_PointAttribute.second, GL_FLOAT, false, stride, nullptr);
  offset += m_Impl->m_Vertices.m_PointAttribute.second;
  index += 1;
  if (m_Impl->m_Vertices.m_NormalAttribute.first)
  {
    GL::EnableVertexAttribArray(index);
    GL::VertexAttribPointer(index, m_Impl->m_Vertices.m_NormalAttribute.second, GL_FLOAT, false,
      stride, reinterpret_cast<void*>(offset * sizeof(GLfloat)));
    offset += m_Impl->m_Vertices.m_NormalAttribute.second;
    index += 1;
  }
  if (m_Impl->m_Vertices.m_TextureAttribute.first)
  {
    GL::EnableVertexAttribArray(index);
    GL::VertexAttribPointer(index, m_Impl->m_Vertices.m_TextureAttribute.second, GL_FLOAT, GL_FALSE,
      stride, reinterpret_cast<void*>(offset * sizeof(GLfloat)));
    index += 1;
    offset += m_Impl->m_Vertices.m_TextureAttribute.second;
  }
}

void VertexIndexBuffer::deleteBuffer()
{
  if (!m_Impl->m_VAO)
  {
    return;
  }

  GL::DisableVertexAttribArray(0);

  if (m_Impl->m_Vertices.m_NormalAttribute.first)
  {
    GL::DisableVertexAttribArray(1);
  }
  if (m_Impl->m_Vertices.m_TextureAttribute.first)
  {
    GL::DisableVertexAttribArray(2);
  }

  GL::BindVertexArray(0);
  GL::BindBuffer(GL_ARRAY_BUFFER, 0);
  GL::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

  GL::DeleteBuffers(1, &m_Impl->m_VBO);
  GL::DeleteBuffers(1, &m_Impl->m_EBO);
  GL::DeleteVertexArrays(1, &m_Impl->m_VAO);
}

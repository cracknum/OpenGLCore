#include "ShaderProgramManager.h"
#include <string>
#include <algorithm>

struct ShaderProgramManager::Impl
{
  std::unordered_map<size_t, ShaderProgramPointer> m_ShaderCache;
  Impl() {}
};

ShaderProgramManager::ShaderProgramManager()
{
  m_Impl = std::make_unique<Impl>();
}

ShaderProgramManager::~ShaderProgramManager() = default;

ShaderProgramManager::ShaderProgramPointer ShaderProgramManager::getShaderProgram(
  const std::unordered_map<GLenum, std::string>& shaderSources)
{
  auto hashResult = hash(shaderSources);
  auto it = m_Impl->m_ShaderCache.find(hashResult);
  if (it != m_Impl->m_ShaderCache.end())
  {
    return it->second;
  }
  else
  {
    auto shaderProgram = std::make_shared<ShaderProgram>(shaderSources);
    m_Impl->m_ShaderCache[hashResult] = shaderProgram;
    return shaderProgram;
  }
}

size_t ShaderProgramManager::hash(const std::unordered_map<GLenum, std::string>& shaderSources)
{
    std::vector<std::pair<GLenum, std::string>> items;
    for (const auto& [type, source] : shaderSources) {
        if (!source.empty()) {
            items.emplace_back(type, source);
        }
    }

    // 必须排序！因为 unordered_map 遍历顺序不确定
    std::sort(items.begin(), items.end(),
        [](const auto& a, const auto& b) { return a.first < b.first; });

    size_t seed = 0;
    for (const auto& [type, source] : items) {
        // 哈希类型 + 内容
        hash_combine(seed, static_cast<size_t>(type));
        hash_combine(seed, std::hash<std::string>{}(source));
    }
    return seed;
}

void ShaderProgramManager::hash_combine(size_t& seed, const size_t& v)
{
    seed ^= v + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

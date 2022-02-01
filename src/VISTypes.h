#pragma once

#include <algorithm>
#include <functional>
#ifdef __cplusplus
#include <map>
#include <memory>
#include <string>
#include <variant>
#include <vector>

extern "C" {
#endif

#ifdef __cplusplus
enum class visl_tokens {
#else
enum visl_tokens {
#endif
  visl_emp = -1,
  visl_c1,
  visl_w1,
  visl_w2,
  visl_u,
  visl_ast,  // [*]
};

#ifdef __cplusplus
namespace visl_cpp {
  typedef std::multimap<visl_tokens, std::vector<std::string>> tokens_args;
  typedef std::variant<std::vector<std::string>, std::vector<int>> tokens_func;
  struct tokens_struct {
    std::string m_name;
    std::function<void(tokens_func)> m_func;
    
    void ReplaceFunc(std::function<void(tokens_func)> a_func);
    std::string GetName() const;
    void Exec(visl_cpp::tokens_func a_args) const;
  };
  typedef std::map<visl_tokens, visl_cpp::tokens_struct> tokens_map;
  const visl_cpp::tokens_map tokens_def {
    {visl_tokens::visl_emp, {.m_name = "EMP", .m_func = [](auto i) {} }},
    {visl_tokens::visl_c1, {.m_name = "C1", .m_func = [](auto i) {} }},
    {visl_tokens::visl_w1, {.m_name = "W1", .m_func = [](auto i) {} }},
    {visl_tokens::visl_w2, {.m_name = "W2", .m_func = [](auto i) {} }},
  };
}  // namespace visl_cpp

class VISLTokens {
 public:
  VISLTokens(visl_cpp::tokens_map a_tokens_base=visl_cpp::tokens_def);

  std::vector<std::string> GetAllNames() const;
  visl_tokens GetToken(std::string a_value) const;
  struct visl_cpp::tokens_struct Get(visl_tokens a_token) const;
  bool IsEmpty() const;

  operator std::map<visl_tokens, struct visl_cpp::tokens_struct>() {
    return this->m_tokens;
  }
  operator std::vector<std::string>() {
    return this->GetAllNames();
  }

 private:
  visl_cpp::tokens_map m_tokens;
};
}
#endif

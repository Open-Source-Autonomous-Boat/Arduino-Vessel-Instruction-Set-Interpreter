#pragma once

#ifdef __cplusplus
#include <map>
#include <memory>
#include <string>
#include <vector>
extern "C" {
#endif

#ifdef __cplusplus
enum class visl_tokens {
#else
enum visl_tokens {
#endif
  visl_emp = -1,
  visl_h1,
  visl_c1,
  visl_w1,
  visl_w2,
  visl_u,
  visl_ast,  // [*]
};

#ifdef __cplusplus
namespace visl_cpp {
typedef std::map<visl_tokens, std::string> tokens_type;
}
}
#endif

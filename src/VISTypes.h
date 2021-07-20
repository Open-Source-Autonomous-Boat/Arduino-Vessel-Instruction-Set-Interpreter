#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
enum class visl_types { /* So VS2019 won't throw a hissy fit */
#else
enum visl_types {
#endif
  visl_emp = -1,
  visl_h1,
  visl_c1,
  visl_w1,
  visl_w2,
  visl_u,
  visl_ast, // [*]
};

#ifdef __cplusplus
}
#endif

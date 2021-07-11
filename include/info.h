#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct visl_file_info {
  int instruction_type;
};

enum visl_instruction_type {
  mission_instruction,
  instruction_msg,
  data_msg,
};

#ifdef __cplusplus
}
#endif

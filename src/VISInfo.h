#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Metadata of file
 */
struct visl_file_info {
  int instruction_type;
};

/*
 * File instruction type
 * ---
 * Taken from VIS documentation on H1
 */
enum visl_instruction_type {
  mission_instruction,
  instruction_msg,
  data_msg,
};

#ifdef __cplusplus
}
#endif

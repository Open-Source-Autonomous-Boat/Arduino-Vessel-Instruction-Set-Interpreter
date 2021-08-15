#include "VISUtils.h"

#ifndef UNICODE
#define UNICODE
#endif

std::vector<std::string> string_utils::split_string(std::string text,
                                                    char delim) {
  std::vector<std::string> tmp_vector;
  std::stringstream stream(text);
  for (std::string tmp; std::getline(stream, tmp, delim);) {
    tmp_vector.push_back(tmp);
  }
  return tmp_vector;
}

void string_utils::strip_string(std::string* text, char delim) {
  text->erase(std::remove(text->begin(), text->end(), delim), text->end());
  return;
}

template <typename T>
void token_utils::map_insert(visl_cpp::tokens_type* tokens, visl_tokens type,
                             T value) {
  tokens->insert(std::pair<visl_tokens, std::string>(type, std::string(value)));
}

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

bool string_utils::regex_find(
    std::string a_text, std::string a_regexp,
    std::regex_constants::syntax_option_type a_re_flags) {
  return (std::regex_search(a_text, std::regex(a_regexp, a_re_flags))) ? true
                                                                       : false;
}

std::string string_utils::token_stringify(visl_tokens a_token) {
  auto ret_val = visl_cpp::tok_strings.find(a_token);
  return (ret_val == visl_cpp::tok_strings.end()) ? "ERR" : ret_val->second;
}

void token_utils::map_insert(visl_cpp::tokens_type* tokens, visl_tokens type,
                             std::string value) {
  tokens->insert(std::pair<visl_tokens, std::string>(type, value));
}

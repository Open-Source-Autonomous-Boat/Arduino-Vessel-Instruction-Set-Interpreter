#include "VISUtils.h"

#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

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

std::string string_utils::strip_string(std::string text, char delim) {
  text.erase(std::remove(text.begin(), text.end(), delim), text.end());
  return text;
}

bool string_utils::regex_find(
    std::string a_text, std::string a_regexp,
    std::regex_constants::syntax_option_type a_re_flags) {
  return (std::regex_search(a_text, std::regex(a_regexp, a_re_flags))) ? true
                                                                       : false;
}

std::string string_utils::join_string(std::vector<std::string> a_vector,
                                      char a_delim) {
  std::ostringstream joined_string;
  std::copy(a_vector.begin() + 1, a_vector.end(),
            std::ostream_iterator<std::string>(joined_string, &a_delim));
  std::string final_string = joined_string.str();
  if (!final_string.empty()) {
    final_string = strip_string(final_string, ' ');
    final_string.pop_back();
  }
  std::cout << final_string << std::endl;
  ;
  return final_string;
}

std::string string_utils::token_stringify(visl_tokens a_token) {
  //auto ret_val = visl_cpp::tokens.find(a_token)->second.GetName();
  return "";
}


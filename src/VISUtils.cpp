#include "VISUtils.h"

std::vector<std::string> string_utils::split_string(std::string text,
                                                    char delim) {
  std::string tmp;
  std::vector<std::string> tmp_vector;
  std::stringstream stream(text);
  while (getline(stream, tmp, delim)) {
    tmp_vector.push_back(tmp);
  }
  return tmp_vector;
}

void string_utils::strip_string(std::string text, char delim) {
  text.erase(std::remove(text.begin(), text.end(), delim), text.end());
}

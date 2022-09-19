#include <vector>
#include <string>
#pragma once

namespace string_utils {
  std::vector<std::string> SplitString(std::string aLine, char aDelim);
  std::string FlattenString(std::vector<std::string> aLines, std::string aDelim, std::string aEOL);
};


#include <string>
#include <vector>
#include <sstream>
#include "def_macros.h"

namespace string_utils {
  std::vector<std::string> SplitString(std::string aLine, char aDelim) {
      std::stringstream stream(aLine);
  std::string segment;
  std::vector<std::string> output;

  while (std::getline(stream, segment, aDelim)) {
    auto line_ending = std::string(1, VISL_LINE_ENDING);
    auto colon_pos = segment.find(line_ending);
    if (!(colon_pos == std::string::npos)) {
      segment.replace(colon_pos, line_ending.length(), "");
    }
    output.push_back(segment);
  }

  return output;
  }

  std::string FlattenString(std::vector<std::string> aLines, std::string aDelim, std::string aEOL) {
      std::stringstream stream;
  std::vector<std::string>::const_iterator it;
  for (it = aLines.cbegin(); it != aLines.end(); ++it) {
    if (std::next(it) == aLines.end()) {
      stream << *it << aEOL;
    } else {
      stream << *it << aDelim;
    }
  }
  return stream.str();
  }
}

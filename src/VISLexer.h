#include <string>
#include <vector>
#include "VISCommands.h"
#pragma once

#define VISL_COMMENT '#'
#define VISL_LINE_ENDING ';'

class VISLexer {
  VISCommands *mCommandCtrl;
 public:
  VISLexer(VISCommands *ACommands);

  void Lex(std::string aLine);
  void Lex(std::vector<std::string> aLines);

  static std::vector<std::string> SplitString(std::string aLine, char aDelim);
  static std::string FlattenString(std::vector<std::string> aLines, std::string aDelim, std::string aEOL);
};

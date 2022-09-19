#include <string>
#include <vector>
#include "VISCommands.h"
#include "utils/def_macros.h"
#pragma once

class VISLexer {
  VISCommands *mCommandCtrl;
 public:
  VISLexer(VISCommands *ACommands);

  void Lex(std::string aLine);
  void Lex(std::vector<std::string> aLines);

};

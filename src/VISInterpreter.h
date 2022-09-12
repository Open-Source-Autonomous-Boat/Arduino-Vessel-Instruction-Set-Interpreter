#include "VISCommands.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#pragma once

class VISInterpreter {
  std::vector<std::string> m_args;
  VISCommands *m_commands = new VISCommands();

public:
  VISInterpreter(std::string a_line);
  VISInterpreter(std::fstream &a_file);

  void start();

  void _DEBUG_printHeaderType();

private:
  std::vector<std::string> _format_lines();
};

#include "VISInterpreter.h"
#include "VISLexer.h"
#include "utils/def_macros.h"
#include <regex>
#include <string>
#include <algorithm>

VISInterpreter::VISInterpreter(std::string a_line) { m_args.push_back(a_line); }

VISInterpreter::VISInterpreter(std::fstream &a_file) {
  if (!a_file || !a_file.is_open()) {
    std::cerr << "Failed to get fstream of file!" << std::endl;
    return;
  }
  for (std::string line; std::getline(a_file, line);) {
    m_args.push_back(line);
  }
  m_args = this->_format_lines();
  return;
}

std::vector<std::string> VISInterpreter::_format_lines() {
  std::vector<std::string> formated_args;
  std::string temp_string;

  auto _strip_whiteline = [](std::string a_line) {
    a_line.erase(std::remove_if(a_line.begin(), a_line.end(), ::isspace), a_line.end());
  };

  for (auto &i : m_args) {
    _strip_whiteline(i);
    temp_string += (i + "\n");
    if (i.ends_with(VISL_LINE_ENDING)) {
      formated_args.push_back(temp_string);
      temp_string = "";
    }
  }
  return formated_args;
}

void VISInterpreter::start() {
  std::unique_ptr<VISLexer> lexer(new VISLexer(this->m_commands));
  lexer->Lex(this->m_args);
}

void VISInterpreter::_DEBUG_printHeaderType() {
  std::cout << this->m_commands->getHeaderType() << std::endl;
}

void VISInterpreter::_DEBUG_printNavigationType() {
  std::cout << this->m_commands->getNavigationMode() << std::endl;
}

void VISInterpreter::_DEBUG_printPresetCmd(int a_cmd) {
  std::cout << "WIP" << std::endl;
}

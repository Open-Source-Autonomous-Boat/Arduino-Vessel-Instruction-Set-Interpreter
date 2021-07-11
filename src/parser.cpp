#include "parser/parser.h"

#include <fstream>
#include <ios>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

#include "parser/utils.h"

VISLParser::VISLParser(){};
VISLParser::~VISLParser() { delete this->file; }

void VISLParser::OpenFile(std::string path) {
  this->file->open(path);
  this->is_opened = true;
  this->Prepare();
  this->Parse();
  return;
}

void VISLParser::CloseFile() {
  if (!this->is_opened && !this->file) {
    std::cerr << "Can't close closed file" << std::endl;
    return;
  }
  this->file->close();
  this->is_opened = false;
  return;
}

void VISLParser::Prepare() {
  std::vector<std::string> tokens;
  std::string line;
  if (!this->is_opened) return;
  for (std::string tmp; std::getline(*this->file, tmp);) {
    if (tmp.rfind("(#|//)", 0)) {
      continue;
    }
    line += tmp;
  }
  tokens = string_utils::split_string(line, ';');
  for (auto &i : tokens) {
    string_utils::strip_string(i, ' ');
  }
  this->tokens = tokens;
}

void VISLParser::Parse() {
  for (auto &i : this->tokens) {
    std::cerr << i << std::endl;
  }
}

void VISLParser::DetermineTypeFromLine(std::vector<std::string> tokens) {}

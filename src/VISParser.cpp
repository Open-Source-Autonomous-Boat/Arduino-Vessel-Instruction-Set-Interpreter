#include "VISParser.h"

#ifndef UNICODE
#define UNICODE
#endif

#ifdef __cplusplus

VISParser::VISParser(){};
VISParser::~VISParser() {}

void VISParser::OpenFile(VISFile *a_file) {
  // Opens file with ifstream
  this->m_file = a_file;
  // Strips unneeded characters and seperates lines into vector entries
  this->PrepareFile();
  // Parse file
  this->Parse();
  return;
}

void VISParser::ParseLine(std::string line) {
  // Init vector of tokens
  std::vector<std::string> tokens;
  if (line.rfind("#", 0) == 0) {  // Stops if comment
    return;
  }
  tokens = string_utils::split_string(line, ';');
  for (auto &i : tokens) {
    string_utils::strip_string(&i, ' ');
  }
  this->Parse();
  return;
}

/* Closes file */
void VISParser::CloseFile() { this->m_file = nullptr; }

/* Prepare file for parsing */
void VISParser::PrepareFile() {
  // Init vector of tokens
  std::vector<std::string> tokens;
  // Init empty "line" string
  std::string line;
  // For each line in file...
  for (std::string tmp; std::getline(*this->m_file->GetFileObject(), tmp);) {
    if (tmp.rfind("#", 0) == 0) {  // Strip comments out
      continue;
    }
    // Concancate into string
    line += tmp;
  }
  // Split string by semi-colon (;)
  tokens = string_utils::split_string(line, ';');
  for (auto &i : tokens) {  // For each line in file...
    // Strip whitespace
    string_utils::strip_string(&i, ' ');
  }
  // Set class property (tokens) with local vector (tokens)
  // TODO: Set new name
  this->m_tokens = tokens;
}

/* Parse file */
void VISParser::Parse() {
  // WIP
  // TODO: Actually parse file
  for (auto &i : this->m_tokens) {
    std::cout << i << std::endl;
  }
}

void VISParser::DetermineTypeFromLine(std::vector<std::string> tokens) {}
#endif

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

void VISParser::ParseLine(std::string a_line) {
  // Init vector of tokens
  std::vector<std::string> tokens;
  if (a_line.rfind("#", 0) == 0) {  // Stops if comment
    return;
  }
  tokens = string_utils::split_string(a_line, ';');
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
  // Init vector of lines
  std::vector<std::string> lines;
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
  lines = string_utils::split_string(line, ';');
  for (auto &i : lines) {  // For each line in file...
    // Strip whitespace
    string_utils::strip_string(&i, ' ');
  }
  // Set class property (lines) with local vector (tokens)
  this->m_lines = lines;
}

/* Parse file */
void VISParser::Parse() {
  // WIP
  visl_cpp::tokens_type::iterator max_pos =
      this->m_tokens->begin();  // TODO: Forgot what this is for
  for (auto &i : this->m_lines) {
    visl_cpp::tokens_type line_tokens;
    auto local_tokens = string_utils::split_string(i, ',');
    auto instruction = this->DetermineTypeFromLine(i);
    if (instruction == visl_tokens::visl_emp) {
      continue;
    }
    token_utils::map_insert(this->m_tokens.get(), instruction, "");
  }
}

visl_tokens VISParser::DetermineTypeFromLine(std::string a_line) {
  auto def_flags = std::regex_constants::icase | std::regex_constants::grep;
  if (string_utils::regex_find(a_line, "H1", def_flags)) {
    return visl_tokens::visl_h1;
  };
  return visl_tokens::visl_emp;
}
#endif

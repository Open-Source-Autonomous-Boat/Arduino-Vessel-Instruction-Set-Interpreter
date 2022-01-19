#include "VISParser.h"
#include <algorithm>

#include "VISTypes.h"
#include "VISUtils.h"

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
    i = string_utils::strip_string(i, ' ');
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
    i = string_utils::strip_string(i, ' ');
  }
  // Set class property (lines) with local vector (tokens)
  this->m_lines = lines;
}

/* Parse file */
void VISParser::Parse() {
  // WIP
  for (auto &i : this->m_lines) {
    visl_cpp::tokens_type line_tokens;
    auto local_tokens = string_utils::split_string(i, ',');
    auto instruction = this->DetermineTypeFromLine(i);
    if (instruction == visl_tokens::visl_emp) {
      continue;
    }
    this->m_tokens.insert(std::pair<visl_tokens, std::string>(instruction, ""));
    for (const auto &pair : this->m_tokens) {
      std::cout << string_utils::token_stringify(instruction) << " - "
                << pair.second;
    }  // Test
  }
}

visl_tokens VISParser::DetermineTypeFromLine(std::string a_line) {
  auto line = string_utils::split_string(a_line, ' ')[0];
  auto tokens = visl_cpp::tok_strings;
  auto result = std::find_if(tokens.begin(),tokens.end(),[&](const auto &&i){
    return i->second == line;
  });
  return (result != tokens.end()) ? result->first : visl_tokens::visl_emp;
}
#endif

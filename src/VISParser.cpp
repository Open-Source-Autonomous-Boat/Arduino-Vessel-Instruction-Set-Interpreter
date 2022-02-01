#include "VISParser.h"

#include <algorithm>
#include <cctype>
#include <iterator>
#include <memory>
#include <string>

#include "VISTypes.h"
#include "VISUtils.h"

#ifndef UNICODE
#define UNICODE
#endif

#ifdef __cplusplus

VISParser::VISParser(VISLTokens* a_tokens_base){
  if (a_tokens_base->IsEmpty()) {
    this->m_tokens_base = std::make_unique<VISLTokens>();
  } else {
    std::unique_ptr<VISLTokens>temp(a_tokens_base);
    this->m_tokens_base.swap(temp);
    delete temp.release();
    temp = nullptr;
  }
};
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
  // tokens = string_utils::split_string(a_line, VISL_LINE_END);
  if (a_line.back() != VISL_LINE_END) {
    a_line += VISL_LINE_END;
  }
  for (auto &i : tokens) {
    i = string_utils::strip_string(i, VISL_DELIMITER);
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
  // Split string by VISL_DELIMITER
  lines = string_utils::split_string(line, VISL_LINE_END);
  for (auto &i : lines) {  // For each line in file...
    // Strip whitespace
    i = string_utils::strip_string(i, ' ');
    // Capitalize
    std::transform(i.begin(), i.end(), i.begin(), ::toupper);
  }
  // Set class property (lines) with local vector (tokens)
  this->m_lines = lines;
  for (auto &i : lines) {
  }
}

/* Parse file */
void VISParser::Parse() {
  std::cerr << "TEST\n";
  for (auto &i : this->m_lines) {
    auto local_tokens = string_utils::split_string(i, VISL_DELIMITER);
    auto instruction = this->m_tokens_base->GetToken(local_tokens[0]);
    if (instruction == visl_tokens::visl_emp) {
      continue;
    }
    std::vector<std::string> arguments;
    std::copy(local_tokens.begin(), local_tokens.end(),
              std::back_inserter(arguments));
    this->m_tokens.insert(std::pair<visl_tokens, std::vector<std::string>>(
        instruction, arguments));
    for (const auto &pair : this->m_tokens) {
      std::cout << this->m_tokens_base->Get(instruction).GetName() << " - "
                << string_utils::join_string(arguments, VISL_DELIMITER) << std::endl;
    }  // Test
  }
}

visl_tokens VISParser::DetermineTypeFromLine(std::string a_line) {
  auto line = string_utils::split_string(a_line, VISL_DELIMITER)[0];
  return this->m_tokens_base->GetToken(line);
}

#endif

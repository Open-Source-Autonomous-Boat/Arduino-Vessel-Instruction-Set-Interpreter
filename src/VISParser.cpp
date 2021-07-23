#include "VISParser.h"

#ifndef UNICODE
#define UNICODE
#endif

VISParser::VISParser(){};
VISParser::~VISParser() {}

/* Opens file
 * @param path: path to file
 */
void VISParser::OpenFile(std::string path) {
  // Opens file with ifstream
  this->file.open(path);
  // Strips unneeded characters and seperates lines into vector entries
  this->Prepare();
  // Parse file
  this->Parse();
  return;
}

/* Closes file */
void VISParser::CloseFile() {
  if (!this->file.is_open()) {  // If file is not opened anyway
    std::cerr << "Can't close closed file" << std::endl;
    return;
  }
  // Close file
  this->file.close();
  return;
}

/* Prepare file for parsing */
void VISParser::Prepare() {
  // Init vector of tokens
  std::vector<std::string> tokens;
  // Init empty "line" string
  std::string line;
  // For each line in file...
  for (std::string tmp; std::getline(this->file, tmp);) {
    if (tmp.rfind("#", 0) == 0) {  // Strip comments out
      /* TODO: This catches non comments */
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
  this->tokens = tokens;
}

/* Parse file */
void VISParser::Parse() {
  // WIP
  // TODO: Actually parse file
  for (auto &i : this->tokens) {
    std::cout << i << std::endl;
  }
}

void VISParser::DetermineTypeFromLine(std::vector<std::string> tokens) {}

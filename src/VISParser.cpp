#include "VISParser.h"

VISParser::VISParser(){};
VISParser::~VISParser() { delete this->file; }  // Deletes dangling pointer

/* Opens file
 * @param path: path to file
 */
void VISParser::OpenFile(std::string path) {
  // Opens file with ifstream
  this->file->open(path);
  // Sets boolean that states that file is open
  // TODO: Isn't this redundent?
  this->is_opened = true;
  // Strips unneeded characters and seperates lines into vector entries
  this->Prepare();
  // Parse file
  this->Parse();
  return;
}

/* Closes file */
void VISParser::CloseFile() {
  if (!this->is_opened && !this->file) {  // If file is not opened anyway
    std::cerr << "Can't close closed file" << std::endl;
    return;
  }
  // Close file
  this->file->close();
  // Resets bool
  this->is_opened = false;
  return;
}

/* Prepare file for parsing */
void VISParser::Prepare() {
  // Init vector of tokens
  std::vector<std::string> tokens;
  // Init empty "line" string
  std::string line;
  // For each line in file...
  for (std::string tmp; std::getline(*this->file, tmp);) {
    if (tmp.rfind("(#|//)", 0)) {  // Strip comments out
      continue;
    }
    // Concancate into string
    line += tmp;
  }
  // Split string by semi-colon (;)
  tokens = string_utils::split_string(line, ';');
  for (auto &i : tokens) {  // For each line in file...
    // Strip whitespace
    string_utils::strip_string(i, ' ');
  }
  // Set class property (tokens) with local vector (tokens)
  // TODO: Set new name
  this->tokens = tokens;
}

/* Parse file */
void VISParser::Parse() {
  // WIP
  for (auto &i : this->tokens) {
    std::cerr << i << std::endl;
  }
}

void VISParser::DetermineTypeFromLine(std::vector<std::string> tokens) {}

#include "VISCWrapper.h" /* Shouldn't the build system handle this include? */

#include <string>

#include "VISParser.h"

extern "C" {
VISParser* getVISParser() {
  /* Returns class to C struct */
  return new VISParser();
}
void VISOpenFile(VISParser* parser, char* path) {
  /* Convert to C++ readable string */
  std::string path_cpp(path);
  /* Open file with class handle */
  parser->OpenFile(path);
}

void VISCloseFile(VISParser* parser) { parser->CloseFile(); }

void delVISParser(VISParser* parser) { delete parser; }
}

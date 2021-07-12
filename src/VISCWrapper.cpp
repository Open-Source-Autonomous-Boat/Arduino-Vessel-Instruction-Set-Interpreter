#include "VISCWrapper.h" /* Shouldn't the build system handle this include? */

#include <string>

#include "VISParser.h"

extern "C" {
VISParser* getVISParser() {
  /* Returns class to C struct */
  return new VISParser();
}
void VISOpenFile(VISParser* parser, char* filename) {
  /* Convert to C++ readable string */
  std::string filename_cpp(filename);
  /* Open file with class handle */
  parser->OpenFile(filename);
}

void VISCloseFile(VISParser* parser) {
  parser->CloseFile();
}

void delVISParser(VISParser* parser) {
  delete parser;
}
}

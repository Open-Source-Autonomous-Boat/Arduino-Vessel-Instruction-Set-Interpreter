#include "../include/cwrapper.h" /* Shouldn't the build system handle this include? */

#include <string>

#include "../include/parser.h"

extern "C" {
VISLParser* getVISLParser() {
  /* Returns class to C struct */
  return new VISLParser();
}
void VISLOpenFile(VISLParser* parser, char* filename) {
  /* Convert to C++ readable string */
  std::string filename_cpp(filename);
  /* Open file with class handle */
  parser->OpenFile(filename);
}

void VISLCloseFile(VISLParser* parser) {
  parser->CloseFile();
}
}

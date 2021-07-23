#include "VISCWrapper.h" /* Shouldn't the build system handle this include? */

#include <string>

#include "VISFile.h"
#include "VISParser.h"

extern "C" {
VISParser* getVISParser() {
  /* Returns class to C struct */
  return new VISParser();
}
void VISOpenFile(VISParser* a_parser, char* path) {
  /* Convert to C++ readable string */
  std::string path_cpp(path);
  /* Open file with class handle */
  std::unique_ptr<VISFile> file(new VISFile(path_cpp));
  a_parser->OpenFile(file.release());
}

void VISCloseFile(VISParser* parser) { parser->CloseFile(); }

void delVISParser(VISParser* parser) { delete parser; }
}

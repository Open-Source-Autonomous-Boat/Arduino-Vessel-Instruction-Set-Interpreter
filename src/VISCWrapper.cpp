#include "VISCWrapper.h" /* Shouldn't the build system handle this include? */

#include <string>

#include "VISFile.h"
#include "VISParser.h"

extern "C" {
VISParser* getVISParser() {
  /* Returns class to C struct */
  return new VISParser();
}
void VISParserOpenFile(VISParser* a_parser, char* path) {
  /* Convert to C++ readable string */
  std::string path_cpp(path);
  /* Open file with class handle */
  std::unique_ptr<VISFile> file(new VISFile(path_cpp));
  a_parser->OpenFile(file.release());
}

void VISParserCloseFile(VISParser* parser) { parser->CloseFile(); }

void delVISParser(VISParser* parser) { delete parser; }

VISFile* getVISFile(char* a_path) { return new VISFile(std::string(a_path)); }

void* VISFileGetObject(VISFile* a_file) { return a_file->GetFileObject(); }

char* VISFileGetPath(VISFile* a_file) {
  // Initializes pointer to null
  char* tmpstr = nullptr;
  // Copies string (convert to c string) to char pointer
  std::strcpy(tmpstr, a_file->GetFilePath().c_str());
  // Return pointer
  return tmpstr;
}
}

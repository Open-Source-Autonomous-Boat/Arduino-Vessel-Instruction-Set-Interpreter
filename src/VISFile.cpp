#include "VISFile.h"

#ifdef __cplusplus

VISFile::VISFile(std::string a_path) {
  if (a_path == "") {
    return;
  }
  this->m_path = a_path;
#ifdef DEBUG
  std::cout << "PATH: " + this->m_path << std::endl;
#endif
  this->m_file = std::make_unique<std::fstream>(a_path);
  return;
}

VISFile::~VISFile() {
} /* idk */

std::string VISFile::GetFilePath() { return this->m_path; };
std::fstream* VISFile::GetFileObject() { return this->m_file.get(); }

#endif

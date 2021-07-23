#include "VISFile.h"

#ifdef __cplusplus

VISFile::VISFile(std::string a_path) {
  if (a_path == "") {
    return;
  }
  this->m_path = a_path;
  this->m_file->open(a_path);
  return;
}

VISFile::~VISFile() {
  if (this->m_file->is_open()) {
    this->m_file->close();
  }
  delete this->m_file.release();
}

std::string VISFile::GetFilePath() { return this->m_path; };
std::fstream* VISFile::GetFileObject() { return this->m_file.get(); }

#endif

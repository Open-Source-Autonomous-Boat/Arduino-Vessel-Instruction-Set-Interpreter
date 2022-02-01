#include "VISFile.h"
#include <fstream>
#include <memory>

#ifdef __cplusplus

VISFile::VISFile(std::string a_path) {
  if (a_path == "") {
    std::cerr << "Failed to get path!" << std::endl;
    return;
  }
  this->m_path = a_path;
  this->m_file = std::make_unique<std::fstream>(a_path);
  return;
}

VISFile::VISFile(std::fstream* a_file) {
  if (a_file == nullptr) {
    std::cerr << "Failed to get fstream!" << std::endl;
    this->m_file = std::make_unique<std::fstream>();
    return;
  }
  std::unique_ptr<std::fstream>temp(a_file);
  this->m_file.swap(temp);
  auto delete_temp = temp.release();
  delete_temp = nullptr;
  delete delete_temp;
}

VISFile::VISFile(std::unique_ptr<std::fstream>a_file) {
  if (a_file == nullptr) {
    std::cerr << "Failed to get fstream!" << std::endl;
    this->m_file = std::make_unique<std::fstream>();
    return;
  }
  std::cerr << "I am special!" << std::endl;
  this->m_file.swap(a_file);
  std::cerr << "Maybe not..." << std::endl;
  auto file_delete =  a_file.release();
  file_delete = nullptr;
  delete file_delete;
}

VISFile::~VISFile() = default; /* idk */

std::string VISFile::GetFilePath() const { return this->m_path; };
std::fstream* VISFile::GetFileObject() const { return this->m_file.get(); }

#endif

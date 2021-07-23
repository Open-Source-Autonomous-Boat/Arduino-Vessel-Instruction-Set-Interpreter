#ifndef VISFILE_H
#define VISFILE_H

#ifdef __cplusplus
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

class VISFile {
 public:
  VISFile(std::string a_path=nullptr);
  ~VISFile();
  /* Getters */
  std::string GetFilePath();
  std::fstream* GetFileObject();

 private:
  /* TODO: Should this be an ifstream instead? */
  std::string m_path;
  std::unique_ptr<std::fstream> m_file;
};
#else
typedef struct VISFile VISFile;
#endif

#endif

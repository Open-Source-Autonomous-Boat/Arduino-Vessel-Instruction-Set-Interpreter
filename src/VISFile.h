#ifndef VISFILE_H
#define VISFILE_H

#ifdef __cplusplus
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

class VISFile {
 public:
  VISFile(std::string a_path = "");
  VISFile(std::fstream* a_file = nullptr);
  VISFile(std::unique_ptr<std::fstream> a_file=nullptr);
  ~VISFile();

  bool ValidateExtension() const;
  
  /* Getters */
  std::string GetFilePath() const;
  std::fstream* GetFileObject() const;

  operator std::string() const { return this->GetFilePath(); };
  operator std::fstream*() const { return this->GetFileObject(); }

 private:
  /* TODO: Should this be an ifstream instead? */
  std::string m_path;
  std::unique_ptr<std::fstream> m_file;
  bool m_valid = false;
};
#else
typedef struct VISFile VISFile;
#endif

#endif

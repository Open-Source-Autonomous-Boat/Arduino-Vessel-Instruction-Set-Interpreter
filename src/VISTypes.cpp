#include "VISTypes.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

VISType::VISType() { this->bEmpty = true; }

VISType::VISType(std::string aSource) {
  std::copy(aSource.begin(), aSource.end(), std::back_inserter(this->mBytes));
}

VISType::VISType(char *aSource) {
  /*
    std::string stringSource = std::string(aSource);
    std::copy(stringSource.begin(), stringSource.end(), this->mBytes);
   */
  this->mBytes = std::vector<char>(
      aSource, aSource + (sizeof(aSource) / sizeof(int))); /* UNTESTED */
}

VISType::VISType(int aSource) { this->mBytes.push_back(aSource); }

VISType::VISType(float aSource) { this->mFloatBytes.push_back(aSource); }

VISType::VISType(bool aSource) { this->mBytes.push_back(aSource); }

bool VISType::isEmpty() const {
  return (this->bEmpty || (this->mBytes.empty() || this->mFloatBytes.empty()));
}

std::string VISType::toVISLString() const {
  return std::string(this->mBytes.cbegin(), this->mBytes.cend());
}

std::string VISType::toSTLString() const {
  return std::string(this->mBytes.cbegin() + 1, this->mBytes.cend() - 1);
}

/* Pointer arimethic is a PITA */

char *VISType::toSTLStringC() const {
  if (this->mBytes.empty())
    return new char[0];
  char *buffer = new char[this->mBytes.size() - 1];
  std::copy(this->mBytes.begin() + 1, this->mBytes.end() - 1, buffer);
  buffer[this->mBytes.size() - 2] = '\0';
  return buffer;
}

char *VISType::toVISLStringC() const {
  if (this->mBytes.empty())
    return new char[0];
  char *buffer = new char[this->mBytes.size() + 1];
  std::copy(this->mBytes.begin(), this->mBytes.end(), buffer);
  buffer[this->mBytes.size()] = '\0';
  return buffer;
}

int VISType::toInt() const {
  return (!this->mFloatBytes.empty()) ? (int)this->mFloatBytes.front()
                                      : (int)this->mBytes.front() - '0';
}
float VISType::toFloat() const {
  return (!this->mFloatBytes.empty()) ? this->mFloatBytes.front()
                                      : (float)this->mBytes.front() - '0';
}
bool VISType::toBool() const {
  return (!this->mFloatBytes.empty()) ? (bool)this->mFloatBytes.front()
                                      : (bool)(this->mBytes.front() - 0);
}

VISType VISType::fromVISLString(std::string aString) {
  return (aString.starts_with("\"") && aString.ends_with("\""))
             ? VISType(aString)
             : VISType();
}

VISType VISType::storeFloat(std::string aString) {
  return VISType(std::stof(aString));
}

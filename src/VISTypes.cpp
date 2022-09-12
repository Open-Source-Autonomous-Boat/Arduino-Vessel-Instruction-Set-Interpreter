#include "VISTypes.h"
#include <algorithm>
#include <string>
#include <vector>

VISTypes::VISTypes() { this->bEmpty = true; }

VISTypes::VISTypes(std::string aSource) {
  std::copy(aSource.begin(), aSource.end(), this->mBytes);
}

VISTypes::VISTypes(int aSource) { this->mBytes.push_back(aSource); }

VISTypes::VISTypes(float aSource) { this->mBytes.push_back(aSource); }

VISTypes::VISTypes(bool aSource) { this->mBytes.push_back(aSource); }

bool VISTypes::isEmpty() const {
  return (this->bEmpty || this->mBytes.empty());
}

std::string VISTypes::toVISLString() const {
  return std::string(this->mBytes.cbegin(), this->mBytes.cend());
}

std::string VISTypes::toSTLString() const {
  return std::string(this->mBytes.cbegin() + 1, this->mBytes.cend() - 1);
}

/* Pointer arimethic is a PITA */

char* VISTypes::toSTLStringC() const {
  char *buffer = new char[this->mBytes.size() - 1 ];
  std::copy(this->mBytes.begin() + 1, this->mBytes.end() - 1, buffer);
  buffer[this->mBytes.size() - 2] = '\0';
  return buffer;
}

char* VISTypes::toVISLStringC() const {
  char *buffer = new char[this->mBytes.size() + 1];
  std::copy(this->mBytes.begin(), this->mBytes.end(), buffer);
  buffer[this->mBytes.size()] = '\0';
  return buffer;
}

int VISTypes::toInt() const { return (int)(this->mBytes.front()); }
float VISTypes::toFloat() const { return (float)(this->mBytes.front()); }
bool VISTypes::toBool() const { return (bool)(this->mBytes.front()); }

VISTypes VISTypes::fromVISLString(std::string aString) {
  return (aString.starts_with("\"") && aString.ends_with("\""))
             ? VISTypes(aString)
             : VISTypes();
}

#include <string>
#include <vector>
#pragma once

class VISType {
  std::vector<char> mBytes;
  std::vector<float> mFloatBytes; /* I hate this */
  bool bEmpty;

public:
  VISType();
  VISType(std::string aSource);
  VISType(char* aSource);
  VISType(int aSource);
  VISType(float aSource);
  VISType(bool aSource);

  /* GETTER */
  bool isEmpty() const;

  /* SETTER */
  /* CONVERTER */
  /** STRING **/
  std::string toVISLString() const;
  std::string toSTLString() const;
  char* toSTLStringC() const;
  char* toVISLStringC() const;
  /** INT **/
  int toInt() const;
  /** FLOAT **/
  float toFloat() const;
  /** BOOL **/
  bool toBool() const;

  /* STATIC */
  static VISType fromVISLString(std::string aString);
  static VISType storeFloat(std::string aString);

  /* OPERATOR */
  operator std::string() { return this->toSTLString(); }
  operator int() { return this->toInt(); }
  operator float() { return this->toFloat(); }
  operator bool() { return this->toBool(); }
};

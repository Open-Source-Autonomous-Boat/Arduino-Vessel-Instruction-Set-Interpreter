#include <string>
#include <vector>
#pragma once

class VISTypes {
  std::vector<char> mBytes;
  bool bEmpty;

public:
  VISTypes();
  VISTypes(std::string aSource);
  VISTypes(int aSource);
  VISTypes(float aSource);
  VISTypes(bool aSource);

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
  static VISTypes fromVISLString(std::string aString);

  /* OPERATOR */
  operator std::string() { return this->toSTLString(); }
  operator int() { return this->toInt(); }
  operator float() { return this->toFloat(); }
  operator bool() { return this->toBool(); }
};

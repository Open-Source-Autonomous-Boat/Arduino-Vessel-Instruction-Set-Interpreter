#ifdef __cplusplus
#include <iostream>
#include <vector>
#include <array>
#include <map>
#include "utils/def_macros.h"
#endif
#pragma once

enum VISHeaderEnum {
  Mission = 0,
  Instruction = 1,
  Data = 2,
};

typedef std::array<float, 3> VISWaypoint_t;

#ifdef __cplusplus
class VISCommands {
  VISHeaderEnum mHeaderType = VISHeaderEnum::Data;
  int mNavigationMode = 0;
  std::map<int, VISWaypoint_t> mWaypoints;
  std::map<int, std::vector<std::string>> mPresets;
 public:
  VISCommands();
  /* Header */
  void setHeaderType(VISHeaderEnum aType);
  void setHeaderType(int aType);
  VISHeaderEnum getHeaderType();
  /* Instruction */
  void setNavigationMode(int aMode);
  int getNavigationMode() const;
  /* Waypoints */
  void setWaypoint(int aIndex, VISWaypoint_t aWaypoint);
  VISWaypoint_t getWaypoint(int aIndex) const;
  void removeWaypoint(int aIndex);
  /* Presets */
  void setPrefix(int aIndex, std::string aPreset);
  void setPrefix(int aIndex, std::vector<std::string> aPreset);
  std::vector<std::string> getPrefix(int aIndex) const;
  void removePrefix(int aIndex);
};
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef struct cVISCommands_s {
} cVISCommands_s;

/* Functions */
extern "C" {
  EXPORT cVISCommands_s* cVISCommands_s_new();
  EXPORT void cVISCommands_s_setHeaderType(cVISCommands_s* aData, VISHeaderEnum aHeader);
  EXPORT void cVISCommands_s_setHeaderType_raw(cVISCommands_s* aData, VISHeaderEnum aHeader);
  EXPORT void cVISCommands_s_setNavigationMode(cVISCommands_s* aData, int aMode);
  EXPORT int cVISCommands_s_getNavigationMode(cVISCommands_s* aData);
  EXPORT VISHeaderEnum cVISCommands_s_getHeaderType(cVISCommands_s* aData);
  EXPORT void cVISCommands_s_setWaypoint(cVISCommands_s* aData, int aIndex, VISWaypoint_t aWaypoint);
  EXPORT void cVISCommands_s_removeWaypoint(cVISCommands_s* aData, int aIndex);
  EXPORT void cVISCommands_s_setWaypoint_raw(cVISCommands_s* aData, int aIndex, int aWaypoint[2]);
  EXPORT void cVISCommands_s_setPrefix(cVISCommands_s* aData, int aIndex, char* aPrefix);
  EXPORT void cVISCommands_s_setPrefix_list(cVISCommands_s* aData, int aIndex, char** aPrefix, int aPrefixSize);
  EXPORT void cVISCommands_s_removePrefix(cVISCommands_s* aData, int aIndex);
  EXPORT char** cVISCommands_s_getPrefix(cVISCommands_s*, int aIndex);
}

#ifdef __cplusplus
}
#endif

#include <iostream>
#include <vector>
#include <array>
#include <map>
#pragma once

enum VISHeaderEnum {
  Mission = 0,
  Instruction = 1,
  Data = 2,
};

typedef std::array<float, 3> VISWaypoint_t;


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

#include "VISCommands.h"


VISCommands::VISCommands() {}

void VISCommands::setHeaderType(VISHeaderEnum aType) {
  this->mHeaderType = aType;
}

void VISCommands::setHeaderType(int aType) {
  this->mHeaderType = static_cast<VISHeaderEnum>(aType);
}

VISHeaderEnum VISCommands::getHeaderType() {
  return this->mHeaderType;
}

void VISCommands::setNavigationMode(int aMode) {
  this->mNavigationMode = aMode;
}
  std::vector<VISWaypoint_t> mWaypoints;

int VISCommands::getNavigationMode() const {
  return this->mNavigationMode;
}

void VISCommands::setWaypoint(int aIndex, VISWaypoint_t aWaypoint) {
  this->mWaypoints.insert({aIndex, aWaypoint});
}

VISWaypoint_t VISCommands::getWaypoint(int aIndex) const {
  return this->mWaypoints.at(aIndex);
}

void VISCommands::removeWaypoint(int aIndex) {
  this->mWaypoints.erase(aIndex);
}

void VISCommands::setPrefix(int aIndex, std::string aPreset) {
  this->mPresets.insert({aIndex, {aPreset}});
}

void VISCommands::setPrefix(int aIndex, std::vector<std::string> aPreset) {
  this->mPresets.insert({aIndex, aPreset});
}


std::vector<std::string> VISCommands::getPrefix(int aIndex) const {
  return this->mPresets.at(aIndex);
}

void VISCommands::removePrefix(int aIndex) {
  this->mPresets.erase(aIndex);
}

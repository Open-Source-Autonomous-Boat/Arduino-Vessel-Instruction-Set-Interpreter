#include "VISCommands.h"

#ifdef __cplusplus

VISCommands::VISCommands() {
}

void VISCommands::setHeaderType(VISHeaderEnum aType) {
  this->mHeaderType = aType;
}

void VISCommands::setHeaderType(int aType) {
  this->mHeaderType = static_cast<VISHeaderEnum>(aType);
}

VISHeaderEnum VISCommands::getHeaderType() { return this->mHeaderType; }

void VISCommands::setNavigationMode(int aMode) {
  this->mNavigationMode = aMode;
}

int VISCommands::getNavigationMode() const { return this->mNavigationMode; }

void VISCommands::setWaypoint(int aIndex, VISWaypoint_t aWaypoint) {
  this->mWaypoints.insert({aIndex, aWaypoint});
}

VISWaypoint_t VISCommands::getWaypoint(int aIndex) const {
  return this->mWaypoints.at(aIndex);
}

void VISCommands::removeWaypoint(int aIndex) { this->mWaypoints.erase(aIndex); }

void VISCommands::setPrefix(int aIndex, std::string aPreset) {
  this->mPresets.insert({aIndex, {aPreset}});
}

void VISCommands::setPrefix(int aIndex, std::vector<std::string> aPreset) {
  this->mPresets.insert({aIndex, aPreset});
}

std::vector<std::string> VISCommands::getPrefix(int aIndex) const {
  return this->mPresets.at(aIndex);
}

void VISCommands::removePrefix(int aIndex) { this->mPresets.erase(aIndex); }

/* C Lib */
/* Functions */
extern "C" {
  cVISCommands_s* cVISCommands_s_new() {
    return (cVISCommands_s*)(new VISCommands());
  }
 void cVISCommands_c_setHeaderType(cVISCommands_s* aData, VISHeaderEnum aHeader) {
    VISCommands* comData = (VISCommands*)aData;
    comData->setHeaderType(aHeader);
  }
  void cVISCommands_c_setHeaderType_raw(cVISCommands_s* aData, int aHeader) {
    VISCommands* comData = (VISCommands*)(aData);
    comData->setHeaderType(aHeader);
  }
  void cVISCommands_s_setNavigationMode(cVISCommands_s* aData, int aMode) {
    VISCommands* comData = (VISCommands*)(aData);
    comData->setNavigationMode(aMode);
  }
  int cVISCommands_s_getNavigationMode(cVISCommands_s* aData) {
    VISCommands* comData = (VISCommands*)(aData);
    return comData->getNavigationMode();
  }
  VISHeaderEnum cVISCommands_s_getHeaderType(cVISCommands_s* aData) {
    VISCommands* comData = (VISCommands*)(aData);
    return comData->getHeaderType();
  }
  void cVISCommands_s_setWaypoint(cVISCommands_s* aData, int aIndex, VISWaypoint_t aWaypoint) {
    VISCommands* comData = (VISCommands*)(aData);
    comData->setWaypoint(aIndex, aWaypoint);
  }
  void cVISCommands_s_setWaypoint_raw(cVISCommands_s* aData, int aIndex, int aWaypoint[2]) {
    VISCommands* comData = (VISCommands*)(aData);
    VISWaypoint_t waypoint = {aWaypoint[0], aWaypoint[1], aWaypoint[2]};
    comData->setWaypoint(aIndex, waypoint);
  }
  void cVISCommands_s_removeWaypoint(cVISCommands_s* aData, int aIndex) {
    VISCommands* comData = (VISCommands*)(aData);
    comData->removeWaypoint(aIndex);
  }
  void cVISCommands_s_setPrefix(cVISCommands_s* aData, int aIndex, char* aPrefix) {
    VISCommands* comData = (VISCommands*)(aData);
    comData->setPrefix(aIndex, aPrefix);
  }
  void cVISCommands_s_setPrefix_list(cVISCommands_s* aData, int aIndex, char** aPrefix, int aPrefixSize) {
    VISCommands* comData = (VISCommands*)(aData);
    std::vector<std::string> presets;
    for (int i = 0; i < aPrefixSize; ++i) {
      std::string newPrefix(aPrefix[i]);
      presets.push_back(newPrefix);
    }
    comData->setPrefix(aIndex, presets);
  }
  void cVISCommands_s_removePrefix(cVISCommands_s* aData, int aIndex) {
    VISCommands* comData = (VISCommands*)(aData);
    comData->removePrefix(aIndex);
  }
  char** cVISCommands_s_getPrefix(cVISCommands_s* aData, int aIndex) {
    VISCommands* comData = (VISCommands*)(aData);
    std::vector<std::string> prefixes = comData->getPrefix(aIndex);
  }
}


#endif
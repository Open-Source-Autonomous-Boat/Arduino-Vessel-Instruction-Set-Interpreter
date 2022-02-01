#pragma once
#include <array>
#ifdef __cplusplus
#include <string>

#include "VISFile.h"
#include "VISTypes.h"
#include "VISUtils.h"

extern "C" {
#endif

class VISMissionCtl {
 public:
  VISMissionCtl();

  std::vector<std::array<float, 2>> GetCoords() const;

 private:
  std::vector<std::array<float, 2>> m_coords;
};

static const VISMissionCtl MissionCtl();

#ifdef __cplusplus
}
#endif

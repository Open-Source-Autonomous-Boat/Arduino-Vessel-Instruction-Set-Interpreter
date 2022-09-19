#include "VISLexer.h"
#include "VISCommands.h"
#include "VISTypes.h"
#include "utils/string_utils.h"
#include <algorithm>
#include <functional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

VISLexer::VISLexer(VISCommands *ACommands) { this->mCommandCtrl = ACommands; }

void VISLexer::Lex(std::string aLines) {
  auto splitedString = string_utils::SplitString(aLines, ',');
  const auto argument = splitedString.front();
  std::vector<std::string> parameters(splitedString);
  parameters.erase(parameters.begin());
  if (argument == "H1") {
    auto header = VISType::storeFloat(parameters.front());
    mCommandCtrl->setHeaderType(header);
  } else if (argument == "C1") {
    auto navigation = VISType(parameters.front());
    mCommandCtrl->setNavigationMode(navigation.toInt());
  } else if (argument == "W1") {
    if (parameters.front() == "") {
      std::cerr << "Not Implemented" << std::endl;
      throw std::logic_error{"Unimplemented! (W1)"};
    }
    // int index = std::stoi(parameters.front());
    // int latitude = std::stoi(parameters.at(1));
    // int longtitude = std::stoi(parameters.at(2));
    // int radius = std::stoi(parameters.at(3));
    auto index = VISType(parameters.front());
    auto latitude = VISType(parameters.at(1));
    auto longtitude = VISType(parameters.at(2));
    auto radius = VISType(parameters.at(3));
    mCommandCtrl->setWaypoint(index, {latitude, longtitude, radius});
  } else if (argument == "W2") {
    mCommandCtrl->removeWaypoint(VISType(parameters.front()));
  } else if (argument == "D1") {
    std::vector<std::string> commands(parameters);
    commands.erase(commands.begin());
    mCommandCtrl->setPrefix(VISType(parameters.front()), commands);
  } else if (argument == "D2") {
    mCommandCtrl->removeWaypoint(VISType(parameters.front()));
  }
}

void VISLexer::Lex(std::vector<std::string> aLines) {
  for (auto &i : aLines) {
    this->Lex(i);
  }
}


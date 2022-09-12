#include "VISLexer.h"
#include "VISCommands.h"
#include <algorithm>
#include <functional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

VISLexer::VISLexer(VISCommands *ACommands) { this->mCommandCtrl = ACommands; }

void VISLexer::Lex(std::string aLines) {
  auto splitedString =
    VISLexer::SplitString(aLines, ',');
  const std::string argument = splitedString.front();
  std::vector<std::string> parameters(splitedString);
  parameters.erase(parameters.begin());
  if (argument == "H1") {
    mCommandCtrl->setHeaderType(std::stoi(parameters.front()));
  } else if (argument == "C1") {
    mCommandCtrl->setNavigationMode(std::stoi(parameters.front()));
  } else if (argument == "W1") {
    if (parameters.front() == "") {
      std::cerr << "Not Implemented" << std::endl;
      throw std::logic_error{"Unimplemented! (W1)"};
    }
    int index = std::stoi(parameters.front());
    int latitude = std::stoi(parameters.at(1));
    int longtitude = std::stoi(parameters.at(2));
    int radius = std::stoi(parameters.at(3));
    mCommandCtrl->setWaypoint(index, {latitude, longtitude, radius});
  } else if (argument == "W2") {
    mCommandCtrl->removeWaypoint(std::stoi(parameters.front()));
  } else if (argument == "D1") {
    std::vector<std::string> commands(parameters);
    commands.erase(commands.begin());
    mCommandCtrl->setPrefix(std::stoi(parameters.front()), commands);
  } else if (argument == "D2") {
    mCommandCtrl->removeWaypoint(std::stoi(parameters.front()));
  }
}

void VISLexer::Lex(std::vector<std::string> aLines) {
  for (auto &i: aLines) {
    this->Lex(i);
  }
}


std::vector<std::string> VISLexer::SplitString(std::string aLine,
                                               char aDelim) {
  std::stringstream stream(aLine);
  std::string segment;
  std::vector<std::string> output;

  while (std::getline(stream, segment, aDelim)) {
    std::cout << "segment: " << segment << std::endl;
    auto line_ending = std::string(1, VISL_LINE_ENDING);
    auto colon_pos = segment.find(line_ending);
    if (!(colon_pos == std::string::npos)) {
      segment.replace(colon_pos, line_ending.length(), "");
    }
    output.push_back(segment);
  }

  return output;
}

std::string VISLexer::FlattenString(std::vector<std::string> aLines, std::string aDelim, std::string aEOL) {
  std::stringstream stream;
  std::vector<std::string>::const_iterator it;
  for (it = aLines.cbegin(); it != aLines.end(); ++it) {
    if (std::next(it) == aLines.end()) {
      stream << *it << aEOL;
    } else {
      stream << *it << aDelim;
    }
  }
  return stream.str();
}

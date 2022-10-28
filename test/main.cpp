#include "../src/VISInterpreter.h"
#include <ios>
#include <iostream>
#include <fstream>
#include <memory>

int main(int argc, char** argv) {
  std::fstream file;
  file.open(argv[1]);
  auto interpreter = std::make_unique<VISInterpreter>(file);
  interpreter->start();
  interpreter->_DEBUG_printHeaderType();
  interpreter->_DEBUG_printNavigationType();
  file.close();
}

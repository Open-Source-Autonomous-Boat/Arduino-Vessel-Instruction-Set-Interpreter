#include "../src/VISInterpreter.h"
#include <ios>
#include <iostream>
#include <fstream>


int main(int argc, char** argv) {
  std::fstream file;
  file.open(argv[1]);
  VISInterpreter* interpreter = new VISInterpreter(file);
  interpreter->start();
  interpreter->_DEBUG_printHeaderType();
  file.close();
}

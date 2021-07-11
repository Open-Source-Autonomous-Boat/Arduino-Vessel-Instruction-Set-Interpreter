#include <fstream>
#include <ios>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#pragma once

namespace string_utils {
std::vector<std::string> split_string(std::string text, char delim);
void strip_string(std::string text, char delim);
}

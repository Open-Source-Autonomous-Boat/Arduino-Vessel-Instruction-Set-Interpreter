#include <fstream>
#include <ios>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

#include "VISTypes.h"
#pragma once

namespace string_utils {
/*
 * Splits string on deliminator
 * @param[in] text: The text to split string on
 * @param[in] delim: The deliminator to split string on
 * @return A vector containing each element of the split string
 */
std::vector<std::string> split_string(std::string text, char delim);
/*
 * Strips string of deliminator
 * @param[in,out] text: The text in where the string is stripped off
 * @param[in] delim: The deliminator to strip the string off
 * @return The stripped text
 */
void strip_string(std::string* text, char delim);
}  // namespace string_utils

namespace token_utils {
/*
 * Makes it easier to insert stuff
 * @param[in,out] tokens: The token map
 * @param[in] type: The type of the token
 * @param[in] value: The value corresponding to type
 */
template <typename T>
void map_insert(visl_cpp::tokens_type* tokens, visl_tokens type, T value);
}  // namespace token_utils

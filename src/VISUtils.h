#include <fstream>
#include <ios>
#include <iostream>
#include <iterator>
#include <ostream>
#include <regex>
#include <vector>
#include <sstream>
#include <string>

#include "VISTypes.h"
#pragma once

namespace string_utils {
/*
 * Splits string on deliminator
 * @param[in] a_text: The text to split string on
 * @param[in] a_delim: The deliminator to split string on
 * @return A vector containing each element of the split string
 */
std::vector<std::string> split_string(std::string a_text, char a_delim);
/*
 * Strips string of deliminator
 * @param[in,out] a_text: The text in where the string is stripped off
 * @param[in] a_delim: The deliminator to strip the string off
 * @return The stripped text
 */
std::string strip_string(std::string a_text, char a_delim);
/*
 * Finds regex in string, returns true if found
 * @param[in] a_text: The text to find in
 * @param[in] a_regexp: Regex Expression pls
 * @param[in] a_re_flags: Regex bitmask flags (std::regex_constants)
 * @return true or false
 */
bool regex_find(std::string a_text, std::string a_regexp,
                std::regex_constants::syntax_option_type a_re_flags);
/*
 * Finds string representation of VISL token
 * @param[in] a_token: The token to find from
 * @return string representation of token
 */
std::string token_stringify(visl_tokens a_token);
std::string join_string(std::vector<std::string> a_vector, char a_delim);
}  // namespace string_utils


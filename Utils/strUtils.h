#ifndef STRUTILS_H
#define STRUTILS_H

#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

namespace bml {

/**
 * @brief toLower : get an lowercased string
 * @param str
 * @return a lowercased string
 */
std::string toLower(const std::string& str) {
  std::string lower_str(str.size(), ' ');
  std::transform(str.begin(), str.end(), lower_str.begin(), tolower);
  return lower_str;
}

/**
 * @brief toUpper : get an uppercased string
 * @param str
 * @return an uppercased string
 */
std::string toUpper(const std::string& str) {
  std::string upper_str(str.size(), ' ');
  std::transform(str.begin(), str.end(), upper_str.begin(), toupper);
  return upper_str;
}

/**
 * @brief splitStr : split a string into a vector of string
 * @param str
 * @param sep : separator to use
 * @return a vector of strings
 */
std::vector<std::string> splitStr(const std::string str, const char sep=' ')
{
    std::string tempStr;
    std::vector<std::string> sv;
    std::stringstream iss(str);
    while (getline(iss,tempStr,sep))
        sv.push_back(tempStr);
    return sv;
}


} // Eof namespace

#endif // STRUTILS_H

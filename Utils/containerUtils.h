#ifndef CONTAINERUTILS_H
#define CONTAINERUTILS_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

namespace bml {

/**
 * @brief vec2str : a string representation of a vector
 * @param vt
 * @param sep
 * @return
 */
template <typename T>
std::string vec2str(std::vector<T> vt, const char sep=',')
{
    bool first = true;
    std::stringstream oss;
    oss << "[";
    for (T value: vt) {
        if (!first) oss << sep;
        oss << value;
        first=false;
    }
    oss << "]";
    return oss.str();
}


/**
 * @brief vecVec2str : a string representation of a vector of vectors
 * @param vvt
 * @param sep
 * @return
 */
template <typename T>
std::string vecVec2str(std::vector<std::vector<T>> vvt, const char sep=',')
{
    bool first = true;
    std::stringstream oss;
    oss << "[";
    for (std::vector<T> vt : vvt)
    {
        if (!first) oss << sep;
        oss << std::endl << " " << vec2str(vt);
        first=false;
    }
    oss << std::endl << "]";
    return oss.str();
}

/**
 * @brief longestInVec : longest string representation of items in a vector
 * @param vt
 * @return
 */
template<typename T>
std::size_t longestInVec(std::vector<T> vt)
{
    std::size_t l;
    std::size_t longest = 0;
    for (T val: vt)
    {
        std::stringstream tss;
        tss << val;
        l = tss.str().length();
        if (l>longest) longest=l;
    }
    return longest;
}

/**
 * @brief longestInVecVec : longest string representation of items in a vector of vectors
 * @param vvt
 * @return
 */
template<typename T>
std::size_t longestInVecVec(std::vector<std::vector<T>> vvt)
{
    std::size_t l;
    std::size_t longest = 0;
    for (std::vector<T> vt: vvt)
    {
        l = longestInVec(vt);
        if (l>longest) longest=l;
    }
    return longest;
}



} // Eof namespace

#endif // CONTAINERUTILS_H

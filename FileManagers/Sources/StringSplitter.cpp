//
// Created by gunther on 24/11/20.
//

#include "../Headers/StringSplitter.h"

//Split System
std::vector<std::string> StringSplitter::splitString(const std::string &str, const std::string &delim) {

    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

//Type Conversion
string *StringSplitter::toString(int num) {


    string* string1 = new string();
    string1->append(to_string(num));

    return string1;
}
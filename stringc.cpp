#include <algorithm>
#include <string>
#include "stringc.h"

int compareInsensitive(std::string s1, std::string s2) {
  // convert s1 and s2 to lowercase
  transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
  transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
  // compare string s1 with string s2
  return s1.compare(s2);
};

size_t findInsensitive(std::string s1, std::string s2) {
  // convert s1 and s2 to lowercase
  transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
  transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
  // find substring s2 in string s1
  return s1.find(s2);
};

void ltrim(std::string &str) {
  // erase whitespaces from the left
  str.erase(0, str.find_first_not_of("\t\n\v\f\r "));
};

void rtrim(std::string &str) {
  // erase whitespaces from the right
  str.erase(str.find_last_not_of("\t\n\v\f\r ") + 1);
};

void trim(std::string &str) {
  // erase whitespaces both sides
  ltrim(str);
  rtrim(str);
};

std::string truncate(std::string str, int length, bool ellipsis) {
  if (str.length() > length) {
    if (ellipsis)
      return str.substr(0, length - 3) += "...";
    else
      return str.substr(0, length);
  };
  return str;
};

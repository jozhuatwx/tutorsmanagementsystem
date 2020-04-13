#pragma once
#include <string>

int compareInsensitive(std::string s1, std::string s2);
size_t findInsensitive(std::string s1, std::string s2);

void ltrim(std::string &str);
void rtrim(std::string &str);
void trim(std::string &str);

std::string truncate(std::string str, int length, bool ellipsis = true);

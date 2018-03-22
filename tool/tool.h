#ifndef TOOL_H
#define TOOL_H

#include<string>
#include<vector>
#include<iostream>
#include<cctype>

FILE* shell(std::string cmd);
void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c);
bool isalnum(const std::string& s);

#endif

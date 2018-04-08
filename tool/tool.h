#ifndef TOOL_H
#define TOOL_H

#include<string>
#include<vector>
#include<iostream>
#include<cctype>
#include<stdio.h>

FILE* shell(std::string cmd);
void shellResultToVector(FILE* shellResult, std::vector<std::string>& v);
void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c);
bool isalnum(const std::string& s);

#endif

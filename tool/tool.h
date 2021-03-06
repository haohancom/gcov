#ifndef TOOL_H
#define TOOL_H

#include<string>
#include<vector>
#include<iostream>
#include<cctype>
#include<stdio.h>
#include<sstream>

FILE* shell(std::string cmd);
void shellResultToVector(FILE* shellResult, std::vector<std::string>& v);
void splitString(const std::string& s, std::vector<std::string>& v, const std::string& c);
bool isnum(const std::string& s);
void str2int(const std::string &s, int &i);
template<typename T>
void showVec(std::vector<T> const&v){
    for (typename std::vector<T>::const_iterator i = v.begin(); v.end() != i; ++i){
        std::cout << *i << std::endl;
    }
}
#endif

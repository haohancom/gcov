#include<iostream>
#include"tool/tool.h"
using namespace std;

void res2int(vector<string> vDiffReslut, vector<int> &vChangedLine){
    bool begin = 0;
    bool end = 0;
    string str = "";
    string sPos = "";
    int iPos = 0;
    vector<string>::iterator it = vDiffReslut.begin();
    while(vDiffReslut.end() != it){
        str = *it;
        if('@' == str[0] && '@' == str[1]){
            begin = 1;
            end = 0;

            std::size_t pos1= str.find("+");
            std::size_t pos2= str.find(",", pos1 + 1);
            sPos = str.substr(pos1 + 1, pos2 - pos1 - 1);
            str2int(sPos, iPos);

            //now iPos saves the begin position of changed code
        }

        ++it;
    }
}

int main(){
    vector<string> vDiffReslut;;   
    shellResultToVector(shell("git diff"), vDiffReslut);

    //analyse vDiffReslut
    vector<int> vChangedLine;
    res2int(vDiffReslut, vChangedLine);
    return 0;
}

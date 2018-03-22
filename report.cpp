#include<iostream>
#include<string>
#include<fstream>
#include"tool/tool.h"
using namespace std;

bool bLineNum(const string &s){
    std::size_t found = s.find("lineNum");
    if (string::npos != found){
        return 1;
    }
    return 0;
}

bool bLineCov(const string &s){
    std::size_t found = s.find("lineCov");
    if (string::npos != found){
        return 1;
    }
    return 0;
}

int main(){
    const int max_buffer = 256;
    char buffer[max_buffer];
    string sInFileName = "lineInfo";
    string sOutFileName = "coverageReport";
    string sL = "";
    string sR = "";
    ifstream in(sInFileName, ios::in);
    ofstream out(sOutFileName, ios::out|ios::trunc);

    if (!in.is_open() || !out.is_open()){
        cout << "open file error, exit !" << endl;
        return 1;
    }

    FILE *fShellResult = shell("ls | grep " + sInFileName);
    if (NULL == fShellResult){
        cout << "target file does not exist , exit !" << endl;
        return 1;
    }

    while (!in.eof()){
        in.getline(buffer, 100);
        string s = buffer;
        if (bLineNum(s)){
           sL = s;
        }
        else if (bLineCov(s)){
            sR = s;
            out << sL << " " << sR << endl;
        }
    }
    out.close();
    return 0;
}

/*************************************************************************
	> File Name: infoCatchTool.cpp
	> Author: hanhao
	> Mail: hanhao@cisco.com
	> Created Time: 2018年03月05日 星期一 21时18分29秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<fstream>
using namespace std;

void getInfo(vector<string> &v){
    string s;
    while (cin >> s){
        v.push_back(s);
        s = "";
    }
}

void printVector(vector<string> v){
    cout << "print info in v : "<<endl;
    auto i = v.begin();
    while (v.end() != i){
        cout << *i << endl;
        ++i;
    }
    cout << "print over! " << endl;
}

const char* string2char(string s){
    shared_ptr<string> p(new string(s));
    return p->c_str();
}

void getFilename(string &sFilename, const vector<string> &v){
    auto i = v.end() - 1;
    sFilename = *i;
    cout << "filename is : " << sFilename << endl;
}

bool searchStrInLine(vector<string> v, string sLine){
    auto i = v.begin();
    while(v.end() - 1 != i){
        if(string::npos == sLine.find(*i)){
            return 0;
        } 
        ++i;
    }
    return 1;
}

int main(){
    vector<string> vInfo;
    getInfo(vInfo);
    // At least 2 string; 
    // the last one is name of the file which you want to search in;

    string sFilename = "";
    getFilename(sFilename, vInfo);
    // got filename

    ifstream file;
    file.open(sFilename, ios::in);
    if(!file.is_open()){
        cout << "file open error ! " << endl;
        return 0;
    }
    string sLine = "";
    while(getline(file, sLine)){
        if(searchStrInLine(vInfo, sLine)){
            cout << sLine << endl;
        }
    }
    return 0;
}

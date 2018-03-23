#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<fstream>
using namespace std;

void getInfo(vector<string> &v, char** argv){
    string s = "";
    int index = 1;
    while (NULL != argv[index]){
        s = argv[index];
        v.push_back(s);
        s = "";
        ++index;
    }
}

void printVector(vector<string> v){
    cout << "print info in v : "<<endl;
    vector<string>::iterator i = v.begin();
    while (v.end() != i){
        cout << *i << endl;
        ++i;
    }
    cout << "print over! " << endl;
}

const char* string2char(string s){
    auto_ptr<string> p(new string(s));
    return p->c_str();
}

void getFilename(string &sFilename, vector<string> &v){
    vector<string>::iterator i = v.end() - 1;
    sFilename = *i;
    cout << "filename is : " << sFilename << endl;
}

bool searchStrInLine(vector<string> v, string sLine){
    vector<string>::iterator i = v.begin();
    while (v.end() - 1 != i){
        if (string::npos == sLine.find(*i)){
            return 0;
        } 
        ++i;
    }
    return 1;
}

int main(int argc, char** argv){
    vector<string> vInfo;
    getInfo(vInfo, argv);
    // At least 2 string; 
    // the last one is name of the file which you want to search in;

    string sFilename = "";
    getFilename(sFilename, vInfo);

    ifstream file;
    file.open(sFilename.c_str(), ios::in);
    if (!file.is_open()){
        cout << "file open error ! " << endl;
        return 0;
    }
    string sLine = "";
    while (getline(file, sLine)){
        if (searchStrInLine(vInfo, sLine)){
            cout << sLine << endl;
        }
    }
    return 0;
}

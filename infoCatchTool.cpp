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

int main(){
    vector<string> vInfo;
    cout << "Please input vector" << endl;
    getInfo(vInfo);
    printVector(vInfo);
    return 0;
}

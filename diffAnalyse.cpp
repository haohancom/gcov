#include<iostream>
#include"tool/tool.h"
using namespace std;

class result{
public:
    static result& instance(vector<string>::const_iterator it){
        static result RESULT(it);
        return RESULT;
    }

    void nextit() {++it;}
    void it2str() {str = *it;}
    void showit() {cout << *it << endl;}
    const char str0() const {return str[0];}
    bool getBegin() {return begin;}
    vector<string>::const_iterator getIt() {return it;}
    vector<int> getVecInt() {return vChangedLine;}

    void End();
    void Begin();
    void Normal();
    void Add();
    void Minus();

private:
    bool begin = 0;
    string str = "";
    string sPos = "";
    int iPos = 0;
    vector<string>::const_iterator it ;
    vector<int> vChangedLine;

    result(vector<string>::const_iterator it){
        this->it = it;
    }

    result(result const&);
    result& operator=(result const&);
    ~result() {vector<int>().swap(vChangedLine);}
};

void result::End(){
    begin = 0;
    iPos = 0;
}

void result::Begin(){
    begin = 1;
    std::size_t pos1 = str.find("+");
    std::size_t pos2 = str.find(",", pos1 + 1);
    sPos = str.substr(pos1 + 1, pos2 - pos1 - 1);
    str2int(sPos, iPos);
    --iPos;
}

void result::Normal(){
    ++iPos;   
}

void result::Add(){
    ++iPos;
    vChangedLine.push_back(iPos);
}

void result::Minus(){
    //do nothing
}

void whileLoop(result &r, vector<string>::const_iterator endIt){
    while (endIt != r.getIt()){
        r.it2str();

        //diff --git a/fileName b/fileName
        if ('d' == r.str0()) r.End();

        //@@ -beginLocation, length +beginLocation, length @@xxxxxx
        if ('@' == r.str0()) r.Begin();

        //normal line
        if (' ' == r.str0()) r.Normal();

        //+ xxxxxx
        if (r.getBegin() && '+' == r.str0()) r.Add();

        //- xxxxxx
        if (r.getBegin() && '-' == r.str0()) r.Minus();

        r.nextit();
    }
    showVec(r.getVecInt());
}

int main(){
    vector<string> vDiffReslut;
    shellResultToVector(shell("git diff"), vDiffReslut);
    vector<string>::const_iterator it = vDiffReslut.begin();
    whileLoop(result::instance(it), static_cast<vector<string>::const_iterator>(vDiffReslut.end()));
    return 0;
}

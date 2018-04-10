#include<iostream>
#include"tool/tool.h"
using namespace std;

void res2int(vector<string> vDiffReslut, vector<int> &vChangedLine){
    bool begin = 0;
    string str = "";
    string sPos = "";
    int iPos = 0;
    vector<string>::iterator it = vDiffReslut.begin();
    while(vDiffReslut.end() != it){
        str = *it;

        //diff --git a/fileName b/fileName
        if ('d' == str[0]){
            begin = 0;
            iPos = 0;
        }

        //@@ -beginLocation, length +beginLocation, length @@xxxxxx
        if ('@' == str[0] && '@' == str[1]){
            begin = 1;

            std::size_t pos1 = str.find("+");
            std::size_t pos2 = str.find(",", pos1 + 1);
            sPos = str.substr(pos1 + 1, pos2 - pos1 - 1);
            str2int(sPos, iPos);
            --iPos; //now iPos saves the begin position of changed code
        }

        //normal line
        if (' ' == str[0]){
            ++iPos;
        }

        //+ xxxxxx
        if (begin && '+' == str[0]){
            ++iPos;
            vChangedLine.push_back(iPos);
        }

        //- xxxxxx
        if (begin && '-' == str[0]){
            //do nothing
        }
        ++it;
    }
}

class result{
public:
    static result& instance(vector<string>::const_iterator it){
        static result RESULT(it);
        return RESULT;
    }

    void nextit() {++it;}
    void it2str() {str = *it;}
    const char str0() const {return str[0];}

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
    ~result();
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

int main(){
    vector<string> vDiffReslut;;   
    shellResultToVector(shell("git diff"), vDiffReslut);

    //analyse vDiffReslut
    vector<int> vChangedLine;
    res2int(vDiffReslut, vChangedLine);

    showVec(vChangedLine);
    return 0;
}

#include"tool.h"

FILE* shell(std::string cmd){
    FILE* stream;
    cmd.append(" 2>&1");

    stream = popen(cmd.c_str(), "r");
    return stream;
}

void shellResultToVector(FILE* stream, std::vector<std::string>& v){
    const int max_buffer = 256;
    char buffer[max_buffer];

    if(stream){
        while(!feof(stream)){
            if(NULL != fgets(buffer, max_buffer, stream)){
                v.push_back(buffer);
            } 
        }
        pclose(stream);
    }
    else{
        std::cout << "ERROE: STREAM IS NULL, EXIT THIS FUNCTION !";
        return;
    }
}

void splitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (std::string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);

    }
    if (s.length() != pos1)
    v.push_back(s.substr(pos1));
}

bool isnum(const std::string& s){
    if (0 == s.length()) return 0;

    bool result = 1;
    for (int i = 0; i < s.length(); ++i){
        if (0 == std::isdigit(s[i])){
            result = 0;
        }
    }
    return result;
}

void str2int(const std::string &s, int &i){
    std::stringstream(s) >> i;
}

template<typename T>
void showVec(std::vector<T> v){
    for (typename std::vector<T>::const_iterator i = v.begin(); v.end() != i; ++i){
        std::cout << *i << std::endl;
    }
}


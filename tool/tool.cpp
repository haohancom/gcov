#include"tool.h"

FILE* shell(std::string cmd){
    FILE* stream;
    cmd.append(" 2>&1");

    stream = popen(cmd.c_str(), "r");
    return stream;
}

void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
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

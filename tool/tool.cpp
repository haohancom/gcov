#include"tool.h"

FILE* shell(std::string cmd){
    FILE* stream;
    cmd.append(" 2>&1");

    stream = popen(cmd.c_str(), "r");
    return stream;
}

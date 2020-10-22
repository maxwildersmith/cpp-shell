#include "shell.h"

string cp(string input){
    int space_index = input.substr(3).find_first_of(' ');
    string src = input.substr(3, space_index);
    string target = input.substr(space_index+4);
    filesystem::copy(src, target);

    return "";
}
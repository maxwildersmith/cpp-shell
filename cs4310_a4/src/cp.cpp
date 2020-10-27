#include "shell.h"

string cp(string input){
    int space_index = input.find_first_of(' ');
    string src = input.substr(0, space_index);
    string target = input.substr(space_index+1);
    filesystem::copy(src, target);

    return "";
}
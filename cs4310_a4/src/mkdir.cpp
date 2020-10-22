#include "shell.h"

string mkdir(string input){
    if( !filesystem::create_directory(input) )
        return "mkdir: cannot create directory '" + input + "': File exists";
    return "";
}
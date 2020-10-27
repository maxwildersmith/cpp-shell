#include "shell.h"

string mkdir(string input){
    if( !filesystem::create_directory(cwd+'/'+input) )
        return "mkdir: cannot create directory '" + input + "': File exists";
    return "";
}
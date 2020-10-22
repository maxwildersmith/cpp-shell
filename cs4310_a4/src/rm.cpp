#include "shell.h"

string rm(string input){
    string path = cwd;
    if (input.at(0) == '/') {
        path = "";
    }
    path = cwd +"/"+ input;
    if( filesystem::is_directory(path) )
        return "rm: cannot remove '"+input+"': Is a directory";
    else if( !filesystem::remove(path) )
        return "rm: failed to remove '"+input+"': No such file or directory";

    return "";
}
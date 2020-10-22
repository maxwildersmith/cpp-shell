#include "shell.h"

string rmdir(string input){
    if( !filesystem::is_directory(input))
        return "rmdir: failed to remove '"+input+"': Not a directory";
    else if (!filesystem::is_empty(input))
        return "rmdir: failed to remove '"+input+"': Directory not empty";
    else if( !filesystem::remove(input) )
        return "rmdir: failed to remove '"+input+"': No such file or directory";

    return "";
}
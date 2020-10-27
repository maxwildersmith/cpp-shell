#include "shell.h"

string rdir(string input){
    if( !filesystem::is_directory(cwd+'/'+input))
        return "rmdir: failed to remove '"+input+"': Not a directory";
    else if (!filesystem::is_empty(cwd+'/'+input))
        return "rmdir: failed to remove '"+input+"': Directory not empty";
    else if( !filesystem::remove(cwd+'/'+input) )
        return "rmdir: failed to remove '"+input+"': No such file or directory";

    return "";
}
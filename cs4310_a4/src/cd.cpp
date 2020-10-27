#include "shell.h"

string cd(string input){
    string temp;
    string path = input;
    if(path.substr(0,2).compare("..") == 0){
        cwd = cwd.substr(0,cwd.find_last_of('/'));
        path = path.substr(2);
        
    } else if (path.at(0) == '/') {
        if (filesystem::exists(path) == 0)
            return "Invalid file path";
        cwd = path;
        return "";
    }
    if(path.length() > 0)
        temp = cwd + "/" + path;
    else   
        temp = cwd;
    if (filesystem::exists(temp) == 0)
        return "Invalid file path";
    cwd = temp;
    cwd = filesystem::path(cwd).lexically_normal();
    
    return "";
}
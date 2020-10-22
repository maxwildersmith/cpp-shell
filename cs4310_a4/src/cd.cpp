#include "shell.h"

/**
 * Needs to check if the path is valid, if theres multiple paths, or nothing there
 * 
 */
string cd(string input){
    string path = input.substr(3);
    if(path.substr(0,2).compare("..") == 0){
        cwd = cwd.substr(0,cwd.find_last_of('/'));
        path = path.substr(2);
    } else if (path.at(0) == '/') {
        cwd = path;
        return "";
    }
    if(path.length() > 0)
        cwd += "/" + path;
    cwd = filesystem::path(cwd).lexically_normal();

    // Return error string if it doesnt work
    return "";
}
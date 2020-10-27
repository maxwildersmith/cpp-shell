#include "shell.h"

string entry_to_filename(filesystem::directory_entry entry){
    string name = entry.path().filename().string();
    if(name.find(' ') != string::npos)
        name = "'"+name+"'";
    if(filesystem::is_directory(entry.path()))
        name += '/';
    return name;
}

string ls(string input){
    string path = cwd;
    string output = "";
    if(input.length() > 3){
        path = input.substr(3);
        if (filesystem::exists(path) == 0)
            return "Invalid file path";
    }

    for( auto& entry: filesystem::directory_iterator(path))
        output += entry_to_filename(entry) + ' ';
    
    return output;
}
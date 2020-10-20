#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include<unistd.h>
#include<filesystem>

using namespace std;

bool valid_path(string path){
    return filesystem::exists(path);
}

string entry_to_filename(filesystem::directory_entry entry){
    string name = entry.path().filename().string();
    if(name.find(' ') != string::npos)
        name = "'"+name+"'";
    return name;
}

int main(){
    string promptStr = getenv("USER");
    char hostname[512];
    gethostname(hostname, sizeof hostname);
    promptStr += "@" + string(hostname) + ":";

    string cwd = filesystem::current_path().string();

    string input;

    do{
        cout << promptStr << cwd << "$ ";
        getline(cin,input);
        
        int spacePos = input.find(' ');
        if( input.compare(0, spacePos, "cd") == 0 )
        {
            string path = input.substr(3);
            if(path.substr(0,2).compare("..") == 0){
                cwd = cwd.substr(0,cwd.find_last_of('/'));
                path = path.substr(2);
            } else if (path.at(0) == '/') {
                cwd = path;
                continue;
            }
            if(path.length() > 0)
                cwd += "/" + path;
            cwd = filesystem::path(cwd).lexically_normal();

        } else if( input.compare(0, spacePos, "pwd") == 0 )
        {
            cout << cwd << endl;
        } else if( input.compare(0, spacePos, "mkdir") == 0 )
        {
            //TODO

        } else if( input.compare(0, spacePos, "rmdir") == 0 )
        {
            //TODO

        } else if( input.compare(0, spacePos, "ls") == 0 )
        {
            
            string path = cwd;
            if(input.length() > 3){
                path = input.substr(3);
            }

            for( auto& entry: filesystem::directory_iterator(path))
                cout << entry_to_filename(entry) << ' ';
            cout << endl;

        } else if( input.compare(0, spacePos, "cp") == 0 )
        {

            int space_index = input.substr(3).find_first_of(' ');
            string src = input.substr(3, space_index);
            string target = input.substr(space_index+4);
            filesystem::copy(src, target);

        } else if( input.find("./") == 0) 
        {
            //TODO
            cout << "executing: " << input.substr(2)<<endl;
        } else {
            cout << "Command '"<<input<<"' not found."<<endl;
        }
    } while (input.compare("exit") != 0);
}
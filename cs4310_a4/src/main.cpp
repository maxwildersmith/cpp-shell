#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include<unistd.h>
#include<filesystem>

using namespace std;


int main(){
    string promptStr = getenv("USER");
    char hostname[512];
    gethostname(hostname, sizeof hostname);
    promptStr += "@" + string(hostname) + ":";

    string cwd = filesystem::current_path().string();

    string input;
    do{
        cout << promptStr << cwd << '$';
        getline(cin,input);
        
        int spacePos = input.find(' ');
        if( input.compare(0, spacePos, "cd") == 0 ){

        } else if( input.compare(0, spacePos, "pwd") == 0 ){
            cout << cwd << endl;
        } else if( input.compare(0, spacePos, "mkdir") == 0 ){

        } else if( input.compare(0, spacePos, "rmdir") == 0 ){

        } else if( input.compare(0, spacePos, "ls") == 0 ){

        } else if( input.compare(0, spacePos, "cp") == 0 ){

        } else if( input.find("./") == 0) {

        }
    } while (input.compare("exit") != 0);
}
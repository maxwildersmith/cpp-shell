#include "shell.h"

using namespace std;

bool valid_path(string path){
    return filesystem::exists(path);
}

string cwd;

int main(){

    cwd = filesystem::current_path().string();

    string promptStr = get_prompt_string();

    string input;

    do{
        cout << promptStr << cwd << "$ ";
        getline(cin,input);
        
        int spacePos = input.find(' ');
        if (input.find(" | ") != string::npos)
        {
            cout << piping(input) << endl;
        }
        else if( input.compare(0, spacePos, "cd") == 0 )
        {
            cout << cd(input) << endl;

        } else if( input.compare(0, spacePos, "pwd") == 0 )
        {
            cout << cwd << endl;

        } else if( input.compare(0, spacePos, "rm") == 0 )
        {
            cout << rm(input.substr(3)) << endl;

        } else if( input.compare(0, spacePos, "mkdir") == 0 )
        {
            
            cout << mkdir(input.substr(6)) << endl;

        } else if( input.compare(0, spacePos, "rmdir") == 0 )
        {
            
            cout << rmdir(input.substr(6)) << endl;

        } else if( input.compare(0, spacePos, "ls") == 0 )
        {
            
            cout << ls(input) << endl;

        } else if( input.compare(0, spacePos, "cp") == 0 )
        {

            cout << cp(input) << endl;

        } else if( input.find("./") == 0) 
        {
            
            cout << execute(input.substr(2)) << endl;
        
        } else if( input.compare("exit") != 0)
        {

            cout << "Command '" << input << "' not found." << endl;
        }
    } while (input.compare("exit") != 0);
}
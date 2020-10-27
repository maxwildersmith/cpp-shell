#include "shell.h"

bool valid_path(string path){
    return filesystem::exists(path);
}

string cwd;

int main(){

    cwd = filesystem::current_path().string();

    string promptStr = get_prompt_string();

    string input, output;

    do{
        output = "";
        cout << promptStr << cwd << "$ ";
        getline(cin,input);
        
        int spacePos = input.find(' ');
        try{
            if (input.find(" | ") != string::npos)
            {
                output = piping(input);
            }
            else if( input.compare(0, spacePos, "cd") == 0 )
            {
                output = cd(input.substr(3));

            } else if( input.compare(0, spacePos, "pwd") == 0 )
            {
                output = cwd;

            } else if( input.compare(0, spacePos, "rm") == 0 )
            {
                output = rm(input.substr(3));

            } else if( input.compare(0, spacePos, "mkdir") == 0 )
            {
                output = mkdir(input.substr(6));

            } else if( input.compare(0, spacePos, "rmdir") == 0 )
            {
            output = rdir(input.substr(6));

            } else if( input.compare(0, spacePos, "ls") == 0 )
            {
                output = ls(input);

            } else if( input.compare(0, spacePos, "cp") == 0 )
            {
                output = cp(input.substr(3));

            } else if( input.find("./") == 0) 
            {
                output = execute(input.substr(2));
            
            } else if( input.compare("exit") != 0)
            {
                output = "Command '" + input + "' not found.";
            }
        } catch (...) {
            output = "Incorrect usage of the command, check the number of arguments.";
        }

        if(output.length() > 0)
            cout << output << endl;

    } while (input.compare("exit") != 0);
}
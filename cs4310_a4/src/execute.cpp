#include "shell.h"

string execute(string input){
    string path = cwd + "/" + input;
    pid_t pid = fork();
    if(pid == 0)
    {
        if (execlp(path.c_str(), input.c_str(), NULL) < 0)
            cout << "Failed to execute process '" << input << "'" << endl;
    }
    else
    {
        wait(NULL);
    }
    return "";
}
#include "shell.h"

string piping(string input){
    string str1, str2, path1, path2;
    int pos = input.find(" | ");
    int pipefiledesc[2];
    pid_t pid1, pid2;

    str1 = input.substr(0, pos);
    str2 = input.substr(pos + 3);
    path1 = cwd + '/' + str1;
    path2 = cwd + '/' + str2;

    pipe(pipefiledesc);
    pid1 = fork();
    if (pid1 == 0)
    {
        close(pipefiledesc[0]);
        dup2(pipefiledesc[1], STDOUT_FILENO);
        close(pipefiledesc[1]);
        if (execlp(path1.c_str(), str1.c_str(), NULL) < 0)
            cout << "Failed to execute process '" << str1 << "'" << endl;
    }
    else
    {
        pid2 = fork();
        if (pid2 == 0)
        {
            close(pipefiledesc[1]);
            dup2(pipefiledesc[0], STDIN_FILENO);
            close(pipefiledesc[0]);
            if (execlp(path2.c_str(), str2.c_str(), NULL) < 0)
                cout << "Failed to execute process '" << str2 << "'" << endl;
        }
        else
        {
            wait(NULL);
            wait(NULL);
        }
    }
    return "";
}
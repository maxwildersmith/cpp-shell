#include "shell.h"


string get_prompt_string(){
    string promptStr = getenv("USER");
    char hostname[512];
    gethostname(hostname, sizeof hostname);
    promptStr += "@" + string(hostname) + ":";
    return promptStr;
}
#ifndef __shell_h__
#define __shell_h__

#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include<unistd.h>
#include<filesystem>

using namespace std;

extern string cwd;

string get_prompt_string();

string cd(string input);

string ls(string input);

string cp(string input);

string mkdir(string input);

string rmdir(string input);

string execute(string input);

string rm(string input);

#endif
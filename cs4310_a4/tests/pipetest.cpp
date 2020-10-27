#include<iostream>
#include<string>

using namespace std;

int main(){
    string input;
    getline(cin, input);

    cout << "Data passed through the pipe: '" << input << "'" << endl;
    cout << "Pipe test passed!" << endl;
}
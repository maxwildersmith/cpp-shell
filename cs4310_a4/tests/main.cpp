#include "../src/shell.h"
#include <cassert>

string cwd;

int main(){

    cwd = filesystem::current_path().string();

    assert( mkdir("testDir").length() == 0);
    cout << "Make directory passed" << endl;
    
    assert( mkdir("testDir").length() != 0);
    cout << "Directory exists check passed" << endl;
    
    assert( cd("testDir").length() == 0);
    cout << "Change directory passed" << endl;
    
    assert( ls("").length() == 0);
    cout << "List empty directory passed" << endl;

    assert( ls("/").length() == 0);
    cout << "List non-empty path-specified directory passed" << endl;

    assert( cd("..").length() == 0);
    cout << "Move to parent directory passed" << endl;

    assert( cp("test.out testDir/test.out").length() == 0);
    cout << "Copy file passed" << endl;

    assert( rdir("testDir").length() != 0);
    cout << "Non-empty directory delete passed" << endl;

    assert( rm("testDir/test.out").length() == 0);
    cout << "Delete file passed" << endl;

    assert( rdir("testDir").length() == 0);
    cout << "Empty directory delete passed" << endl;

    cd("tests");
    
    assert( execute("extest").length() == 0);
    cout << "Execution of file passed" << endl;

    assert( piping("./extest | pipetest").length() == 0);
    cout << "Piping test passed" << endl;

    cout << endl << "Passed all test cases" <<endl;
    return 0;
}
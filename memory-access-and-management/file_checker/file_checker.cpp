#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool filesAreEqual(string filenameA, string filenameB) {
    ifstream fileA(filenameA.c_str());
    ifstream fileB(filenameB.c_str());
    
    while (fileA || fileB) {
        string aLine;
        getline(fileA, aLine);

        string bLine;
        getline(fileB, bLine);

        if (aLine != bLine) {
            cout << aLine << " != " << bLine << endl;
            return false;
        }
    }

    return true;
}

int main() {
    string firstFileName, secondFileName;
    cout << "This program lets you compare two files!" << endl;
    cout << "Please enter the first file's name: " << endl;
    cin >> firstFileName;
    cout << "Please enter the second file's name: " << endl;
    cin >> secondFileName;

    cout << "Files are " << (filesAreEqual(firstFileName, secondFileName) ? "equal" : "not equal") << endl;
    return 0;
}
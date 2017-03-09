#include <iostream>
#include <string>

using namespace std;

void findAndReplace(string& text, string findStr, string replaceStr) {
    int substrIndex = text.find(findStr);

    while (substrIndex != string::npos) {
        // Replace while it is a valid index
        text.replace(substrIndex, findStr.size(), replaceStr);
        substrIndex = text.find(findStr);
    }

}

int main() {
    string text, findStr, replaceStr;
    cout << "Enter the text: " << endl;
    getline(cin, text);
    cout << "Enter the string you want to be replace" << endl;
    getline(cin, findStr);
    cout << "Enter the string you want to take its place" << endl;
    getline(cin, replaceStr);

    findAndReplace(text, findStr, replaceStr);

    cout << text << endl;
    return 0;
}

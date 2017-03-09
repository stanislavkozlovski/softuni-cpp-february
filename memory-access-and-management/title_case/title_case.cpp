#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;


void makeTitleCase(string& text) {
    bool lastLetterIsAlpha = false;
    for (int i = 0; i < text.size(); i++)
    {
        char character = text[i];
        if (isalpha(character)) {
            if (!lastLetterIsAlpha) {
                // modify it to upper case
                text[i] = toupper(text[i]);
            }
            lastLetterIsAlpha = true;
        } else {
            lastLetterIsAlpha = false;
        }
    }
}

int main() {
    string sentence;
    cout << "Enter your string" << endl;
    getline(cin, sentence);

    makeTitleCase(sentence);

    cout << sentence << endl;
    return 0;
}
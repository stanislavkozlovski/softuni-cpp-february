#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <ctype.h>


void paste(std::string& text, int clipboardIndex, int pasteIndex, std::vector<std::string> clipboard) {
    std::string pasteString = clipboard[clipboardIndex];
    text.insert(pasteIndex, clipboard[clipboardIndex].c_str());
}

void copyToClipboard(int startIndex, int endIndex, const std::string& text, std::vector<std::string> &clipboard, int& clipboardLen) {
    
    // find the appropriate start and end index
    while (isalpha(text[startIndex]) && startIndex > 0) {
        startIndex--;
    }
    while (isalpha(text[endIndex]) && (endIndex < (text.size() - 1))) {
        endIndex++;
    }

    // get the words from the index
    std::stringstream ss;
    ss << text.substr(startIndex, ((endIndex + 1) - startIndex));

    std::string currentWord;
    while (ss >> currentWord) {
        clipboard.push_back(currentWord);
    }
}

int main() {
    // std::string text = "The following tasks should be submitted to the SoftUni Judge etc etc";
    int n;
    
    std::string text;
    getline(std::cin, text);

    std::cin >> n;

    /// copy 10 20
    /// paste 0 1
    std::vector<std::string> clipboard;
    int clipboardSize = 0;
    for (int i = 0; i < n; i++) {
        std::string command;
        int idx_1, idx_2;
        std::cin >> command >> idx_1 >> idx_2;

        if (command == "copy") {
            copyToClipboard(idx_1, idx_2, text, clipboard, clipboardSize);
        } else if (command == "paste") {
            paste(text, idx_1, idx_2, clipboard);
        }
    }

    // print out the words
    std::cout << text << std::endl;
    return 0;
}
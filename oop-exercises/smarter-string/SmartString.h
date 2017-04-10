//
// Created by netherblood on 10.04.17.
//

#ifndef SMARTER_STRING_SMARTSTRING_H
#define SMARTER_STRING_SMARTSTRING_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

class SmartString : public std::string {
    std::vector<std::string> words;
    void fillWords();
public:
    SmartString(const std::string& str);
    SmartString(const char* str);
    size_t getWordCount();
    void changeWord(size_t wordIndex, const std::string& newWord);
};


#endif //SMARTER_STRING_SMARTSTRING_H

//
// Created by netherblood on 10.04.17.
//

#include "SmartString.h"
#include <vector>
#include <sstream>
using std::istringstream;
using std::vector;
SmartString::SmartString(const std::string& str) : std::string(str) {
    this->fillWords();
}

SmartString::SmartString(const char* cString) : std::string(cString) {
    this->fillWords();
}

size_t SmartString::getWordCount() {
    return this->words.size();
}

void SmartString::fillWords() {
    istringstream stream(*this);  // deref self to stream

    std::string word;
    while (stream >> word) {
        this->words.push_back(word);
    }
}

void SmartString::changeWord(size_t wordIndex, const std::string& newWord) {
    std::stringstream ss;
    if (wordIndex >= 0 || wordIndex > this->words.size()) {
        throw "Index out of bounds!";
    }
    this->words[wordIndex-1] = newWord;
    std::string word;

    for (int i = 0; i < this->words.size()-1; ++i) {
        word = this->words[i];
        ss << word << " ";
    }
    ss << this->words[this->words.size() - 1];
    (*this) = ss.str();
}
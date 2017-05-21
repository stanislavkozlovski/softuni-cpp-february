#include <iostream>
#include <sstream>
#include <map>
#include <vector>

using std::cin;
using std::string;
using std::vector;
using std::stringstream;
using std::map;
using std::make_pair;

int getWordCount(string& sentence, string& wantedWord) {
    int wordCount = 0;
    string currWord;
    stringstream ss;
    ss << sentence;
    while (ss >> currWord) {
        if (currWord == wantedWord) {
            wordCount++;
        }
    }

    return wordCount;
}

int main() {
    cin.sync_with_stdio(false);
    string wantedWord;
    cin >> wantedWord;
    int wantedLines = 0;
    cin >> wantedLines;
    map<int, vector<string>> sentencesByCount;
    string currentSentence;
    while (getline(cin, currentSentence)) {
        if (currentSentence == ".") {
            break;
        }
        // Analyze sentence
        int wordCount = getWordCount(currentSentence, wantedWord);
//        std::cout << "Word count of " << wantedWord << " in " << currentSentence << " is " << wordCount << std::endl;
        if (wordCount > 0) {
            auto it = sentencesByCount.find(wordCount);
            if (it == sentencesByCount.end()) {
                vector<string> sentences = {currentSentence};
                sentencesByCount.insert(make_pair(wordCount, sentences));
            } else {
                sentencesByCount[wordCount].push_back(currentSentence);
            }
        }
    }

    int printedSentencees = 0;
    for (auto iter = sentencesByCount.rbegin(); iter != sentencesByCount.rend(); ++iter) {
        for (auto sent : iter->second) {
            if (printedSentencees == wantedLines) {
                break;
            }
            std::cout << sent << std::endl;
            printedSentencees++;
        }
    }

    return 0;
}
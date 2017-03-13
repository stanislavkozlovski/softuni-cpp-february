#include <iostream>
#include <string>
#include <sstream>
#include <vector>

bool wordsAreSimilar(const std::string& word_1, const std::string& word_2, int wantedPerc) {
    /* Returns a boolean indicating if the word is similar to the given word by the given percentage*/
    if (word_1.size() != word_2.size() || word_1[0] != word_2[0]) {
        return false;
    }

    int equalCharacters = 0;

    for (size_t i = 0; i < word_1.size(); i++) {
        if (word_1[i] == word_2[i]) {
            equalCharacters++;
        }
    }

    int simPerc = ((double)equalCharacters / word_1.size()) * 100;
    return wantedPerc <= simPerc;
}

int main() {
    std::vector<std::string> wordVector;
    std::string line;
    std::getline(std::cin, line);
    std::size_t prev = 0, pos;
    while ((pos = line.find_first_of(".,;!? ", prev)) != std::string::npos)
    {
        if (pos > prev)
            wordVector.push_back(line.substr(prev, pos-prev));
        prev = pos+1;
    }
    if (prev < line.length())
        wordVector.push_back(line.substr(prev, std::string::npos));
    
    std::string wantedWord;
    int similarityPercentage;
    std::cin >> wantedWord >> similarityPercentage;

    int validWordsCount = 0;
    for (size_t i = 0; i < wordVector.size(); i++) {
        if (wordsAreSimilar(wordVector[i], wantedWord, similarityPercentage)) {
            validWordsCount++;
        }
    }

    std::cout << validWordsCount << std::endl;
    return 0;
}
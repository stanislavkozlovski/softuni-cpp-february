#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

int main() {
    std::unordered_map<int, std::vector<std::string>> words;
    std::unordered_map<std::string, int> wordsByCount;
    std::string input;
    getline(std::cin, input);

    std::string currWord;
    std::vector<std::string> savedWords;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            savedWords.push_back(currWord);
            currWord = "";
        }
        else
            currWord += input[i];
    }

    for (auto word : savedWords) {
        if (word == "" || word == ".") {
            break;
        }

        auto it = wordsByCount.find(word);
        if (it == wordsByCount.end()) {
            wordsByCount[word] = 1;
        } else {
            wordsByCount[word]++;
        }
    }

    for (auto tank : wordsByCount) {
        std::string word = tank.first;
        int occ = tank.second;
        auto it = words.find(tank.second);
        if (it == words.end()) {
            words.insert(std::make_pair(tank.second, std::vector<std::string>{tank.first}));
        } else {
            words[tank.second].push_back(tank.first);
        }
    }

    for (auto tnk : words) {
        std::sort(words[tnk.first].begin(), words[tnk.first].end());
    }


    int queryCount;
    std::cin >> queryCount;

    for (int j = 0; j < queryCount; ++j) {
        int i, jj;
        std::cin >> i >> jj;

        auto it = words.find(i);
        if (it == words.end()) {
            std::cout << "." << std::endl;
        } else {
            if (jj >= it->second.size()) {
                std::cout << "." << std::endl;
            } else {
                std::cout << it->second[jj] << std::endl;
            }
        }

    }
    return 0;
}
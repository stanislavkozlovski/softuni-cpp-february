#include <iostream>
#include <vector>
#include <sstream>

using std::string;
using std::cin;
using std::vector;
using std::stringstream;

int main() {
    vector<int> originalPipes;
    vector<int> corrodedPipes;
    string firstLine, secondLine;
    getline(cin, firstLine);
    getline(cin, secondLine);
    stringstream ss;
    ss << firstLine;
    int currPipe;
    while (ss >> currPipe) {
        originalPipes.push_back(currPipe);
    }

    stringstream newSS;
    newSS << secondLine;
    int currCorrPipe;
    while (newSS >> currCorrPipe) {
        corrodedPipes.push_back(currCorrPipe);
    }

    vector<int> answers;
    for (int i = 0; i < originalPipes.size(); ++i) {
        int originalPipe = originalPipes[i];
        int corrodedPipe = corrodedPipes[i];
        int corrosionRate = originalPipe - corrodedPipe;
        if (corrosionRate > corrodedPipe) {
            answers.push_back(0);
        } else {
            answers.push_back(corrodedPipe / corrosionRate);
        }
//        if (corrodedPipe == 0) {
//            answers.push_back(0);
//            std::cout << 0 << std::endl;
//            continue;
//        }
//        if (originalPipe % corrodedPipe == 0) {
//            answers.push_back((originalPipe / corrodedPipe) + 1);
//            std::cout << (originalPipe / corrodedPipe) + 1 << std::endl;
//        } else {
//            answers.push_back((originalPipe / corrodedPipe));
//            std::cout << originalPipe / corrodedPipe << std::endl;
//        }
    }

    for (int j = 0; j < answers.size(); ++j) {
        if (j == answers.size()-1) {
            std::cout << answers[j] << std::endl;
        } else {
            std::cout << answers[j] << " ";
        }
    }


    return 0;
}
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>
#include <limits>

const int SUM_OP = 0, AVG_OP = 1, MIN_OP = 2, MAX_OP = 3;

std::vector<int> createVector(std::string numbersStr);
std::unordered_map<std::string, int> readOperationNames(int readCount);
std::string executeCommands(const std::unordered_map<std::string, int> &opNames, const std::vector<int> &numbers);
int getSum(const std::vector<int> numbers, int startIndex, int endIndex);
int getAvg(const std::vector<int> numbers, int startIndex, int endIndex);
int findMin(const std::vector<int> numbers, int startIndex, int endIndex);
int findMax(const std::vector<int> numbers, int startIndex, int endIndex);
std::string buildResultString(const std::vector<std::string> results);


int main() {
    std::string numbersStr;
    int defineOpCount;  // the number of definitions we will read

    std::getline(std::cin, numbersStr);
    std::vector<int> numbers = createVector(numbersStr);

    std::cin >> defineOpCount;
    std::unordered_map<std::string, int> opNames = readOperationNames(defineOpCount);
    std::string outputStr = executeCommands(opNames, numbers);
    std::cout << outputStr << std::endl;
    return 0;
}

std::string executeCommands(const std::unordered_map<std::string, int> &opNames, const std::vector<int> &numbers) {
    /* Executes all the commands given by the user and returns a string summary */
    std::vector<std::string> commandResults; // store command strings here
    std::string command;
    std::cin >> command;
    while (command != "end") {
        int startIdx, endIdx;
        std::cin >> startIdx >> endIdx;

        int opId = opNames.find(command)->second;
        std::string currResult;
        std::stringstream ss;
        int opResult;
        switch (opId) {
            case SUM_OP:
                opResult = getSum(numbers, startIdx, endIdx);
                break;
            case AVG_OP:
                opResult = getAvg(numbers, startIdx, endIdx);
                break;
            case MIN_OP:
                opResult = findMin(numbers, startIdx, endIdx);
                break;
            case MAX_OP:
                opResult = findMax(numbers, startIdx, endIdx);
                break;
        }
        ss << command.c_str() << "(" << startIdx << "," << endIdx  << ")=" << opResult;
        commandResults.push_back(ss.str());

        std::cin >> command;
    }

    return buildResultString(commandResults);
}

std::string buildResultString(const std::vector<std::string> results) {
    std::stringstream ss;
    ss << "[" << results.size() << "]{";

    for (size_t i = 0; i < results.size(); i++) {
        ss << results[i];
        if (i + 1 < results.size()) {
            ss << ',';
        }
    }
    ss << "}";

    return ss.str();
}

int getSum(const std::vector<int> numbers, int startIndex, int endIndex) {
    int sum = 0;

    for (size_t i = startIndex; i < endIndex; i++) {
        sum += numbers[i];
    }

    return sum;
}

int getAvg(const std::vector<int> numbers, int startIndex, int endIndex) {
    int count = endIndex - startIndex;

    return getSum(numbers, startIndex, endIndex) / count;
}

int findMin(const std::vector<int> numbers, int startIndex, int endIndex) {
    int min = std::numeric_limits<int>::max();

    for (size_t i = startIndex; i < endIndex; i++) {
        int currNum = numbers[i];
        if (currNum < min) {
            min = currNum;
        }
    }

    return min;
}


int findMax(const std::vector<int> numbers, int startIndex, int endIndex) {
    int max = std::numeric_limits<int>::min();

    for (size_t i = startIndex; i < endIndex; i++) {
        int currNum = numbers[i];
        if (currNum > max) {
            max = currNum;
        }
    }

    return max;
}

std::unordered_map<std::string, int> readOperationNames(int readCount) {
    /* Attaches a name to each of the operations */
    std::unordered_map<std::string, int> opNames;
    for (size_t i = 0; i < readCount; i++) {
        std::string opName;
        int opNumber;
        std::cin >> opName >> opNumber;
        // Attach the name to the operation ID
        opNames[opName] = opNumber;
    }

    return opNames;
}

std::vector<int> createVector(std::string numbersStr) {
    /* Fills a vector of integers */
    int x;
    std::vector<int> numbers;

    std::stringstream sstream;
    sstream << numbersStr;
    while (sstream >> x) {
        numbers.push_back(x);
    }

    return numbers;
}
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using std::vector; 
using std::string;
using std::stringstream;

class LineParser {
    private:
        string line;
        // Store them for efficiency, so we don't have to rebuild them on each get call
        vector<int> numbers;
        vector<string> strings;
        vector<char> chars;

        void FillNumbers() {
            stringstream ss;
            ss << this->line;

            int number;
            while (ss >> number) {
                this->numbers.push_back(number);
            }
        }

        void FillStrings() {
            stringstream ss;
            ss << this->line;

            string word;
            while (ss >> word) {
                this->strings.push_back(word);
            }
        }

        void FillChars() {
            stringstream ss;
            ss << this->line;

            string word;
            while (ss >> word) {
                for (int i = 0; i < word.size(); i++) {
                    this->chars.push_back(word[i]);
                }
            }
        }

        void ResetVectors() {
            // Resets the vectors once a new line has been added
            this->numbers.clear();
            this->chars.clear();
            this->strings.clear();
        }
    public:
        LineParser(const string& line) {
            this->line = line;
        }

        vector<int> GetNumbers(){
            if (this->numbers.size() == 0) {
                // Only fill them when necessary
                this->FillNumbers();
            }
            return this->numbers;
        }

        vector<string> GetStrings() {
            if (this->strings.size() == 0) {
                this->FillStrings();
            }
            return this->strings;
        }

        vector<char> GetChars() {
            if (this->chars.size() == 0) {
                this->FillChars();
            }
            return this->chars;
        }

        void ChangeLine(const string& line) {
            this->line = line;
            this->ResetVectors();
        }
};

int main() {
    LineParser lp("1 2 3 4");
    vector<int> v = lp.GetNumbers();
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    vector<char> vChars = lp.GetChars();
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    lp.ChangeLine("1");
    vector<int> changed = lp.GetNumbers();
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    vector<char> changedChars = lp.GetChars();
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    lp.ChangeLine("");
    vector<string> words = lp.GetStrings();
    std::cout << "Len of words is " << words.size() << std::endl;

    lp.ChangeLine("I am a mixed string, consisting of numbers like 1234, 12341, 4134141, 1313 and 0. Wonder what this will output?");
    vector<int> nums = lp.GetNumbers();
    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    
    vector<string> strs = lp.GetStrings();
    for (int i = 0; i < strs.size(); i++) {
        std::cout << strs[i] << " ";
    }
    std::cout << std::endl;
    
    vector<char> chrs = lp.GetChars();
    for (int i = 0; i < chrs.size(); i++) {
        std::cout << chrs[i] << " ";
    }
    return 0;
}
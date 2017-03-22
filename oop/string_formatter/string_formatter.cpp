#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <exception>

using std::string;
using std::vector;
using std::unordered_map;
using std::stringstream;

class descriptive_exception : public std::exception {
    public:
    descriptive_exception(std::string const &message) : msg_(message) { }
    virtual char const *what() const noexcept { return msg_.c_str(); }

    private:
    std::string msg_;
};
class StringFormatter {
    private:
        string& text;
        string placeholderPrefix;
        unordered_map<int, int> indices;
    public:
        StringFormatter(string& strToFormat, const string& formatPrefix): 
        text(strToFormat)  {
            // this->text = strToFormat;
            this->placeholderPrefix = formatPrefix;
        }

        void FillPlaceholderIndices(int plCount) {
            /* Fills the each placeholders to the index it starts at*/
            int placeholderNumber = 0;
            stringstream ss;
            string expectedPlaceholder;
            // Build the expected placeholder we're searching for
            ss << this->placeholderPrefix << placeholderNumber;
            ss >> expectedPlaceholder;
            for (int i = 0; i < this->text.size(); i++) {
                // Search substring by substring for the placeholderPrefix
                if (this->text[i] != this->placeholderPrefix[0]) 
                    continue;  // only get substrings which make sense

                if (i + expectedPlaceholder.size() > this->text.size()) {
                    stringstream errMsg;
                    errMsg << "Missing placeholder #" << i << "'!";
                    throw descriptive_exception(errMsg.str().c_str());
                }
                
                string substr = this->text.substr(i, expectedPlaceholder.size());
                
                if (substr == expectedPlaceholder) {
                    // Found the placeholder
                    this->indices.insert(std::make_pair(placeholderNumber, i));
                    
                    if (++placeholderNumber == plCount) {
                        break;  // reached the last placeholder
                    }
                    // update the placeholder we're expecting
                    expectedPlaceholder.clear();
                    ss.clear();
                    ss << this->placeholderPrefix << placeholderNumber;
                    ss >> expectedPlaceholder;
                }
            }
        }

        void Format(int insertArr[], int insertArrSize) {
            this->FillPlaceholderIndices(insertArrSize);

            // replace the values
            int indexOffset = 0;  // we need this offset because we constantly change the length of the string
            int lastStrSize = this->text.size();
            stringstream ss;
            
            for (int plNum = 0; plNum < insertArrSize; plNum++) {
                string expectedPlaceholder;
                ss << this->placeholderPrefix << plNum;
                ss >> expectedPlaceholder;
                ss.clear();

                string numToInsert;
                ss << insertArr[plNum];
                ss >> numToInsert;
                ss.clear();
                
                unordered_map<int, int>::const_iterator findResult = this->indices.find(plNum);
                if (findResult == this->indices.end()) {
                    // THROW EXC
                    stringstream errMsg;
                    errMsg << "Missing placeholder " << expectedPlaceholder << "!";
                    throw descriptive_exception(errMsg.str().c_str());
                }
                int indexToInsertAt = findResult->second;
                this->text.replace(indexToInsertAt + indexOffset, expectedPlaceholder.size(), numToInsert);
                int txtSize = this->text.size();
                indexOffset += txtSize - lastStrSize;
                lastStrSize = txtSize;
            }
        }

        void Format(string insertArr[], int insertArrSize) {
            this->FillPlaceholderIndices(insertArrSize);

            // replace the values
            int indexOffset = 0;  // we need this offset because we constantly change the length of the string
            int lastStrSize = this->text.size();
            stringstream ss;
            
            for (int plNum = 0; plNum < insertArrSize; plNum++) {
                string expectedPlaceholder;
                ss << this->placeholderPrefix << plNum;
                ss >> expectedPlaceholder;
                ss.clear();

                string numToInsert = insertArr[plNum];
                
                unordered_map<int, int>::const_iterator findResult = this->indices.find(plNum);
                if (findResult == this->indices.end()) {
                    // THROW EXC
                    stringstream errMsg;
                    errMsg << "Missing placeholder " << expectedPlaceholder << "!";
                    throw descriptive_exception(errMsg.str().c_str());
                }
                int indexToInsertAt = findResult->second;
                this->text.replace(indexToInsertAt + indexOffset, expectedPlaceholder.size(), numToInsert);
                int txtSize = this->text.size();
                indexOffset += txtSize - lastStrSize;
                lastStrSize = txtSize;
            }
        }
};

int main() {
        // string s = "Dear *:0, Our company *:1 wants to make you a Donation Of *:2 Million *:3 in good faith. Please send us a picture of your credit card";
        // StringFormatter formatter(s, "*:");
        // formatter.Format(new int[4]{1,2,3,4}, 4);
        // std::cout << s;
        string s = "Dear *:0, Our company *:1 wants to make you a Donation Of *:2 Million *:3 in good faith. Please send us a picture of your credit card";
        StringFormatter formatter(s, "*:");
        formatter.Format(new string[4]{"Ben Dover", "Totally Legit NonSpam Ltd", "13", "Leva"}, 4);
        std::cout << s << std::endl;
        return 0;
}
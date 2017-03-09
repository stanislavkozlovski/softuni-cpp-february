#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

int zAlgorithm(string pattern, string target) {
    /* Uses the Z Algorithm to efficiently ( in O(n+m) time ) to compute the number of substrings*/
    string s = pattern + '$' + target;
    int n = s.length();
    vector<int> z(n, 0);
    int goal = pattern.length();
    int occurences = 0;
    int r = 0, l = 0, i;

    for (int k = 1;  k < n; k++) {
        if (k > r) {
            // increase i while its less than n and the character is equal to the prefix
            for (i = k; i < n && s[i] == s[i - k]; i++);
            if (i > k)
            {
                z[k] = i - k;
                l = k;
                r = i - 1;
            }
        }
        else {
            int kt = k - l;
            int b = r - k + 1;
            if (z[kt] > b) {
                // increase i while its less than n and the character at i is equal to the corresponding char on the prefix
                for (i = r + 1; i < n && s[i] == s[i - k]; i++);
                z[k] = i - k;
                l = k;
                r = i - 1;
            }
        }
        if (z[k] == goal)
            occurences++;
    }
    return occurences;
}


int* parseNumbers(const string& str, int& resultLength) {
    int spaceCount = zAlgorithm(" ", str);
    int *p;
    int * numbers;
    numbers = new int [spaceCount+1];
    resultLength = spaceCount + 1;

    bool lastWasSpace = true;
    int numIndex = 0;
    // parse  the numbers from the string
    istringstream inputStream(str);
    int currentNum;
    while (inputStream >> currentNum) {
        numbers[numIndex] = currentNum;
        numIndex++;
    }
    
    p = numbers;
    return p;
}

int calcSum(int arr[], int arrLen) {
    int sum = 0;
    
    for (int i = 0; i < arrLen; i++) {
        sum += arr[i];
    }

    return sum;
}
int main() {
    string inputFilename;
    cout << "Please enter the input file name." << endl;
    cin >> inputFilename;
    string outputFilename;
    cout << "Please enter the output file name." << endl;
    cin >> outputFilename;
    
    ifstream inputStream(inputFilename.c_str());
    int sum = 0;
    string input;
    while (getline(inputStream, input)) {

    // }
    // for (int i = 0; i < lineCount; i++) {
        // string input;
        int arrayLen = 0;
        
        // getline(cin, input);

        int *arrPointer = parseNumbers(input, arrayLen);
        sum += calcSum(arrPointer, arrayLen);
    }
    inputStream.close();


    ofstream outputStream(outputFilename.c_str());
    outputStream << sum << endl;
    outputStream.close();
    cout << "Wrote to " << outputFilename << endl;
    return 0;
}
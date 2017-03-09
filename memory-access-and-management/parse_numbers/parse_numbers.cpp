#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>     /* atoi */
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
    for (int i = 0; i < str.size(); i++) {
        string currentNum(1 ,str[i]);
        for (int j = i+1; j < str.size(); j++) {
            if (str[j] != ' ') {
                currentNum.push_back(str[j]);
            } else {
                // we're at a whitespace, make sure the main for loop jumps to the index after the whitespace
                i = j;
                break;
            }
        }
        numbers[numIndex] = atoi(currentNum.c_str());
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
    int lineCount;
    cin >> lineCount;
    string empty;
    getline(cin, empty);
    int sum = 0;
    for (int i = 0; i < lineCount; i++) {
        string input;
        int arrayLen = 0;
        
        getline(cin, input);

        int *arrPointer = parseNumbers(input, arrayLen);
        sum += calcSum(arrPointer, arrayLen);
    }

    cout << sum << endl;
    return 0;
}
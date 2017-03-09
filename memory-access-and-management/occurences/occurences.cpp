#include <iostream>
#include <string>
#include <vector>

using namespace std;

int zAlgorithm(string pattern, string target);


int main() {
    string pattern, text;
    cout << "Enter the pattern you want" << endl;
    getline(cin, pattern);
    cout << "Enter the text you want to search in" << endl;
    getline(cin, text);

    cout << zAlgorithm(pattern, text) << endl;
    return 0;
}

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
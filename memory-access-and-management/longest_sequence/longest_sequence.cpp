#include <iostream>
#include <tuple>
using namespace std;

void printArr(int array[], int startIndex, int arrayLength);
int main() {
    int arrayLength;
    cin >> arrayLength;
    int arr[arrayLength];
    for (int i = 0; i < arrayLength; i++)
    {
        cin >> arr[i];
    }

    int longestSequenceIndex = 0;
    int longestSeqLen = 0;
    int currentStartIndex = 0;
    int currentSeqLen = 1;
    int lastElement = arr[0];
    for (int i = 1; i < arrayLength; i++) {
        if (arr[i] == lastElement) {
            currentSeqLen++;
            if (currentSeqLen > longestSeqLen) {
                longestSequenceIndex = currentStartIndex;
                longestSeqLen = currentSeqLen;
            }
        } else {
            currentSeqLen = 1;
            currentStartIndex = i;
            lastElement = arr[i];
        }
    }

    printArr(arr, longestSequenceIndex, longestSequenceIndex + longestSeqLen);
    return 0;
}

void printArr(int array[], int startIndex, int endIndex) {
    for (int i = startIndex; i < endIndex; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
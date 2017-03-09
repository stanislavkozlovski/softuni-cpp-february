#include <iostream>
using namespace std;

bool compArr(int arr1[], int arr1Len, int arr2[], int arr2Len);

int main() {
    int firstArrLen;
    cout << "Enter the length of the first array: " << endl;
    cin >> firstArrLen;
    int firstArr[firstArrLen];
    cout << "Enter the number of your first array: " << endl;
    for (int i = 0; i < firstArrLen; i++) {
        cin >> firstArr[i];
    }
    int secondArrLen;
    cout << "Enter the length of the second array: " << endl;
    cin >> secondArrLen;
    int secondArr[secondArrLen];
    cout << "Enter the number of your second array: " << endl;
    for (int i = 0; i < secondArrLen; i++) {
        cin >> secondArr[i];
    }

    cout << "Both arrays are " << (compArr(firstArr, firstArrLen, secondArr, secondArrLen) ? "equal!" : "not equal!" ) << endl;
    return 0;
}

bool compArr(int arr1[], int arr1Len, int arr2[], int arr2Len) {
    if (arr1Len != arr2Len) {
        // Different sizes mean that they're different arrays
        return false;
    }
    
    for (int i = 0; i < arr1Len; i++)
    {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }

    return true;
}
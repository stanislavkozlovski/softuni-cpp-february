#include <iostream>
using namespace std;

void swapElements(int a[], int idxA, int idxB) {
    int tempValue = a[idxA];
    a[idxA] = a[idxB];
    a[idxB] = tempValue;
}

void selectionSort(int a[], int start, int end) {
    for (int i = start; i < end; i++)
    {
        int minValueIndex = i;
        int minValue = a[i];
        
        for (int j = i+1; j < end; j++)
        {
            if (a[j] < minValue) {
                minValue = a[j];
                minValueIndex = j;
            }
        }

        swapElements(a, i, minValueIndex);
    }
}

void printArr(int a[], int length) {
    for (int i = 0; i < length; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int arrLen;
    cout << "What is the length of your array?" << endl;
    cin >> arrLen;
    int arr[arrLen];
    cout << "Enter your array" << endl;
    for (int i = 0; i < arrLen; i++)
    {
        cin >> arr[i];
    }
    cout << "What is the start and the end index(exclusive) that you want sorted?" << endl;
    int startIndex, endIndex;
    cin >> startIndex >> endIndex;

    selectionSort(arr, startIndex, endIndex);
    printArr(arr, arrLen);
    return 0;
}
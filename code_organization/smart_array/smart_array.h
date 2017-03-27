#include <iostream>
#include <stdexcept>
using namespace std;

class SmartArray {
    int capacity;
    int* elements;


        void incrCapacity();
        void dcrCapacity();
        void dcrCapacity(int newCap);
        void createNewArr(int newLength);
    public:
        int size;
    
        SmartArray();
        SmartArray(int capacity);
        void Append(int el);
        void Cut();
        void CutTo(int newLength);
        int& operator[](const int idx) const;
};
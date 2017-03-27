#include <iostream>
#include <stdexcept>
#ifndef SMARTARRAY
    #define SMARTARRAY
class SmartArray {
    int capacity;
    int* elements;


        void incrCapacity() {
            /* Double the capacity */
            this->capacity *= 2;
        }
        void dcrCapacity() {
            /* Decrease the capacity twice */
            this->capacity /= 2;
        }
        void dcrCapacity(int newCap) {
            /* Decrease the capacity by the given amount */
            this->capacity = newCap;
        }
        void createNewArr(int newLength) {
            /* Creates a new array in order to **increase the size**,
               deletes the old array and attaches the new array to this->elements */
            int* newElements = new int[this->capacity];

            for (int i = 0; i < this->size && i < newLength; i++) {
                newElements[i] = this->elements[i];
            }
            if (newLength < this->size) {
                // We've remove elements'
                this->size = newLength;
            }
            delete[] this->elements;
            this->elements = newElements;
        }
    public:
        int size;
    
        SmartArray() :
            capacity(32),
            size(0),
            elements(new int[this->capacity]) { }

        SmartArray(int capacity) :
            capacity(capacity), 
            size(0),
            elements(new int[this->capacity]) { }

        void Append(int el) {
            if (this->size + 1 > this->capacity) {
                this->incrCapacity();
                this->createNewArr(this->capacity);
            }
            this->size++;
            

            this->elements[this->size - 1] = el;
        }

        void Cut() {
            /* Halves the array, losing the right part of values */
            this->dcrCapacity();
            std::cout << "Removing " << this->capacity;
            
            this->createNewArr(this->capacity);
        }

        void CutTo(int newLength) {
            this->dcrCapacity(newLength);
            this->createNewArr(this->capacity);
        }

        int& operator[](const int idx) const {
            if (idx >= this->size || idx < 0) {
                throw std::invalid_argument( "Invalid index!" );
            }
            return this->elements[idx];
        }

};

#endif

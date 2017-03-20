#include <iostream>
#include <stdexcept>

class SmartArray {
    int capacity;
    int size;
    int* elements;


        void incrCapacity() {
            /* Double the capacity */
            this->capacity *= this->capacity;
        }
        void dcrCapacity() {
            /* Decrease the capacity twice */
            this->capacity /= this->capacity;
            // TODO: Check if we've deleted items and create new array
        }
        void createNewArr() {
            /* Creates a new array in order to **increase the size**,
               deletes the old array and attaches the new array to this->elements */
            this->incrCapacity();
            
            int* newElements = new int[this->capacity];

            for (int i = 0; i < this->size; i++) {
                newElements[i] = this->elements[i];
            }

            delete[] this->elements;
            this->elements = newElements;
        }
    public:
        SmartArray() {
            this->capacity = 32;
            this->size = 0;
            this->elements = new int[this->capacity];
        }
        SmartArray(int capacity) {
            this->capacity = capacity;
            this->size = 0;
            this->elements = new int[this->capacity];
        }

        void Append(int el) {
            if (this->size > this->capacity) {
                this->createNewArr();                
            }
            this->size++;
            

            this->elements[this->size - 1] = el;
        }

        int operator[](const int idx) {
            if (idx >= this->size || idx < 0) {
                throw std::invalid_argument( "Invalid index!" );
            }
            return this->elements[idx];
        }

};

int main() {
    SmartArray smArr;
    for (size_t i = 0; i < 34; i++) {
        smArr.Append(3);
    }
    return 0;
}
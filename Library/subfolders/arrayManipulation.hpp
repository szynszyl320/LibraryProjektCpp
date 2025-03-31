#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
class DynamicArray
{
private:
    int arraySize;
    T* data;

public:
    DynamicArray(int sz) : arraySize(sz) {
        this->data = new T[this->arraySize];
    }

    int insertData(int index, T data) {
        if(index >= 0 && index < this->arraySize) {
            this->data[index] = data;
            return 0;
        } else {
            return -1;
        }
    }

    T getData(int index) {
        if(index >= 0 && index < this->arraySize) {
            return this->data[index];
        } else {
            return -1;
        }
    }

    int getSize() {
        return this->arraySize;
    }

    /**void resizeArray(int newSize) {
        T* newData = new T[newSize];
        int elementsToCopy = min(this->arraySize, newSize)
    }**/

    ~DynamicArray() {
        delete[] this->data;
    }


};

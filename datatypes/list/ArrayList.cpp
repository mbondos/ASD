#include "ArrayList.h"

template<typename T>
ArrayList<T>::ArrayList(size_t size)
{
    elements = 0;
    counter = 0;
    this->size = size;
    this->array = new T[this->size];
}

template <typename T>
void ArrayList<T>::resize() {
    size_t newSize = size * 2;
    T *newArray = new T[newSize];
    memcpy(this->array, newArray, newSize);
    delete [] this->array;
    this->size = newSize;
    this->array = newArray;
}

template<typename T>
void ArrayList<T>::add(T value) {
    if (size <= elements) {
        resize();
    }
    array[elements] = value;
    elements++;
}

template<typename T>
T ArrayList<T>::next() {
    if(counter >= elements) {
        throw std::out_of_range("There is no next value");
    }
    return array[counter++];
}

template <typename T>
bool ArrayList<T>::hasNext() {
    return counter <= elements ? 1 : 0;
}

template <typename T>
bool ArrayList<T>::isEmpty() {
    return elements == 0 ? 1 : 0;
}

template <typename T>
int ArrayList<T>::listSize() {
    return elements;
}


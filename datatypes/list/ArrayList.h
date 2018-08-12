#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <cstring>
#include <stdexcept>

template<typename T>
class ArrayList
{
    T *array;
    int size;
    int counter;
    int elements;
    void resize();

public:
    ArrayList(size_t size = 10);

    bool hasNext();
    T next();

    void add(T value);

    bool isEmpty();
    int listSize();

};

#endif // ARRAYLIST_H

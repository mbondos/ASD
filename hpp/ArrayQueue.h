
#ifndef ASD_ARRAY_QUEUE_H
#define ASD_ARRAY_QUEUE_H


#include <iostream>
#include <stdexcept>


template<typename T>
class ArrayQueue{
    T *queue;
    int head;
    int tail;
    int queueSize;
    int elements;
public:
    ArrayQueue(int size);
    ~ArrayQueue();
    void push(T data);
    T pop();
    int getEmptyLeft();
    int getElements();
    void reverse();
    void printList();
    void reverseHeadTail();
    ArrayQueue<T>& operator +=(ArrayQueue<T>& que);
    ArrayQueue<T>(const ArrayQueue<T>&) = delete;
    ArrayQueue<T>& operator =(const ArrayQueue<T>&)= delete;

};


#endif //ASD_ARRAY_QUEUE_H

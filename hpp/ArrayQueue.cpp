#include "ArrayQueue.h"

using ::std::cout;
using ::std::cin;

template<typename T>
ArrayQueue<T>::ArrayQueue(int size) :elements(0),head(0),tail(0),queueSize(size){
    queue = new T[size];
}

template<typename T>
ArrayQueue<T>::~ArrayQueue() {
   delete[] queue;
}


template<typename T>
void ArrayQueue<T>::push(T data){
    if(getEmptyLeft()==0) throw std::out_of_range("Queue full");
    else if(getElements()==0){
        head=0;
        tail=0;
    }else{
        tail=(tail+1)%queueSize;
    }
    queue[tail]=data;
    elements++;
}

template<typename T>
T ArrayQueue<T>::pop(){
    if(getElements() == 0){
        throw std::runtime_error("Queue empty");
    }
    int temp=head;
    if(head == tail){
        head=tail=-1;
    }
    else{
        head=(head+1)%queueSize;
    }
    elements--;
    return queue[temp];
}

template<typename T>
int ArrayQueue<T>::getElements(){
    return elements;
}

template<typename T>
int ArrayQueue<T>::getEmptyLeft(){
    return queueSize- getElements();
}

template<typename T>
void ArrayQueue<T>::reverse() {
    T temp;
    if(this->getElements() != 0) {
        temp= pop();
        reverse();
        push(temp);
    }
}

template<typename T>
void ArrayQueue<T>::printList(){
    for (int i = 0; i < queueSize; i++ ){
        if((head+i)%queueSize < tail+1)
            cout<<queue[(head+i)%queueSize]<<" ";
    }
}

template<typename T>
void ArrayQueue<T>::reverseHeadTail() {
    T temp=head;
    head=tail;
    tail=temp;
}

template<typename T>
ArrayQueue<T>& ArrayQueue<T>::operator +=(ArrayQueue<T>& que){
    if(que.getElements() > this->getEmptyLeft()) throw std::out_of_range("Not Enough space");
    while(que.getElements() != 0)
        this->push(que.pop());
    return *this;

}

#ifndef ASD_LIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

template<class T>
class LinkedList{
protected:

    struct  Node{
        T data;
        Node *nextNode;
        Node(const T d, Node *n=NULL){
            data=d;
            nextNode=n;
        }
    };
public:
    typedef  Node* NodePointer;
    LinkedList();
    ~LinkedList();
    void add(T);
    bool remove(T);
    bool removeAtIndex(int index);
    bool contains(LinkedList list);
    bool isEmpty() const;
    int removeDuplicates();
    void writeToFileFromRange(string filename, int leftIndex, int rightIndex);
    int removeFromRange(int leftIndex, int rightIndex);
    void printToConsole();
    void findAndPrintToConsole(const T d);
    void usunWsk(NodePointer wsk);

protected:
    NodePointer Pierwszy;
    NodePointer find(const T d);
    NodePointer newNode(const T d, NodePointer n = NULL);
};
;


#define ASD_LIST_H


#endif //ASD_LIST_H

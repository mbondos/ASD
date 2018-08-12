#include <fstream>
#include "LinkedList.h"

template<class T>
LinkedList<T>::LinkedList(){
    head = NULL;
}

template<class T>
bool LinkedList<T>::isEmpty() const{
    return head == NULL;
}

template<class T>
LinkedList<T>::~LinkedList(){
    if(!isEmpty()){
        NodePointer rob = head;
        while(head != NULL){
            head = head->nextNode;
            delete rob;
            rob=head;
        }
    }
}
template<class T>
void LinkedList<T>::add(T d) {
    if(isEmpty()){
        head = newNode(d);
    } else if(head->data > d){
        NodePointer rob=head;
        head= newNode(d, rob);
    } else{
        NodePointer rob=head;
        while(rob->nextNode != NULL){
            if(rob->nextNode->data <= d)
                rob = rob->nextNode;
            else
                break;
        }
        NodePointer nowy = newNode(d, rob->nextNode);
        rob->nextNode = nowy;
    }
}
template<class T>
typename LinkedList<T>::NodePointer LinkedList<T>::newNode(const T d, NodePointer n){
    return new Node(d,n);
}

template<class T>
bool LinkedList<T>::remove(T d) {
    //TODO removeAtIndex
    return 0;
}

template<class T>
void LinkedList<T>::printToConsole() {
    NodePointer rob=head;
    while(rob!=NULL){
        cout<<rob->data<<endl;
        rob=rob->nextNode;
    }

}

template<class T>
typename LinkedList<T>::NodePointer LinkedList<T>::find(const T d) {
    if(isEmpty()) throw runtime_error("Lista Pusta");

    if(head->data == d) return head;

    NodePointer rob = head->nextNode;
    while(rob != NULL) {
        if(rob->data == d) return rob;
        rob=rob->nextNode;
    }
    return NULL;
}

template<class T>
void LinkedList<T>::findAndPrintToConsole(const T d) {
    NodePointer rob= find(d);
    if(rob != NULL)
        cout<<rob->data<<endl;
    else
        cout<<"Nie ma takiej danej w liscie"<<endl;
}

template<class T>
void LinkedList<T>::usunWsk(NodePointer wsk) {
    if(isEmpty()) throw;
    if(head == wsk) {
        NodePointer rob = head->nextNode;
        delete head;
        head=rob;
        return;
    }
    NodePointer rob= head;
    while(rob->nextNode != wsk && rob->nextNode != NULL){
        rob=rob->nextNode;
    }
    if(rob->nextNode != wsk && rob->nextNode != NULL){
        NodePointer temp= rob->nextNode;
        delete rob->nextNode;
        rob->nextNode=temp->nextNode->nextNode;

    }


}

template<class T>
int LinkedList<T>::removeDuplicates(){
    if(isEmpty()) return -1;
    int licznik=0;

    NodePointer rob = head;
    while(rob->nextNode != NULL) {
        while(rob->data == rob->nextNode->data){
            NodePointer temp= rob->nextNode;
            if(temp->nextNode != NULL)
                rob->nextNode = temp->nextNode;
            else{
                delete temp;
                rob->nextNode=NULL;
                return licznik++;
            }

            licznik++;
            delete temp;
        }
        rob=rob->nextNode;

    }
    return licznik;
}

template<class T>
void LinkedList<T>::writeToFileFromRange(string filename, int leftIndex, int rightIndex) {
    fstream file;
    file.open(filename.c_str(),ios::out | ios::app);
    if (!file.good()) throw runtime_error("Failed to open file " + filename);
    NodePointer rob = head;
    while(rob->nextNode != NULL) {
        while(rob->data >= leftIndex && rob->data <= rightIndex) {
            file<<rob->data;
            if(rob->nextNode == NULL) {
                file.close();
                return;
            }
            rob=rob->nextNode;
        }
        if(rob->data > rightIndex) break;
        rob=rob->nextNode;
    }
    if(rob->data >= leftIndex && rob->data <= rightIndex)  //last list element
        file<<rob->data;
    file.close();
}

template <class T>
int LinkedList<T>::removeFromRange(int leftIndex, int rightIndex) {
    //TODO usun z przedzialu
    return 0;
}

template <class T>
bool LinkedList<T>::contains(LinkedList list) {
    //TODO zawiera()
    return false;
}

template <class T>
bool LinkedList<T>::removeAtIndex(int index) {
    //TODO removeAtIndex
    return false;
}


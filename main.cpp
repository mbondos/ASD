#include <iostream>
#include "datatypes/list/LinkedList.cpp"
#include "datatypes/queue/ArrayQueue.cpp"
#include "datatypes/tree/TreeD.cpp"

using ::std::cout;
int main() {
    LinkedList<int> lista;
    lista.add(5);
    lista.add(2);
    lista.add(2);
    lista.add(1);
    lista.add(3);
    lista.add(1);
    lista.add(6);
    lista.add(6);
    lista.add(6);
    lista.add(6);
    lista.add(6);

    lista.printToConsole();
    cout<<"--------------"<<endl;
    cout<<lista.removeDuplicates()<<endl;
    cout<<"--------------"<<endl;
    lista.printToConsole();
    lista.writeToFileFromRange("asd.txt",6,60);
 /*   ArrayQueue<int> q2(10);
    ArrayQueue<int> q(10);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.printList();
//    q.reverse();
//    cout<<endl;
//    q.printList();
    q2.push(0);
    q2.push(9);
    q2.push(8);
    q2.push(7);
    q+=q2;
    cout<<endl;
    q.printList();
*/
    TreeD<int> tree;
    tree.insert(9);
    tree.insert(7);
    tree.insert(1);
    tree.insert(2);
    tree.insert(8);
    tree.insert(3);
    tree.insert(4);
    tree.insert(6);

    tree.inOrder();
    cout<<"\n-------"<<endl;
    tree.inOrderBack();
    cout<<"\n-------\n"<<endl;

    tree.preOrder();
    cout<<"\n-------"<<endl;
    tree.preOrderBack();
    cout<<"\n-------\n"<<endl;

    tree.postOrder();
    cout<<"\n-------"<<endl;
    tree.postOrderBack();
    cout<<"\n-------\n"<<endl;
    cout<<tree.findHeight()<<endl;
    return 0;
}
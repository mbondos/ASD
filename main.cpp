#include <iostream>
#include "hpp/ListM.cpp"
#include "hpp/ArrayQueue.cpp"

using ::std::cout;
int main() {
    /*ListaM<int> lista;
    lista.Wstaw(5);
    lista.Wstaw(2);
    lista.Wstaw(2);
    lista.Wstaw(1);
    lista.Wstaw(3);
    lista.Wstaw(1);
    lista.Wstaw(6);
    lista.Wstaw(6);
    lista.Wstaw(6);
    lista.Wstaw(6);
    lista.Wstaw(6);

    lista.wys();
    cout<<"--------------"<<endl;
    cout<<lista.UsunDuplikaty()<<endl;
    cout<<"--------------"<<endl;
    lista.wys();
    lista.DaneZPrzedzialuDoPliku("asd.txt",6,60);
    */
    ArrayQueue<int> q(10);
    ArrayQueue<int> q2(10);
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





    return 0;
}
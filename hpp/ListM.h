#ifndef ASD_LIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

template<class T>
class ListaM{
protected:

    struct  Wezel{
        T dane;
        Wezel *nast;
        Wezel(const T d, Wezel *n=NULL){
            dane=d;
            nast=n;
        }
    };
public:
    typedef  Wezel* Wsk;
    ListaM();
    ~ListaM();
    void Wstaw(T);
    bool Usun(T);
    bool Pusta() const;
    int UsunDuplikaty();
    void DaneZPrzedzialuDoPliku(string nazwaPliku, int lewa, int prawa);
    int UsunZPrzedzialu(int lewa, int prawa);
    bool Zawiera(ListaM lista);
    bool UsunKty(int k);
    void wys();
    void znajdzWys(const T d );
    void usunWsk(Wsk wsk);

protected:
    Wsk Pierwszy;
    Wsk Znajdz(const T d);
    Wsk NowyWezel(const T d, Wsk n=NULL);
};
;


#define ASD_LIST_H


#endif //ASD_LIST_H

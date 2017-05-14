#include <fstream>
#include "ListM.h"

template<class T>
ListaM<T>::ListaM(){
    Pierwszy = NULL;
}

template<class T>
bool ListaM<T>::Pusta() const{
    return Pierwszy == NULL;
}

template<class T>
ListaM<T>::~ListaM(){
    if(!Pusta()){
        Wsk rob = Pierwszy;
        while(Pierwszy != NULL){
            Pierwszy = Pierwszy->nast;
            delete rob;
            rob=Pierwszy;
        }
    }
}
template<class T>
void ListaM<T>::Wstaw(T d) {
    if(Pusta()){
        Pierwszy = NowyWezel(d);
    } else if(Pierwszy->dane > d){
        Wsk rob=Pierwszy;
        Pierwszy=NowyWezel(d, rob);
    } else{
        Wsk rob=Pierwszy;
        while(rob->nast != NULL){
            if(rob->nast->dane <= d)
                rob = rob->nast;
            else
                break;
        }
        Wsk nowy = NowyWezel(d, rob->nast);
        rob->nast = nowy;
    }
}
template<class T>
typename ListaM<T>::Wsk ListaM<T>::NowyWezel(const T d, Wsk n){
    return new Wezel(d,n);
}

template<class T>
bool ListaM<T>::Usun(T d) {
    return 0;
}

template<class T>
void ListaM<T>::wys() {
    Wsk rob=Pierwszy;
    while(rob!=NULL){
        cout<<rob->dane<<endl;
        rob=rob->nast;
    }

}

template<class T>
typename ListaM<T>::Wsk ListaM<T>::Znajdz(const T d) {
    if(Pusta()) throw runtime_error("Lista Pusta");

    if(Pierwszy->dane == d) return Pierwszy;

    Wsk rob = Pierwszy->nast;
    while(rob != NULL) {
        if(rob->dane == d) return rob;
        rob=rob->nast;
    }
    return NULL;
}

template<class T>
void ListaM<T>::znajdzWys(const T d ) {
    Wsk rob=Znajdz(d);
    if(rob != NULL)
        cout<<rob->dane<<endl;
    else
        cout<<"Nie ma takiej danej w liscie"<<endl;
}

template<class T>
void ListaM<T>::usunWsk(Wsk wsk) {
    if(Pusta()) throw;
    if(Pierwszy == wsk) {
        Wsk rob = Pierwszy->nast;
        delete Pierwszy;
        Pierwszy=rob;
        return;
    }
    Wsk rob= Pierwszy;
    while(rob->nast != wsk && rob->nast != NULL){
        rob=rob->nast;
    }
    if(rob->nast != wsk && rob->nast != NULL){
        Wsk temp= rob->nast;
        delete rob->nast;
        rob->nast=temp->nast->nast;

    }


}

template<class T>
int ListaM<T>::UsunDuplikaty(){
    if(Pusta()) return -1;
    int licznik=0;

    Wsk rob = Pierwszy;
    while(rob->nast != NULL) {
        while(rob->dane == rob->nast->dane){
            Wsk temp= rob->nast;
            if(temp->nast != NULL)
                rob->nast = temp->nast;
            else{
                delete temp;
                rob->nast=NULL;
                return licznik++;
            }

            licznik++;
            delete temp;
        }
        rob=rob->nast;

    }
    return licznik;
}

template<class T>
void ListaM<T>::DaneZPrzedzialuDoPliku(string nazwaPliku, int lewa, int prawa) {
    fstream file;
    file.open(nazwaPliku.c_str(),ios::out | ios::app);
    if (!file.good()) throw runtime_error("Failed to open file " + nazwaPliku);
    Wsk rob = Pierwszy;
    while(rob->nast != NULL) {
        while(rob->dane >= lewa && rob->dane <= prawa) {
            file<<rob->dane;
            if(rob->nast == NULL) {
                file.close();
                return;
            }
            rob=rob->nast;
        }
        if(rob->dane > prawa) break;
        rob=rob->nast;
    }
    if(rob->dane >= lewa && rob->dane <= prawa)  //last list element
        file<<rob->dane;
    file.close();
}

template <class T>
int ListaM<T>::UsunZPrzedzialu(int lewa, int prawa) {
    //TODO usun z przedzialu
    return 0;
}

template <class T>
bool ListaM<T>::Zawiera(ListaM lista) {
    //TODO zawiera()
    return false;
}

template <class T>
bool ListaM<T>::UsunKty(int k) {
    //TODO UsunKty
    return false;
}


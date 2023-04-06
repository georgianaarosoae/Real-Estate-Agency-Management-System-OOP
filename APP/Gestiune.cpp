#include "Gestiune.h"

template<class T>
int Gestiune<T>::getNrObiecte() {
    return this->obiecte.size();
}

template<class T>
vector<T>& Gestiune<T>::getVector() {
    return obiecte;
}

template<class T>
void Gestiune<T>::afisareaPozitiei(int x) {
    cout << obiecte[x];
}

template<class T>
Gestiune<T>& Gestiune<T>::operator+=(const T& g) {
    this->obiecte.push_back(g);
    return (*this);
}


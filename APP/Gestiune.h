#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template<class T>
class Gestiune {
    vector<T> obiecte;
public:
    Gestiune() = default;

    ~Gestiune() = default;

    int getNrObiecte();

    vector<T>& getVector();

    void afisareaPozitiei(int x);

    Gestiune& operator+=(const T&);

};


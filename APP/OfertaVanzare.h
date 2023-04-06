#pragma once;
#include "Oferta.h"
using namespace std;

class OfertaVanzare : public Oferta
{
private:
    double pretVanzare;
    int nrRate;

public:

    OfertaVanzare();
    OfertaVanzare(double pretVanzare, int nrRate, Imobil imobil, int comision);
    OfertaVanzare(const OfertaVanzare& o);
    OfertaVanzare operator=(const OfertaVanzare& o);
    ~OfertaVanzare();

    void setImobil(Imobil imobilNou);
    void setComision(int comisionNou);

    Imobil getImobil();
    int getComision();

    void setPretVanzare(double pretVanzareNou);
    void setNrRate(int nrRateNou);

    double getPretVanzare();
    int getNrRate();

    double sumaVanFinalAn();

    friend std::istream& operator>>(std::istream& in, OfertaVanzare& o);
    friend std::ostream& operator<<(std::ostream& out, OfertaVanzare& o);

    friend std::ifstream& operator>>(std::ifstream& in, OfertaVanzare& o);
    friend std::ofstream& operator<<(std::ofstream& out, OfertaVanzare& o);
    void scrieInFisierBinar(fstream& fisier);
    void citesteDinFisierBinar(fstream& fisier);
};

#pragma once;

#include "Oferta.h"

class OfertaInchiriere : public Oferta
{
private:
    double pretPerLuna;
    int nrLuniInchiriate;

public:

    OfertaInchiriere();
    OfertaInchiriere(double pretPerLuna, int nrLuniInchiriate, Imobil imobil, int comision);
    OfertaInchiriere(const OfertaInchiriere& o);
    OfertaInchiriere operator=(const OfertaInchiriere& o);
    ~OfertaInchiriere();

    void setImobil(Imobil imobilNou);
    void setComision(int comisionNou);

    Imobil getImobil();
    int getComision();

    void setPretPerLuna(double pretPerLunaNou);
    void setNrLuniInchiriate(int nrLuniInchiriateNou);

    double getPretPerLuna();
    int getNrLuniInchiriate();
    double sumaInchFinalAn();

    friend istream& operator>>(istream& in, OfertaInchiriere& o);
    friend ostream& operator<<(ostream& out, OfertaInchiriere& o);

    friend ifstream& operator>>(ifstream& in, OfertaInchiriere& o);
    friend ofstream& operator<<(ofstream& out, OfertaInchiriere& o);
    void scrieInFisierBinar(fstream& fisier);
    void citesteDinFisierBinar(fstream& fisier);
};

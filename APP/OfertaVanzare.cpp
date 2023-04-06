#include "OfertaVanzare.h"


OfertaVanzare::OfertaVanzare() : Oferta()
{
    this->pretVanzare = 0;
    this->nrRate = 0;
}

OfertaVanzare::OfertaVanzare(double pretVanzare, int nrRate, Imobil imobil, int comision) : Oferta(imobil, comision)
{
    this->pretVanzare = pretVanzare;
    this->nrRate = nrRate;
}

OfertaVanzare::OfertaVanzare(const OfertaVanzare& o)
{
    this->imobil = o.imobil;
    this->comision = o.comision;
    this->pretVanzare = o.pretVanzare;
    this->nrRate = o.nrRate;
}

OfertaVanzare OfertaVanzare::operator=(const OfertaVanzare& o)
{
    this->pretVanzare = o.pretVanzare;
    this->nrRate = o.nrRate;
    return *this;
}

OfertaVanzare::~OfertaVanzare()
{
}

void OfertaVanzare::setImobil(Imobil imobilNou)
{
    this->imobil = imobilNou;
}

void OfertaVanzare::setComision(int comisionNou)
{
    this->comision = comisionNou;
}

Imobil OfertaVanzare::getImobil()
{
    return this->imobil;
}

int OfertaVanzare::getComision()
{
    return this->comision;
}

void OfertaVanzare::setPretVanzare(double pretVanzareNou)
{
    this->pretVanzare = pretVanzareNou;
}

void OfertaVanzare::setNrRate(int nrRateNou)
{
    this->nrRate = nrRateNou;
}

double OfertaVanzare::getPretVanzare()
{
    return this->pretVanzare;
}

int OfertaVanzare::getNrRate()
{
    return this->nrRate;
}


double OfertaVanzare::sumaVanFinalAn()
{
    double sumaV = 0;
    this->pretVanzare = pretVanzare + (pretVanzare * comision);
    sumaV = sumaV + 12 * (pretVanzare / nrRate);

    return sumaV;
}

void OfertaVanzare::scrieInFisierBinar(fstream& fisier)
{
    fisier.write((char*)&imobil, sizeof(Imobil));
    fisier.write((char*)&comision, sizeof(int));
    fisier.write((char*)&pretVanzare, sizeof(double));
    fisier.write((char*)&nrRate, sizeof(int));
}

void OfertaVanzare::citesteDinFisierBinar(fstream& fisier)
{
    fisier.read((char*)&imobil, sizeof(Imobil));
    fisier.read((char*)&comision, sizeof(int));
    fisier.read((char*)&pretVanzare, sizeof(double));
    fisier.read((char*)&nrRate, sizeof(int));
}

std::istream& operator>>(istream& in, OfertaVanzare& o)
{
    cout << "Imobil:\n";
    in >> o.imobil;
    cout << "Comision: ";
    in >> o.comision;
    cout << "Pret Vanzare: ";
    in >> o.pretVanzare;
    cout << "Numar rate: ";
    in >> o.nrRate;
    return in;
}

std::ostream& operator<<(ostream& out, OfertaVanzare& o)
{
    cout << "Imobil:\n";
    out << o.imobil << endl;
    cout << "Comision: ";
    out << o.comision << endl;
    cout << "Pret Vanzare: ";
    out << o.pretVanzare << endl;
    cout << "Numar rate: ";
    out << o.nrRate << endl;
    return out;
}

std::ifstream& operator>>(ifstream& in, OfertaVanzare& o)
{
    in >> o.imobil;
    in >> o.comision;
    in >> o.pretVanzare;
    in >> o.nrRate;
    return in;
}

std::ofstream& operator<<(ofstream& out, OfertaVanzare& o)
{
    cout << "Imobil:\n";
    out << o.imobil;
    cout << "Comision: ";
    out << o.comision;
    cout << "Pret per luna: ";
    out << o.pretVanzare;
    cout << "Numar rate: ";
    out << o.nrRate;
    return out;
}
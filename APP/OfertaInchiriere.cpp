#include "OfertaInchiriere.h"

OfertaInchiriere::OfertaInchiriere() : Oferta()
{
    this->pretPerLuna = 0;
    this->nrLuniInchiriate = 0;
}

OfertaInchiriere::OfertaInchiriere(double pretPerLuna, int nrLuniInchiriate, Imobil imobil, int comision) : Oferta(imobil, comision)
{
    this->pretPerLuna = pretPerLuna;
    this->nrLuniInchiriate = nrLuniInchiriate;
}

OfertaInchiriere::OfertaInchiriere(const OfertaInchiriere& o)
{
    this->comision = o.comision;
    this->imobil = o.imobil;
    this->pretPerLuna = o.pretPerLuna;
    this->nrLuniInchiriate = o.nrLuniInchiriate;
}

OfertaInchiriere OfertaInchiriere::operator=(const OfertaInchiriere& o)
{
    this->pretPerLuna = o.pretPerLuna;
    this->nrLuniInchiriate = o.nrLuniInchiriate;
    return *this;
}

OfertaInchiriere::~OfertaInchiriere()
{
}

void OfertaInchiriere::setImobil(Imobil imobilNou)
{
    this->imobil = imobilNou;
}

void OfertaInchiriere::setComision(int comisionNou)
{
    this->comision = comisionNou;
}

Imobil OfertaInchiriere::getImobil()
{
    return this->imobil;
}

int OfertaInchiriere::getComision()
{
    return this->comision;
}

void OfertaInchiriere::setPretPerLuna(double pretPerLunaNou)
{
    this->pretPerLuna = pretPerLunaNou;
}

void OfertaInchiriere::setNrLuniInchiriate(int nrLuniInchiriateNou)
{
    this->nrLuniInchiriate = nrLuniInchiriateNou;
}

double OfertaInchiriere::getPretPerLuna()
{
    return this->pretPerLuna;
}

int OfertaInchiriere::getNrLuniInchiriate()
{
    return this->nrLuniInchiriate;
}


double OfertaInchiriere::sumaInchFinalAn()
{
    double sumaI = 0;
    this->pretPerLuna = pretPerLuna +(pretPerLuna * comision);
    if (nrLuniInchiriate > 11) {
        sumaI = sumaI + (12 * pretPerLuna);
    }
    else sumaI = sumaI + (nrLuniInchiriate * pretPerLuna);

    return sumaI;
}

void OfertaInchiriere::scrieInFisierBinar(fstream& fisier)
{
    fisier.write((char*)&imobil, sizeof(Imobil));
    fisier.write((char*)&comision, sizeof(int));
    fisier.write((char*)&pretPerLuna, sizeof(double));
    fisier.write((char*)&nrLuniInchiriate, sizeof(int));
}

void OfertaInchiriere::citesteDinFisierBinar(fstream& fisier)
{     
    fisier.read((char*)&imobil, sizeof(Imobil));
    fisier.read((char*)&comision, sizeof(int));
    fisier.read((char*)&pretPerLuna, sizeof(double));
    fisier.read((char*)&nrLuniInchiriate, sizeof(int));
}

std::istream& operator>>(istream& in, OfertaInchiriere& o)
{
    cout << "Imobil:\n";
    in >> o.imobil;
    cout << "Comision: ";
    in >> o.comision;
    cout << "Pret per luna: ";
    in >> o.pretPerLuna;
    cout << "Numar luni inchiriate: ";
    in >> o.nrLuniInchiriate;
    return in;
}

std::ostream& operator<<(ostream& out, OfertaInchiriere& o)
{
    cout << "Imobil:\n";
    out << o.imobil << endl;
    cout << "Comision: ";
    out << o.comision << endl;
    cout << "Pret per luna: ";
    out << o.pretPerLuna << endl;
    cout << "Numar luni inchiriate: ";
    out << o.nrLuniInchiriate << endl;
    return out;
}

std::ifstream& operator>>(ifstream& in, OfertaInchiriere& o)
{
    in >> o.imobil;
    in >> o.comision;
    in >> o.pretPerLuna;
    in >> o.nrLuniInchiriate;
    return in;
}

std::ofstream& operator<<(ofstream& out, OfertaInchiriere& o)
{
    cout << "Imobil:\n";
    out << o.imobil;
    cout << "Comision: ";
    out << o.comision;
    cout << "Pret per luna: ";
    out << o.pretPerLuna;
    cout << "Numar luni inchiriate: ";
    out << o.nrLuniInchiriate;
    return out;
}
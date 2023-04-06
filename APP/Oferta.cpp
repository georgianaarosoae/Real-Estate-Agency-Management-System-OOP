#include "Oferta.h"

Oferta::Oferta() : idOferta(0)
{
    this->comision = 0;
    
}

Oferta::Oferta(Imobil imobil, int comision) : idOferta(0)
{
    this->imobil = imobil;
    this->comision = comision;
}


Oferta::~Oferta(){}


void Oferta::scrieInFisierBinar(fstream& fisier)
{
	fisier.write((char*)&this->comision, sizeof(int));
	fisier.write((char*)&this->imobil, sizeof(Imobil));

}

void Oferta::citesteDinFisierBinar(fstream& fisier)
{
    fisier.read((char*)&this->comision, sizeof(int));
    fisier.read((char*)&this->imobil, sizeof(Imobil));
}

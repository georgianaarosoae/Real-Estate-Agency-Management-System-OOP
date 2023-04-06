#include "Locatie.h"

Locatie::Locatie()
{
	this->idLocatie = idLocatie++;
	denumireLocatie = "Necunoscuta";
	nrImobileDisponibilePerLocatie=0;
	nrImobileVandutePerLocatie=0;
	nrImobileInchiriatePerLocatie=0;
}


Locatie::Locatie(string denumireLocatie, int nrImobileDisponibilePerLocatie, int nrImobileVandutePerLocatie, int nrImobileInchiriatePerLocatie)
{
	if (TotalLocatii != NULL) {
		this->idLocatie = idLocatie++;
	}
	else throw Exceptie("Totalul locatiilor invalid!");
	this->denumireLocatie = denumireLocatie;
	this->nrImobileDisponibilePerLocatie = nrImobileDisponibilePerLocatie;
	this->nrImobileVandutePerLocatie = nrImobileVandutePerLocatie;
	this->nrImobileInchiriatePerLocatie = nrImobileInchiriatePerLocatie;
}

Locatie::Locatie(const Locatie& loc)
{
	if (TotalLocatii != NULL) {
		this->idLocatie = loc.TotalLocatii++;
	}
	
	this->denumireLocatie = loc.denumireLocatie;
	this->nrImobileDisponibilePerLocatie = loc.nrImobileDisponibilePerLocatie;
	this->nrImobileVandutePerLocatie = loc.nrImobileVandutePerLocatie;
	this->nrImobileInchiriatePerLocatie = loc.nrImobileInchiriatePerLocatie;
}

Locatie Locatie::operator=(const Locatie& loc)
{
	if (TotalLocatii != NULL) {
		this->idLocatie = TotalLocatii++;
	}
	
	this->denumireLocatie = denumireLocatie;
	this->nrImobileDisponibilePerLocatie = loc.nrImobileDisponibilePerLocatie;
	this->nrImobileVandutePerLocatie = loc.nrImobileVandutePerLocatie;
	this->nrImobileInchiriatePerLocatie = loc.nrImobileInchiriatePerLocatie;
	return *this;
}

string Locatie::getDenumireLocatie()
{
	return this->denumireLocatie;
}

void Locatie::setDebumireLocatie(string denumireNoua)
{
	if (denumireNoua.length() > 2) {
		this->denumireLocatie = denumireNoua;
	}
	else throw Exceptie("Denumire invalida!");
}

int Locatie::getNrImobileDisponibilePerLocatie()
{
	return nrImobileDisponibilePerLocatie;
}

void Locatie::setNrImobileDisponibilePerLocatie(int nrImobileDisponibilePerLocatie)
{
	if (nrImobileDisponibilePerLocatie != NULL) {
		this->nrImobileDisponibilePerLocatie = nrImobileDisponibilePerLocatie;
	}
	else throw Exceptie("Numar invalid!");
}

int Locatie::getNrImobileVandutePerLocatie()
{
	return nrImobileVandutePerLocatie;
}

void Locatie::setNrImobileVandutePerLocatie(int nrImobileVandutePerLocatie)
{
	if (nrImobileVandutePerLocatie != NULL) {
		this->nrImobileVandutePerLocatie = nrImobileVandutePerLocatie;
	}
	else throw Exceptie("Invalid");
}

int Locatie::getNrImobileInchiriatePerLocatie()
{
	return nrImobileInchiriatePerLocatie;
}

void Locatie::setNrImobileInchiriatePerLocatie(int nrImobileInchiriatePerLocatie)
{
	if (nrImobileInchiriatePerLocatie != NULL) {
		this->nrImobileInchiriatePerLocatie = nrImobileInchiriatePerLocatie;
	}
	else throw Exceptie("Invalid");
}
void Locatie::vanzareImobil()
{
	nrImobileVandutePerLocatie++;
	nrImobileDisponibilePerLocatie--;
}

void Locatie::inchiriereImobil()
{
	nrImobileInchiriatePerLocatie++;
	nrImobileDisponibilePerLocatie--;
}

void Locatie::imobilNouDisponibil()
{
	nrImobileDisponibilePerLocatie++;
}

void Locatie::imobilIndisponibil()
{
	nrImobileDisponibilePerLocatie--;
}

Locatie Locatie::operator++()
{
	Locatie aux = *this;
	this->nrImobileDisponibilePerLocatie++;
	return aux;
}

Locatie Locatie::operator+=(int valoare)
{
	this->nrImobileDisponibilePerLocatie += valoare;
	return *this;
}

bool Locatie::operator<(Locatie loc)
{
	if (this->nrImobileDisponibilePerLocatie < loc.nrImobileDisponibilePerLocatie) {
		return true;
	}
	else
	{
		return false;
	}
}

bool Locatie::operator!()
{
	if (nrImobileInchiriatePerLocatie = nrImobileVandutePerLocatie) {
		return false;
	}
	else
	{
		return true;
	}
}
void Locatie::citesteDinFisierBinar(fstream& fisier) {
	fisier.write((char*)&idLocatie, sizeof(int));
	fisier.write((char*)&denumireLocatie, sizeof(string));
	fisier.write((char*)&nrImobileDisponibilePerLocatie, sizeof(int));
	fisier.write((char*)&nrImobileVandutePerLocatie, sizeof(int));
	fisier.write((char*)&nrImobileInchiriatePerLocatie, sizeof(int));
}
void Locatie::scrieInFisierBinar(fstream& fisier)
{
	fisier.write((char*)&idLocatie, sizeof(int));
	fisier.write((char*)&denumireLocatie, sizeof(string));
	fisier.write((char*)&nrImobileDisponibilePerLocatie, sizeof(int));
	fisier.write((char*)&nrImobileVandutePerLocatie, sizeof(int));
	fisier.write((char*)&nrImobileInchiriatePerLocatie, sizeof(int));
}

ostream& operator<<(ostream& out, Locatie& loc)
{
	out <<"Id:"<< loc.idLocatie << endl;
	out << "Denumire locatie: "<<loc.denumireLocatie << endl;
	out << "Numar Imobile Disponibile Per Locatie "<<loc.nrImobileDisponibilePerLocatie << endl;
	out << "Numar Imobile Vandute Per Locatie "<<loc.nrImobileVandutePerLocatie << endl;
	out << "Numar Imobile Inchiriate Per Locatie " << loc.nrImobileInchiriatePerLocatie << endl;
	return out;
}

istream& operator>>(istream& in, Locatie& loc)
{
	cout << "Citeste denumire locatie:";
	in >> loc.denumireLocatie;
	cout << "Citeste nrImobileDisponibilePerLocatie:";
	in >> loc.nrImobileDisponibilePerLocatie;
	cout << "Citeste nrImobileVandutePerLocatie:";
	in >> loc.nrImobileVandutePerLocatie;
	cout << "Citeste nrImobileInchiriatePerLocatie:";
	in >> loc.nrImobileInchiriatePerLocatie;
	return in;
}

ofstream& operator<<(ofstream& ofs, Locatie& loc)
{
	ofs << "Id. Locatie: " << loc.idLocatie << endl;
	ofs << "Denumire Locatie: " << loc.denumireLocatie << endl;
	ofs << "Numar de imobile disponibile per locatie " << loc.nrImobileDisponibilePerLocatie << endl;
	ofs << "Numar imobile vandute per locatie: " << loc.nrImobileVandutePerLocatie << endl;
	ofs << "Numar imobile inchiriate per locatie: " << loc.nrImobileInchiriatePerLocatie << endl;

	return ofs;
}

ifstream& operator>>(ifstream& ifs, Locatie& loc)
{
	ifs >> loc.denumireLocatie;
	ifs >> loc.nrImobileDisponibilePerLocatie;
	ifs >> loc.nrImobileVandutePerLocatie;
	ifs >> loc.nrImobileInchiriatePerLocatie;
	return ifs;

}
Locatie:: ~Locatie() {

}




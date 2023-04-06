#include "AgentieImobiliara.h"
int AgentieImobiliara::numarTotalImobile = 10;
AgentieImobiliara::AgentieImobiliara()
{
	denumire = "";
	telefon = "";
	adresa = "";
	CUI = nullptr;
	numarTotalImobile = 0;
	orar = Orar();
	locatii = vector<Locatie>();
	oferte = vector<Oferta*>();
}

AgentieImobiliara::AgentieImobiliara(const string denumire, string telefon, string adresa, char* CUI, int numarTotalImobile, Orar orar, vector<Locatie> locatii)
{
	this->denumire = denumire;
	this->telefon = telefon;
	this->adresa = adresa;
	if (CUI != nullptr)
	{
		this->CUI = new char[strlen(CUI) + 1];
		strcpy(this->CUI, CUI);
	}
	else
	{
		this->CUI = nullptr;
	}
	this->numarTotalImobile = numarTotalImobile;
	this->orar = orar;
	this->locatii = locatii;
	oferte = vector<Oferta*>();
	
}

AgentieImobiliara::AgentieImobiliara(const AgentieImobiliara& a)
{
	this->denumire = a.denumire;
	this->telefon = a.telefon;
	this->adresa = a.adresa;
	if (a.CUI != nullptr)
	{
		this->CUI = new char[strlen(a.CUI) + 1];
		strcpy(this->CUI, a.CUI);
	}
	else
	{
		this->CUI = nullptr;
	}
	this->numarTotalImobile = a.numarTotalImobile;
	this->orar = a.orar;
	this->locatii = a.locatii;
	this->oferte = a.oferte;
}

AgentieImobiliara::~AgentieImobiliara()
{
	if (CUI != nullptr)
	{
		delete[] CUI;
	}
}

void AgentieImobiliara::setDenumire(string denumireNoua)
{
	this->denumire = denumireNoua;
}

void AgentieImobiliara::setTelefon(string telefonNou)
{
	this->telefon = telefonNou;
}

void AgentieImobiliara::setAdresa(string adresaNoua)
{
	this->adresa = adresaNoua;
}

void AgentieImobiliara::setCUI(char* CUI)
{
	if (CUI != nullptr)
	{
		this->CUI = new char[strlen(CUI) + 1];
		strcpy(this->CUI, CUI);
	}
	else
	{
		this->CUI = nullptr;
	}
}

void AgentieImobiliara::setNumarTotalImobile(int numarTotalImobileNou)
{
	this->numarTotalImobile = numarTotalImobileNou;
}

void AgentieImobiliara::setOrar(Orar orarNou)
{
	this->orar = orarNou;
}

void AgentieImobiliara::setImobile(vector<Locatie> locatiiNoi)
{
	this->locatii = locatii;
}

void AgentieImobiliara::setOferte(vector<Oferta*> oferteNoi)
{
	oferte = oferteNoi;
}

string AgentieImobiliara::getDenumire()
{
	return this->denumire;
}

string AgentieImobiliara::getTelefon()
{
	return this->telefon;
}

string AgentieImobiliara::getAdresa()
{
	return this->adresa;
}

char* AgentieImobiliara::getCUI()
{
	return this->CUI;
}

int AgentieImobiliara::getNumarTotalImobile()
{
	return this->numarTotalImobile;
}

Orar AgentieImobiliara::getOrar()
{
	return this->orar;
}

std::vector<Locatie> AgentieImobiliara::getImobile()
{
	return this->locatii;
}

vector<Oferta*> AgentieImobiliara::getOferte()
{
	return oferte;
}

void AgentieImobiliara::adaugaOferta(OfertaInchiriere oferta)
{
	oferte.push_back(&oferta);
}

void AgentieImobiliara::stergeOferta(OfertaInchiriere oferta)
{
	oferte.erase(std::remove(oferte.begin(), oferte.end(), &oferta), oferte.end());
}

void AgentieImobiliara::adaugaOferta(OfertaVanzare oferta)
{
	oferte.push_back(&oferta);
}

void AgentieImobiliara::stergeOferta(OfertaVanzare oferta)
{
	oferte.erase(remove(oferte.begin(), oferte.end(), &oferta), oferte.end());
}

double AgentieImobiliara::sumaFinalAn()
{
	int suma = 0;
	for (int i = 0; i < oferte.size(); ++i)
	{
		OfertaInchiriere* castOfertaInchiriere = dynamic_cast<OfertaInchiriere*>(oferte[i]);
		OfertaVanzare* castOfertaVanzare = dynamic_cast<OfertaVanzare*>(oferte[i]);
		if (castOfertaInchiriere)
		{
			suma += castOfertaInchiriere->sumaInchFinalAn();
		}
		else if (castOfertaVanzare)
		{
			suma += castOfertaVanzare->sumaVanFinalAn();
		}
	}

	return suma;

	
}

AgentieImobiliara& AgentieImobiliara::operator=(const AgentieImobiliara& a)
{
	this->denumire = a.denumire;
	this->telefon = a.telefon;
	this->adresa = a.adresa;
	if (a.CUI != nullptr)
	{
		this->CUI = new char[strlen(a.CUI) + 1];
		strcpy(this->CUI, a.CUI);
	}
	else
	{
		this->CUI = nullptr;
	}
	this->numarTotalImobile = a.numarTotalImobile;
	this->orar = a.orar;
	this->locatii = a.locatii;
	return *this;
}


void AgentieImobiliara::scrieInFisierBinar(fstream& fisier)
{
	int length = denumire.length(); 
	fisier.write((char*)&length, sizeof(length));
	    fisier.write(denumire.c_str(), length+1);
		length = telefon.length();
		fisier.write((char*)&length, sizeof(length));
		fisier.write(telefon.c_str(), length+1);
		vector<Locatie>::iterator it;
		it = locatii.begin() + 1;
		for ( it = locatii.begin(); it != locatii.end(); it++) 
		{
			fisier.write((char*)&*it, sizeof(char));
		}
		fisier.write((char*)&this->orar, sizeof(string));
		fisier.write((char*)&this->adresa, sizeof(string));
		fisier.write((char*)&this->CUI, sizeof(char));
		fisier.write((char*)&this->numarTotalImobile, sizeof(int));
}

void AgentieImobiliara::citesteDinFisierBinar(fstream& fisier){
	fisier.read((char*)&denumire, sizeof(string));
	fisier.read((char*)&telefon, sizeof(string));
	vector<Locatie>::iterator it;
	it = locatii.begin() + 1;
	for (it = locatii.begin(); it != locatii.end(); it++)
	{
		fisier.read((char*)&*it, sizeof(char));
	}
	fisier.read((char*)&this->orar, sizeof(string));
	fisier.read((char*)&this->adresa, sizeof(string));
	fisier.read((char*)&this->CUI, sizeof(char));
	fisier.read((char*)&this->numarTotalImobile, sizeof(int));
}

istream& operator>>(istream& in, AgentieImobiliara& a)
{
	cout << "Denumire: ";
	in >> a.denumire;
	cout << "Telefon: ";
	in >> a.telefon;
	cout << "Adresa: ";
	in >> a.adresa;
	cout << "CUI: ";
	char buffer[100];
	in >> buffer;
	if (a.CUI != nullptr)
	{
		delete[] a.CUI;
	}
	a.CUI = new char[strlen(buffer) + 1];
	strcpy(a.CUI, buffer);
	cout << "Numar total: ";
	in >> a.numarTotalImobile;
	cout << "Orar: ";
	in >> a.orar;
	cout << "Numar imobile: ";
	int numarImobile;
	in >> numarImobile;
	for (int i = 0; i < numarImobile; i++)
	{
		Locatie locatie;
		in >> locatie;
		a.locatii.push_back(locatie);
	}
	return in;
}

ostream& operator<<(ostream& out, AgentieImobiliara& a)
{
	out << "Denumire: " << a.denumire << endl;
	out << "Telefon: " << a.telefon << endl;
	out << "Adresa: " << a.adresa << endl;
	out << "CUI: " << a.CUI << endl;
	out << "Numar total imobile: " << a.numarTotalImobile << endl;
	out << "Orar: " << a.orar << endl;
	/*out << "Locatii: " << endl;
	for (int i = 0; i < a.locatii.size(); i++)
	{
		out << a.locatii[i] << endl;
	}*/
	return out;
}

ifstream& operator>>(ifstream& in, AgentieImobiliara& a)
{
	getline(in, a.denumire);
	getline(in, a.telefon);
	getline(in,a.adresa);
	in >> a.CUI;
	in >> a.numarTotalImobile;
	in >> a.orar;
	int numarImobile;
	in >> numarImobile;
	for (int i = 0; i < numarImobile; i++)
	{
		Locatie locatie;
		in >> locatie;
		a.locatii.push_back(locatie);
	}
	return in;
}

ofstream& operator<<(ofstream& ofs, AgentieImobiliara& a)
{
	ofs << "Denumire: " << a.denumire << endl;
	ofs << "Telefon: " << a.telefon << endl;
	ofs << "Adresa: " << a.adresa << endl;
	ofs << "CUI: " << a.CUI << endl;
	ofs << "Numar total imobile: " << a.numarTotalImobile << endl;
	ofs << "Orar: " <<endl<< a.orar << endl;
	/*out << "Locatii: " << endl;
	for (int i = 0; i < a.locatii.size(); i++)
	{
		out << a.locatii[i] << endl;
	}*/

	return ofs;
}
#include "Imobil.h"
#include "Utils.h"

Imobil::Imobil() : id(++numarImobile)
{
	suprafata = 0;
	nrCamere = 0;
	camere = map<string, int>();
	utilat = false;
	adresa = "";
	zona = nullptr;
	dotari = vector<string>();
}

Imobil::Imobil(double suprafata, int nrCamere, bool utilat, string adresa, const char* zona, vector<string> dotari) : id(++numarImobile)
{
	this->suprafata = suprafata;
	this->nrCamere = nrCamere;
	this->camere = map<string, int>();
	this->utilat = utilat;
	this->adresa = adresa;
	if (zona != nullptr)
	{
		this->zona = new char[strlen(zona) + 1];
		strcpy(this->zona, zona);
	}
	else
	{
		this->zona = nullptr;
	}
	this->dotari = dotari;
}

Imobil::Imobil(const Imobil& i) : id(++numarImobile)
{
	this->suprafata = i.suprafata;
	this->nrCamere = i.nrCamere;
	this->camere = i.camere;
	this->utilat = i.utilat;
	this->adresa = i.adresa;
	if (i.zona != nullptr)
	{
		this->zona = new char[strlen(i.zona) + 1];
		strcpy(this->zona, i.zona);
	}
	else
	{
		this->zona = nullptr;
	}
	this->dotari = i.dotari;
}

Imobil Imobil::operator=(const Imobil& i)
{
	this->suprafata = i.suprafata;
	this->nrCamere = i.nrCamere;
	this->camere = i.camere;
	this->utilat = i.utilat;
	this->adresa = i.adresa;
	if (i.zona != nullptr)
	{
		this->zona = new char[strlen(i.zona) + 1];
		strcpy(this->zona, i.zona);
	}
	else
	{
		this->zona = nullptr;
	}
	this->dotari = i.dotari;
	return *this;
}

Imobil::~Imobil()
{
	if (zona != nullptr)
	{
		delete[] zona;
	}
}

void Imobil::setSuprafata(double suprafataNoua)
{
	if (suprafataNoua > 0)
	{
		suprafata = suprafataNoua;
	}
	else
	{
		throw Exceptie("Suprafata nu poate fi negativa!");
	}
}

double Imobil::getSuprafata()
{
	return suprafata;
}

void Imobil::setNrCamere(int nrCamereNou)
{
	if (nrCamereNou > 0)
	{
		nrCamere = nrCamereNou;
	}
	else
	{
		throw Exceptie("Numarul de camere nu poate fi negativ!");
	}
}

int Imobil::getNrCamere()
{
	return nrCamere;
}

void Imobil::setCamare(std::map<string, int> camereNou)
{
	camere = camereNou;
}

std::map<string, int> Imobil::getCamere()
{
	return camere;
}

void Imobil::setUtilat(bool utilatNou)
{
	utilat = utilatNou;
}

bool Imobil::getUtilat()
{
	return utilat;
}

void Imobil::setAdresa(string adresaNoua)
{
	adresa = adresaNoua;
}

string Imobil::getAdresa()
{
	return adresa;
}

void Imobil::setZona(const char* zonaNoua)
{
	if (zona != nullptr)
	{
		delete[] zona;
	}
	if (zonaNoua != nullptr)
	{
		zona = new char[strlen(zonaNoua) + 1];
		strcpy(zona, zonaNoua);
	}
	else
	{
		zona = nullptr;
	}
}

char* Imobil::getZona()
{
	return zona;
}

void Imobil::setDotari(vector<string> dotariNou)
{
	dotari = dotariNou;
}

vector<string> Imobil::getDotari()
{
	return dotari;
}

bool Imobil::operator==(const Imobil& i)
{
	return suprafata == i.suprafata && nrCamere == i.nrCamere && camere == i.camere && utilat == i.utilat && adresa == i.adresa && strcmp(zona, i.zona) == 0 && dotari == i.dotari;
}

istream& operator>>(istream& in, Imobil& i)
{
	cout << "Suprafata: ";
	string suprafata;
	getline(in, suprafata);
	i.suprafata = stod(suprafata); // stod = string to double
	cout << "Numar camere: ";
	string nrCamere;
	getline(in, nrCamere);
	i.nrCamere = stoi(nrCamere.size() == 0 ? "0" : nrCamere); // stoi = string to int
	cout << "Camere: " << endl;
	cout << "Bucatarie: ";
	string bucatarie;
	getline(in, bucatarie);
	i.camere["bucatarie"] = stoi(bucatarie.size() == 0 ? "0" : bucatarie);
	cout << "Living: ";
	string living;
	getline(in, living);
	i.camere["living"] = stoi(living.size() == 0 ? "0" : living);
	cout << "Dormitor: ";
	string dormitor;
	getline(in, dormitor);
	i.camere["dormitor"] = stoi(dormitor.size() == 0 ? "0" : dormitor);
	cout << "Baie: ";
	string baie;
	getline(in, baie);
	i.camere["baie"] = stoi(baie.size() == 0 ? "0" : baie);
	string utilat;
	while (true)
	{
		cout << "Utilat: ";
		getline(in, utilat);
		if ([](string str) -> bool
			{ transform(str.begin(), str.end(), str.begin(), ::tolower); return str == "da"; }(utilat))
		{
			i.utilat = true;
			break;
		}
		else if ([](string str) -> bool
			{ transform(str.begin(), str.end(), str.begin(), ::tolower); return str == "nu"; }(utilat))
		{
			i.utilat = false;
			break;
		}
		else
		{
			cout << "Raspunsul trebuie sa fie DA sau NU!" << endl;
		}
	}
	cout << "Adresa: ";
	getline(in, i.adresa);
	cout << "Zona: ";
	char buffer[100];
	in.getline(buffer, 100);
	if (i.zona != nullptr)
	{
		delete[] i.zona;
	}
	i.zona = new char[strlen(buffer) + 1];
	strcpy(i.zona, buffer);
	cout << "Dotari: " << endl;
	string dotare;
	while (true)
	{
		cout << "Nume dotare: ";
		getline(in, dotare);
		if ([](string str) -> bool
			{ transform(str.begin(), str.end(), str.begin(), ::tolower); return str == "stop" || str == ""; }(dotare))
		{
			break;
		}
		transform(dotare.begin(), dotare.end(), dotare.begin(), ::tolower);
		i.dotari.push_back(dotare);
	}
	return in;
}

ostream& operator<<(ostream& out, Imobil i)
{
	out << "Suprafata: " << i.suprafata << endl;
	out << "Numar camere: " << i.nrCamere << endl;
	out << "Camere: " << endl;
	for (auto camera : i.camere)
	{
		out << camera.first << ": " << camera.second << endl;
	}
	out << "Utilat: " << i.utilat << endl;
	out << "Adresa: " << i.adresa << endl;
	out << "Zona: " << i.zona << endl;
	out << "Dotari: " << endl;
	for (auto dotare : i.dotari)
	{
		out << dotare << " ";
	}
	out << endl;
	return out;
}

ifstream& operator>>(ifstream& ifs, Imobil& i) 
{
	map<string, string> date;
	string line;
	while (getline(ifs, line))
	{
		if (line == "")
		{
			break;
		}
		pair<string, string> rezultat = Utils().citireLinie(line);
		date.insert(rezultat);
	}
	i.suprafata = stoi(date["Suprafata"].size() == 0 ? "0" : date["Suprafata"]);
	i.nrCamere = stoi(date["Numar Camere"].size() == 0 ? "0" : date["Numar Camere"]);

	i.camere["bucatarie"] = stoi(date["Bucatarie"].size() == 0 ? "0" : date["Bucatarie"]);
	i.camere["living"] =stoi(date["Living"].size() == 0 ? "0" : date["Living"]);
	i.camere["dormitor"] =stoi(date["Dormitor"].size() == 0 ? "0" : date["Dormitor"]);
	i.camere["baie"] = stoi(date["Baie"].size() == 0 ? "0" : date["Baie"]);

	i.utilat = date["Utilat"] == "DA" ? true : false;
	i.adresa = date["Adresa"];
	if (i.zona != nullptr)
	{
		delete[] i.zona;
	}
	i.zona = new char[strlen(date["Zona"].c_str()) + 1];
	strcpy(i.zona, date["Zona"].c_str());
	i.dotari = Utils().citireDotari(date["Dotari"]);
	return ifs;
}

ofstream& operator<<(ofstream& ofs, Imobil i)
{
	ofs << i.suprafata << endl;
	ofs << i.nrCamere << endl;
	ofs << i.utilat << endl;
	ofs << i.adresa << endl;
	ofs << i.zona << endl;
	for (auto dotare : i.dotari)
	{
		ofs << dotare << ", ";
	}
	ofs << endl;
	return ofs;
}
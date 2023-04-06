#include "Orar.h"
#include "Exceptie.h"
Orar::Orar()
{
	strcpy(primaZi, "Luni");
	strcpy(ultimaZi, "Sambata");
	intervalOrar = new char[strlen("09:00-22:00") + 1];
	strcpy(intervalOrar, "09:00-22:00");
	startOra = 9;
	stopOra = 22;
}

Orar::Orar(const char primaZi[], const char ultimaZi[], const char intervalOrar[], int startOra, int stopOra)
{
	strcpy(this->primaZi, primaZi);
	strcpy(this->ultimaZi, ultimaZi);
	this->intervalOrar = new char[strlen(intervalOrar) + 1];
	strcpy(this->intervalOrar, intervalOrar);
	this->startOra = startOra;
	this->stopOra = stopOra;
}

Orar::Orar(const Orar& o)
{
	strcpy(this->primaZi, o.primaZi);
	strcpy(this->ultimaZi, o.ultimaZi);
	this->intervalOrar = new char[strlen(o.intervalOrar) + 1];
	strcpy(this->intervalOrar, o.intervalOrar);
	this->startOra = o.startOra;
	this->stopOra = o.stopOra;
}

Orar Orar::operator=(const Orar& o)
{
	if (o.primaZi != NULL) {
		strcpy(this->primaZi, o.primaZi);
	}
	if (o.ultimaZi != NULL) {
		strcpy(this->ultimaZi, o.ultimaZi);
	}
	if (o.intervalOrar != NULL) {
		if (this->intervalOrar != NULL) {
			delete[] this->intervalOrar;
			this->intervalOrar = nullptr;
		}
		this->intervalOrar = new char[strlen(o.intervalOrar) + 1];
		strcpy(this->intervalOrar, o.intervalOrar);
	}
	this->startOra = startOra;
	this->stopOra = stopOra;
	return *this;
}

char* Orar::getPrimaZi()
{
	return primaZi;
}

void Orar::setPrimaZi(const char primaZiNoua[])
{
	if (strlen(primaZiNoua) < 9) strcpy(primaZi, primaZiNoua);
	else throw Exceptie("Invalid!");
}

char* Orar::getUltimaZi()
{
	return ultimaZi;
}

void Orar::setUltimaZi(const char ultimaZiNoua[])
{
	if (strlen(ultimaZiNoua) < 9) strcpy(ultimaZi, ultimaZiNoua);
	else throw Exceptie("Invalid!");
}

char* Orar::getIntervalOrar()
{
	return intervalOrar;
}

void Orar::setIntervalOrar(const char intervalOrarNou[])
{
	if (intervalOrarNou != NULL) {
		if (intervalOrar != NULL) {
			delete[] this->intervalOrar;
		}
		this->intervalOrar = new char[strlen(intervalOrarNou) + 1];
		strcpy(this->intervalOrar, intervalOrarNou);
	}
	else throw Exceptie("Invalid!");
}

int Orar::getStartOra()
{
	return startOra;
}

void Orar::setStartOra(int startOraNoua)
{
	if (startOraNoua != 0) {
		startOra = startOraNoua;
	}else throw Exceptie("Ora invalida!");
}

int Orar::getStopOra()
{
	return stopOra;
}

void Orar::setStopOra(int stopOraNoua)
{
	if (stopOraNoua != 0) {
		stopOra = stopOraNoua;
	}
	else throw Exceptie("Ora invalida!");
}

Orar::~Orar()
{
	if (this->intervalOrar != nullptr)
	{
		delete[]this->intervalOrar;
		this->intervalOrar = nullptr;
	}
}

Orar::operator int()
{
	return stopOra - startOra;
}

void Orar::citesteDinFisierBinar(fstream& fisier)
{
	fisier.write((char*)&primaZi, sizeof(primaZi));
	fisier.write((char*)&ultimaZi, sizeof(ultimaZi));
	fisier.write((char*)&intervalOrar, sizeof(intervalOrar));
	fisier.write((char*)&startOra, sizeof(startOra));
	fisier.write((char*)&stopOra, sizeof(stopOra));
}

void Orar::scrieInFisierBinar(fstream& fisier)
{
	fisier.read((char*)&primaZi, sizeof(primaZi));
	fisier.read((char*)&ultimaZi, sizeof(ultimaZi));
	fisier.read((char*)&intervalOrar, sizeof(intervalOrar));
	fisier.read((char*)&startOra, sizeof(startOra));
	fisier.read((char*)&stopOra, sizeof(stopOra));
}

istream& operator>>(istream& in, Orar& o)
{
	char aux1[9];
	do {
		cout << "Introdu prima zi a programului de lucru (Luni...Duminica): ";
		in >> aux1;
	} while (!Orar::ZiCorecta(aux1));
	strcpy(o.primaZi, aux1);

	char aux2[9];
	do {
		cout << "Introdu ultima zi a programului de lucru (Luni...Duminica): ";
		in >> aux2;
	} while (!Orar::ZiCorecta(aux2));
	strcpy(o.ultimaZi, aux2);

	cout << "Introdu intervalul Orar al programului de lucru de forma xx:xx-xx:xx: ";
	char aux3[12];
	in >> aux3;
	strcpy(o.intervalOrar, aux3);
		cout << "Prima ora a programului de lucru de forma xx: " << endl;
		in >> o.startOra;
		cout << "Ultima ora a programului de lucru de forma xx: " << endl;
		in >> o.stopOra;
		if (o.startOra > o.stopOra) throw Exceptie("Interval Orar gresit.");
	return in;
}

ostream& operator<<(ostream& out, Orar& o)
{
	out << "Prima zi a programului de lucru: " << o.primaZi << endl;
	out << "Ultima zi a programului de lucru: " << o.ultimaZi << endl;
	out << "Intervalul orar al programului de lucru: " << o.intervalOrar << endl;
	out << "Prima ora a programului de lucru: " << o.startOra << endl;
	out << "Ultima ora a programului de lucru: " << o.stopOra << endl;
	return out;
}

ifstream& operator>>(ifstream& ifs, Orar& o)
{
	ifs >> o.primaZi;
	ifs >> o.ultimaZi;
	ifs >> o.intervalOrar;
	ifs >> o.startOra;
	ifs >> o.stopOra;
	return ifs;
}

ofstream& operator<<(ofstream& ofs, Orar& o)
{
	ofs << "Prima zi a programului de lucru: " << o.primaZi << endl;
	ofs << "Ultima zi a programului de lucru: " << o.ultimaZi << endl;
	ofs << "Intervalul orar al programului de lucru: " << o.intervalOrar << endl;
	//ofs << "Prima ora a programului de lucru: " << o.startOra << endl;
	//ofs << "Ultima ora a programului de lucru: " << o.stopOra << endl;
	return ofs;
}

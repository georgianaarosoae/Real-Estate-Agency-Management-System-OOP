#pragma once
//#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include<iostream>
#include <fstream>
using namespace std;

class Orar
{ 
private:
	char primaZi[9]; //prima zi a saptamanii cand este deschis sediul
	char ultimaZi[9]; //ultima zi a saptamanii cand este deschis sediul
	char* intervalOrar; //intervalul orar in care putem gasi deschis sediul
	int startOra; //ora de inceput a programului, varianta int pentru a lucra cu ele
	int stopOra;//ora de final de program
	static int ZiCorecta(char zi[]) {
		if (strcmp(zi, "Luni") == 0) return 1;
		if (strcmp(zi, "Marti") == 0) return 1;
		if (strcmp(zi, "Miercuri") == 0) return 1;
		if (strcmp(zi, "Joi") == 0) return 1;
		if (strcmp(zi, "Vineri") == 0) return 1;
		if (strcmp(zi, "Samabata") == 0) return 1;
		if (strcmp(zi, "Duminica") == 0) return 1;
		return 0;
	}
public:
	Orar();
	Orar(const char primaZi[], const char ultimaZi[], const char intervalOrar[], int startOra, int stopOra);
	Orar(const Orar&);
	Orar operator=(const Orar& o);
	char* getPrimaZi();
	void setPrimaZi(const char primaZiNoua[]);

	char* getUltimaZi();
	void setUltimaZi(const char ultimaZiNoua[]);
	char* getIntervalOrar();
	void setIntervalOrar(const char intervalOrarNou[]);
	int getStartOra();
	void setStartOra(int startOraNoua);
	int getStopOra();
	void setStopOra(int stopOraNoua);
	~Orar();
	operator int();
	friend istream& operator>>(istream& in, Orar& o);
	friend ostream& operator<<(ostream& out, Orar& o);		
	friend ifstream& operator>>(ifstream& ifs, Orar& o);
	friend ofstream& operator<<(ofstream& ofs, Orar& o);
	void citesteDinFisierBinar(fstream& fisier);
	void scrieInFisierBinar(fstream& fisier);

};




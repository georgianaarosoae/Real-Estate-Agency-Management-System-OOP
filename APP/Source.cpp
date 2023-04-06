
#include<iostream>
#include "Meniu.h"
#include "Exceptie.h"
#include "Orar.h"
#include "Locatie.h"
#include "Imobil.h"
#include "AgentieImobiliara.h"
#include "OfertaInchiriere.h"
#include "OfertaVanzare.h"
#include "Gestiune.h"
#include <windows.h>
#include <conio.h>
#include <map>
#include <string>
#include<fstream>
using namespace std;

int Locatie::TotalLocatii = 1;
int Imobil::numarImobile = 0;
//int AgentieImobiliara::numarTotalImobile =10;


template <>
class Gestiune<Locatie>
{
	Locatie l;
	vector<Locatie> obiecte;
public:
	Gestiune(){}
	~Gestiune() = default;
	int getNrObiecte();
	vector<Locatie>& getVector();
	void afisareaPozitiei(int x);
	Gestiune& operator+=(const Locatie& l);
};
int Gestiune<Locatie>::getNrObiecte() {
	return this->obiecte.size();
}
vector<Locatie>& Gestiune<Locatie>::getVector() {
	return obiecte;
}



int main() {
	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE); //PENTRU CULORI
	
	Orar orar;

	Locatie l1("Pipera",1,3,4);
	Locatie l2("Aviatorilor", 1, 6, 3);
	Locatie l3("Titan", 1, 0, 2);
	Locatie l4("Berceni", 1, 2, 1);
	Locatie l5("Central", 1, 5, 1);
	Locatie l6("Vitan",1,2,3);
	Locatie l7("Obor", 1, 1, 2);
	Locatie l8("Tineretului", 1, 3, 2);
	Locatie l9("Primaverii", 1, 2, 4);
	Locatie l10("Crangasi", 1, 1, 2);

	vector<Locatie>locatii;
	locatii.push_back(l1);
	locatii.push_back(l2);
	locatii.push_back(l3);
	locatii.push_back(l4);
	locatii.push_back(l5);
	locatii.push_back(l6);
	locatii.push_back(l7);
	locatii.push_back(l8);
	locatii.push_back(l9);
	locatii.push_back(l10);

	vector<string>dotari1;
	vector<string>dotari2;
	vector<string>dotari3;
	vector<string>dotari4;
	vector<string>dotari5;
	vector<string>dotari6;
	vector<string>dotari7;
	vector<string>dotari8;
	vector<string>dotari9;
	vector<string>dotari10;

	dotari1.push_back("Da");
	dotari2.push_back("Da");
	dotari3.push_back("Nu");
	dotari4.push_back("Da");
	dotari5.push_back("Da");
	dotari6.push_back("Da");
	dotari7.push_back("Da");
	dotari8.push_back("Nu");
	dotari9.push_back("Da");
	dotari10.push_back("Da");

	char* CUI = new char[30];
	strcpy(CUI, "123456789");

	AgentieImobiliara ag("Agentie Imobiliara", "0745 123 456", "Strada Liniei, nr. 1", CUI, 10, Orar(), locatii);
	 
	Imobil* imobil;
	imobil = new Imobil[10];
	Imobil imobil1(62, 2, 1, "Str. 1 Decembrie", "Pipera", dotari1);
	Imobil imobil2(70, 3, 1, "Str. 24 Decembrie", "Aviatorilor", dotari2);
	Imobil imobil3(100, 4, 1, "Str. Soarelui", "Titan", dotari3);
	Imobil imobil4(51, 2, 1, "Str. 1 Decembrie", "Berceni", dotari4);
	Imobil imobil5(55, 2, 1, "Str. Florilor", "Central", dotari5);
	Imobil imobil6(15, 1, 1, "Str. Scolii", "Vitan", dotari6);
	Imobil imobil7(38, 1, 1, "Str. 1 Decembrie", "Obor", dotari7);
	Imobil imobil8(600, 10, 1, "Str. 1 Februarie", "Tineretului", dotari8);
	Imobil imobil9(470, 6, 1, "Str. Mihai Eminescu", "Primaverii", dotari9);
	Imobil imobil10(390, 4, 1, "Str. Partesii Noi", "Crangasi", dotari10);
	
	OfertaInchiriere ofertaInchiriere1(400, 12, imobil1, 0);
	OfertaInchiriere ofertaInchiriere2(500, 24, imobil2, 0);
	OfertaInchiriere ofertaInchiriere3(650, 12, imobil3, 0);
	OfertaInchiriere ofertaInchiriere4(350, 6, imobil4, 0);
	OfertaInchiriere ofertaInchiriere5(320, 12, imobil5, 0);

	OfertaVanzare ofertaVanzare1(43000, 120, imobil6, 4);
	OfertaVanzare ofertaVanzare2(71000, 120, imobil7, 3);
	OfertaVanzare ofertaVanzare3(250500, 240, imobil8, 6);
	OfertaVanzare ofertaVanzare4(995000, 360, imobil9, 7);
	OfertaVanzare ofertaVanzare5(229000, 180, imobil10, 2);


	vector<OfertaInchiriere> ofInc;
	ofInc.push_back(ofertaInchiriere1);
	ofInc.push_back(ofertaInchiriere2);
	ofInc.push_back(ofertaInchiriere3);
	ofInc.push_back(ofertaInchiriere4);
	ofInc.push_back(ofertaInchiriere5);

	vector<OfertaVanzare> ofVnz;
	ofVnz.push_back(ofertaVanzare1);
	ofVnz.push_back(ofertaVanzare2);
	ofVnz.push_back(ofertaVanzare3);
	ofVnz.push_back(ofertaVanzare4);
	ofVnz.push_back(ofertaVanzare5);

	
	
	Meniu* m = new Meniu();
	m->Adauga("1.Afisati numele agentiei");
	m->Adauga("2.Afisati o scurta descriere a agentiei");
	m->Adauga("3.Afisati orarul de functionare al sediului agentiei");
	m->Adauga("4.Afisati cate ore este deschis sediul");
	m->Adauga("5.Afisati detalii despre locatiile/zonele cu care se ocupa agentia");
	m->Adauga("6.Afisati oferta agentiei");
	m->Adauga("7.Afisati cate tipuri de oferta sunt");
	m->Adauga("8.Afisati oferta de inchiriere");
	m->Adauga("9.Afisati oferta de vanzare");
	m->Adauga("10.Afisati suma incasata de agentie dupa un an");
	m->Adauga("11.Afisati cu cate locatii se ocupa agentia");
	m->Adauga("12.Afisati toate datele de mai sus intr-un fisier binar");
	m->Adauga("13.Cititi orarul din fisier text si afisati in alt fisier");
	m->Adauga("14.Cititi agentia din fisier text si afisati in alt fisier");


	int x;
	x = m->Citeste();
	
	if (x == 1) { cout << "Numele agentiei este: " << ag.getDenumire(); }
	
	if (x == 2) cout << "Detalii agentie:" << endl <<endl<< ag;
	
	if (x == 3) cout <<"Programul de functionare este : " << orar.getPrimaZi() << " - " << orar.getUltimaZi() << " intre orele " << orar.getIntervalOrar() << endl;
	
	if (x == 4) cout <<"Sediul il gasiti deschis " <<orar.operator int() << " ore.";

	if (x == 5) {
		vector<Locatie>::iterator it;
		cout << "Locatiile sunt: "<<endl<<endl; 
		for (it = locatii.begin(); it != locatii.end(); it++) {
			cout << *it << endl;
		}
	}

	if (x == 6) {
		cout << "Oferta agentiei este: "<<endl<<endl<<endl;
		vector<OfertaInchiriere>::iterator it;
		for (it = ofInc.begin(); it != ofInc.end(); it++) {
			cout << *it << endl<<endl<<endl;
		}
		vector<OfertaVanzare>::iterator i;
		for (i = ofVnz.begin(); i != ofVnz.end(); i++) {
			cout << *i << endl<<endl<<endl;
		}
	}

	if (x == 7) cout << "Exista 2 tipuri de oferta: inchiriere si vanzare.";

	if (x == 8) {
		cout << "Oferta de inchiriere este: "<<endl<<endl;
		vector<OfertaInchiriere>::iterator it;
		for (it = ofInc.begin(); it != ofInc.end(); it++) {
			cout << *it << endl<<endl<<endl;
		}
	}
	
	if (x == 9) {
		cout << "Oferta de vanzare este: "<<endl<<endl;
		vector<OfertaVanzare>::iterator it;
		for (it = ofVnz.begin(); it != ofVnz.end(); it++) {
			cout << *it << endl<<endl<<endl;
		}
	}
		
	if (x == 10) cout << "Suma incasata este: "<<ag.sumaFinalAn() << endl;

	if (x == 11) {
	Gestiune<Locatie> l;
	cout <<"Agentia se ocupa cu " <<l.getNrObiecte() <<" locatii momentan."<< endl;
	}

    if (x == 12) { 
	   cout << "Scriere in binar reusita!";
       ofstream g("afis.bin", ios::out | ios::binary);
	   g << ag;
	   g<< ag.getDenumire();
       g<<orar.getPrimaZi() << orar.getUltimaZi() << orar.getIntervalOrar();
       g<<orar.operator int();
	   vector<Locatie>::iterator it;
	    g << ag.sumaFinalAn();
		Gestiune<Locatie> l;
		g << l.getNrObiecte();
    }

	if (x == 13) {
		ifstream f("Orar.txt", ios::in); 
		if (f.is_open()) {
			while (!f.eof()) {
				f >> orar;
			}
		} else cout << "Fisier eronat";
		f.close();
		
		ofstream g("OrarOut.txt", ios::out);
		g << orar;
	}

	if (x == 14) {
		ifstream f("Agentie.txt", ios::in);
		if (f.is_open()) {
			while (!f.eof()) {
				f >> ag;
			}
		}
		else cout << "Fisier eronat";
		f.close();
		ofstream g("AgentieOut.txt", ios::out);
		g << ag;
	}
	
}
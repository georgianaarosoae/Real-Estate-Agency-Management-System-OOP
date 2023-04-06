#pragma once
#include "Imobil.h"
#include "Locatie.h"
#include "Gestiune.h"
#include "Oferta.h"
#include "OfertaInchiriere.h"
#include "OfertaVanzare.h"
#include "Orar.h"
#include "Oferta.h"
#include <vector>
#include <string>
#include <cstring>

class AgentieImobiliara {
private:
    string denumire; //denumirea agentiei
    string telefon; //contact
    string adresa; //localizarea sediului
    char* CUI; //cod unic de inregistrare
    int static numarTotalImobile; //numar total imobile cu care se ocupa agentia
    Orar orar;
    vector<Locatie> locatii;
    vector<Oferta*> oferte;


public:

    AgentieImobiliara();
    AgentieImobiliara(const string denumire, string telefon, string adresa, char* CUI, int numarTotal, Orar orar, vector<Locatie> locatii);
    AgentieImobiliara(const AgentieImobiliara& a);
    ~AgentieImobiliara();

    void setDenumire(string denumireNoua);
    void setTelefon(string telefonNou);
    void setAdresa(string adresaNoua);
    void setCUI(char* CUI);
    void setNumarTotalImobile(int numarTotalImobileNou);
    void setOrar(Orar orarNou);
    void setImobile(vector<Locatie> locatiiNoi);
    void setOferte(vector<Oferta*> oferteNoi);

    string getDenumire();
    string getTelefon();
    string getAdresa();
    char* getCUI();
    int getNumarTotalImobile();
    Orar getOrar();
    vector<Locatie> getImobile();
    vector<Oferta*> getOferte();

    void adaugaOferta(OfertaInchiriere);
    void stergeOferta(OfertaInchiriere);

    void adaugaOferta(OfertaVanzare);
    void stergeOferta(OfertaVanzare);

    double sumaFinalAn();

    AgentieImobiliara& operator=(const AgentieImobiliara& a);
    friend istream& operator>>(istream& in, AgentieImobiliara& a);
    friend ostream& operator<<(ostream& out, AgentieImobiliara& a);
    friend ofstream& operator<<(ofstream& out, AgentieImobiliara& a);
    friend ifstream& operator>>(ifstream& in, AgentieImobiliara& a);
    void scrieInFisierBinar(fstream& fisier);
    void citesteDinFisierBinar(fstream& fisier);

};
#pragma once

#include "Imobil.h"

/*
                            Oferta
                              |
                              |
                              |
                _____________________________
                |                           |
                |                           |
                |                           |
          OfertaCumparare            OfertaInchiriere
*/

class Oferta
{
protected:
    Imobil imobil;
    const int idOferta;
    int comision;

public:

    Oferta();
    Oferta(Imobil imobil, int comision);
    Oferta(const Oferta& o) = delete;
    Oferta(Oferta&&) = default;
    virtual ~Oferta();

    // Oferta& operator=(const Oferta&);

    virtual void setImobil(Imobil imobilNou) = 0;
    virtual void setComision(int comisionNou) = 0;
    virtual Imobil getImobil() = 0;
    virtual int getComision() = 0;
    void scrieInFisierBinar(fstream& fisier);
    void citesteDinFisierBinar(fstream& fisier);
};
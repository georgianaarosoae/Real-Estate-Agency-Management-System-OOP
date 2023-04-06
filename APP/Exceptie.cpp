
#include "Exceptie.h"

Exceptie::Exceptie(string mesajExceptie)
{
		this->mesajExceptie = mesajExceptie;
}

string Exceptie::getMesajExceptie()
{
	return mesajExceptie;
}

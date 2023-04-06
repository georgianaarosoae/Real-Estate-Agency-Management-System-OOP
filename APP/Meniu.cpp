#include "Meniu.h"

Meniu::Meniu() {
	lista.clear();
	optiuneActiva = 1;
}
void Meniu::Adauga(string nume) {
	lista.push_back(nume);
}

int Meniu::Citeste()
{
	while (true) {
		
		system("cls");
		cout << *this;
		int tasta;
		tasta = _getch();
		if (tasta == 224) {
			tasta = _getch();
			if (tasta == 80&& optiuneActiva<lista.size()) optiuneActiva++;
			if (tasta == 72&& optiuneActiva>1) optiuneActiva--;
		}
		if (tasta == 13) return optiuneActiva;
	}
	return 0;
}

ostream& operator<<(ostream& out, Meniu m)
{
	int nrOptiune=0;
	list<string>::iterator it;
	for (it = m.lista.begin(); it != m.lista.end(); it++) {
		nrOptiune++;

		ItemMeniu* x = new ItemMeniu(*it);
		if (nrOptiune == m.optiuneActiva) x->activ = 1;
		out << *x;
	}
	return out;
}

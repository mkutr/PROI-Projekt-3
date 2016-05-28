#include "Abonent.h"
#include "Centrala.h"
#include <iostream>
using namespace std;
Abonent::Abonent()
{
}

Abonent::~Abonent()
{
}

void Abonent::dokonstruktor(string nazwa, Centrala * polaczona_centrala)
{
	this->nazwa = nazwa;
	this->polaczona_centrala = polaczona_centrala;
	if (polaczona_centrala != NULL)
	{
		polaczona_centrala->add_abonent(this);
		polaczona_centrala->pol_z_abonentami++;
	}
}

Business::Business(string nazwa = "Nienazwany Abonent klasy Buisness", Centrala* polaczona_centrala = NULL)
{
	dokonstruktor(nazwa, polaczona_centrala);
}

Business::~Business()
{
}

Premium::Premium(string nazwa = "Nienazwany Abonent klasy Premium", Centrala* polaczona_centrala = NULL)
{
	dokonstruktor(nazwa, polaczona_centrala);
}

Premium::~Premium()
{
}

Economy::Economy(string nazwa = "Nienazwany Abonent klasy Economy", Centrala* polaczona_centrala = NULL)
{
	dokonstruktor(nazwa, polaczona_centrala);
}

Economy::~Economy()
{
}

int Economy::polacz_abonenta(Abonent * szukany)
{
	return 0;
}

ostream & operator<<(ostream & s, Abonent & A)
{
	return s << "\nnazwa abonenta: " << A.nazwa << "\nstatus abonenta: " << A.status << "\nnr polaczonej centrali: " << A.polaczona_centrala->nr << endl; 
}

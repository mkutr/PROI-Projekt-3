#include "Centrala.h"
#include "Abonent.h"
#include <iostream>
using namespace std;

Centrala::Centrala(int nr, double cena,  vector <pair <Abonent*, int> > wektor_abonentow,
										 vector <pair <Centrala*, int> > wektor_centrali, 
										 vector <pair <Centrala*, int> > wektor_polaczen) :
										 nr(nr), cena(cena),
										 wektor_abonentow(wektor_abonentow),
										 zajete_pol_z_abonentami (0)
{
	pol_z_abonentami = wektor_abonentow.size();
}

Centrala::Centrala(int nr, double cena) : nr(nr), cena(cena), zajete_pol_z_abonentami(0)
{
}

Centrala::Centrala()
{
}

Centrala::~Centrala()
{
}

void Centrala::add_centrala(Centrala* nowa_centrala, int pol_z_centralami)
{
	try
	{
		for (unsigned int i = 0; i < wektor_centrali.size(); i++)
			if (wektor_centrali[i].first == nowa_centrala) throw nowa_centrala->nr;

		wektor_centrali.push_back(make_pair(nowa_centrala, pol_z_centralami));
		wektor_polaczen.push_back(make_pair(nowa_centrala, pol_z_centralami));

		nowa_centrala->wektor_centrali.push_back(make_pair(this, pol_z_centralami));
		nowa_centrala->wektor_polaczen.push_back(make_pair(this, pol_z_centralami));
	}
	catch (int kod)
	{
		cerr << "centrala o numerze: " << kod << " jest juz polaczona" <<endl;
	}

}

void Centrala::add_abonent(Abonent * nowy_abonent)
{
	try
	{
		for (unsigned int i = 0; i < wektor_abonentow.size(); i++)
			if (wektor_abonentow[i].first == nowy_abonent)	throw wektor_abonentow[i].first->nazwa;

		wektor_abonentow.push_back(make_pair(nowy_abonent, 0));
	}
	catch (string kod)
	{
		cerr << "abonent o nazwie: " << kod << " jest juz polaczony\n";
	}
}

void Centrala::zmiana_ilosci_polaczen(Centrala * centrala, int pol_z_centralami)
{
	try
	{
		for (int i = 0; i < this->wektor_centrali.size(); i++)
			if (this->wektor_centrali[i].first == centrala)
			{
				this->wektor_polaczen[i].second = this->wektor_polaczen[i].second + (pol_z_centralami-this->wektor_centrali[i].second);
				this->wektor_centrali[i].second = pol_z_centralami;

				for (int i2 = 0; i2 < centrala->wektor_centrali.size(); i2++)
					if (centrala->wektor_centrali[i2].first == this)
					{
						centrala->wektor_polaczen[i2].second = centrala->wektor_polaczen[i2].second + (pol_z_centralami - centrala->wektor_centrali[i2].second);
						centrala->wektor_centrali[i2].second = pol_z_centralami;
						return;
					}

			}
		throw centrala->nr;
	}

	catch (int nr)
	{
		cout << "centrala o numerze: " << nr << " nie jest polaczona z centrala o numerze: " << this->nr << endl;
	}

}

ostream & operator<<(ostream & s, Centrala & c)
{
	s	<< "nr: " << c.nr
		<< "\npol_z_abonentami: " << c.pol_z_abonentami
		<< "\nzajete_pol_z_abonentami: " << c.zajete_pol_z_abonentami << "\ncena: " << c.cena;
	
	s << "\nwektor_abonentow: ";
	for (unsigned int i = 0; i<c.wektor_abonentow.size(); i++)
	{
		Abonent *X = c.wektor_abonentow[i].first;
		int Y = c.wektor_abonentow[i].second;
		s << "\n<" << X->nazwa << ", " << Y << ">";
	}

	s << "\nwektor_centrali: ";
	for (unsigned int i=0; i<c.wektor_centrali.size(); i++)
	{
		Centrala *X = c.wektor_centrali[i].first;
		int Y = c.wektor_centrali[i].second;
		s << "\n<" << X->nr << ", " << Y << ">";
	}

	s << "\nwektor_polaczen: ";
	for (unsigned int i = 0; i<c.wektor_polaczen.size(); i++)
	{
		Centrala *X = c.wektor_polaczen[i].first;
		int Y = c.wektor_polaczen[i].second;
		s << "\n<" << X->nr << ", " << Y << ">";
	}
	s << endl;
	return s;
}

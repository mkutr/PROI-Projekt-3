#pragma once
#include <vector>
#include <utility>      // std::pair, std::make_pair
using namespace std;

class Abonent;
class Centrala
{
public:
	Centrala(int nr, double cena, vector <pair <Abonent*, int> > wektor_abonentow,
								  vector <pair <Centrala*, int> > wektor_centrali,
								  vector <pair <Centrala*, int> > wektor_polaczen);

	Centrala(int nr, double cena);
	Centrala();
	~Centrala();

	void add_centrala(Centrala* centrala, int pol_z_centralami);
	void add_abonent(Abonent* nowy_abonent);
	void zmiana_ilosci_polaczen(Centrala* nowa_centrala, int pol_z_centralami);

	friend class Abonent;
	friend class Economy;
	friend class Premium;
	friend class Business;

	friend ostream & operator <<(ostream & s, Abonent & A);
	friend ostream & operator <<(ostream & s, Centrala & c);
	
private:
	int nr, pol_z_abonentami;
	int zajete_pol_z_abonentami;
	double cena;

	vector <pair <Abonent*, int> > wektor_abonentow;
	vector <pair <Centrala*, int> > wektor_centrali;
	vector <pair <Centrala*, int> > wektor_polaczen;	
};
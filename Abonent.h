#pragma once
#include <string>
#include "Centrala.h"

using namespace std;
//class Centrala;
class Abonent
{
public:
	Abonent();
	~Abonent();

	void dokonstruktor(string nazwa = "Nienazwany Abonent klasy Buisness", Centrala* polaczona_centrala = NULL);
	double wyszukiwanie_polaczenia(Abonent* szukany);
	virtual int polacz_abonenta(Abonent* szukany)=0;
	friend class Centrala;
	friend ostream & operator <<(ostream & s, Abonent & A);
	friend ostream & operator <<(ostream & s, Centrala & c);

protected:
	string nazwa;
	int status;
	Centrala* polaczona_centrala;
};

class Business : public Abonent
{
public:
	Business(string nazwa, Centrala * polaczona_centrala);
	~Business();

	friend class Centrala;
private:

};

class Premium : public Abonent
{
public:
	Premium(string nazwa, Centrala * polaczona_centrala);
	~Premium();

	friend class Centrala;
private:

};

class Economy : public Abonent
{
public:
	Economy(string nazwa, Centrala* polaczona_centrala);
	~Economy();

	virtual int polacz_abonenta(Abonent* szukany);

	friend class Centrala;
private:

};






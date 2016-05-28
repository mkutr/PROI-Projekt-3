#include "Abonent.h"
#include "Centrala.h"
#include <iostream>
using namespace std;

int main()
{
	Centrala cent1(1, 10.2);
	Centrala cent2(2, 3.5);
	cout << cent1 << endl;
	Economy A("A", &cent1);
	cout << cent1 << endl <<A;
	cent1.add_abonent(&A);
	cent1.add_centrala(&cent2, 2);
	cout << endl << cent1 <<endl << cent2 << endl;
	cent1.add_centrala(&cent2, 2);
	cent1.zmiana_ilosci_polaczen(&cent2, 4);
	cout << endl << cent1 << endl << cent2 << endl;
	system("pause");
}
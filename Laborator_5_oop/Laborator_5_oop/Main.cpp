#include <iostream>
#include "Film.h"
#include <windows.h>
using namespace std;


int main()
{
	Film f;
	f.adaugare_film("ana", "horror", 2004, 2991, "ww.cs/0");
	f.adaugare_film("asj", "comedie", 2009, 3647, "www.cs/1");
	f.adaugare_film("Iron", "comedie", 2013, 9585, "www.cs/2");
	f.adaugare_film("Captain", "actiune", 2017, 2141, "www.cs/3");
	f.adaugare_film("Conasu", "horror", 2019, 1235, "www.cs/4");
	f.adaugare_film("Eu", "thriller", 1999,912, "www.cs/5");
	f.adaugare_film("Vremea", "aventura", 2005, 1257, "www.cs/6");
	f.adaugare_film("Singur!", "comedie", 2015, 4542, "www.cs/7");
	f.adaugare_film("Slab.", "dragoste", 2011, 1234, "www.cs/8");
	int n;
	int m;
	do
	{
		cout << "Alegeti modul dorit:" << endl;
		cout << "1. Mod administrator" << endl;
		cout << "2.Mod utilizator" << endl;
		cout << "0. Apasand tasta 0 iesiti din program!!!" << endl;
		cout << "Alegeti ce doriti sa faceti apasand tasta de tip numar,din stanga celor de mai sus: ";
		cin >> n;
		if(n==1)
			do
			{
				system("CLS");
				cout << "Ati intrat in modul administratorului:" << endl;
				cout << "1.Adaugati un film" << endl;
				cout << "2.Stergeti un film" << endl;
				cout << "3.Modificati un film " << endl;
				cout << "4. Afisati lista de filme" << endl;
				cout << "0. Apasand tasta 0, va reintoarceti la pagina principala!" << endl;
				cout << "Alegeti ce doriti sa faceti apasand tasta de tip numar,din stanga celor de mai sus: ";
				cin >> m;
				//optiune adaugare
				if (m == 1)
					f.insert_film();
				else
					//optiune stergere
					if (m == 2)
						f.stergere_film();
					else
						//optiune modificare
						if (m == 3)
							f.modificare_film();
						else
							if (m == 4)
								f.afisare_filme();
							else
								if (m == 0)
								{
									cout << "Ati iesit din modul administrator";
									break;
								}
				Sleep(3000);
				system("CLS");
			} while (m != 0);
		if (n == 0)
			break;
		Sleep(3000);
		system("CLS");
	} while (n != 0);

}
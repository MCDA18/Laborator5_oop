#include "Film.h"
#include <iostream>


using namespace std;
//constructoru default
Film::Film()
{
	titel = "";
	genre = "";
	erscheinungsjahr = 0;
	anzahl_likes = 0;
	trailer = "";
}
//adaugarea unui film,la inceputul programului,creand astfel o lista implicita
void Film::adaugare_film(string titlu, string gen, int an, int likeuri, string tr)
{
	Film f;
	f.titel = titlu;
	f.genre = gen;
	f.erscheinungsjahr = an;
	f.anzahl_likes = likeuri;
	f.trailer = tr;
	v.push_back(f);
}
//inserarea unui film nou,in modul administratoului
void Film::insert_film()
{
	string titel, genre, trailer;
	int erscheinungsjahr, anzahl_likes;
	Film f;
	int ok = 0;
	cout << "Ce nume doriti sa aiba filmul?";
	cin >> titel;
	//verifica daca titlul exista deja
	for (auto it : v)
		if (it.titel == titel)
			ok = 1;
	//daca nu exista,adauga
	if (ok == 0)
	{
		cout << "Ce gen este filmul?";
		cin >> genre;
		cout << "In ce an a aparut filmul?";
		cin >> erscheinungsjahr;
		cout << "Care este numarul de like-uri?";
		cin >> anzahl_likes;
		cout << "Care este linkul trailerului?";
		cin >> trailer;
		//atributele obiectului primesc datele oferite de administrator
		f.titel = titel;
		f.genre = genre;
		f.erscheinungsjahr = erscheinungsjahr;
		f.anzahl_likes = anzahl_likes;
		f.trailer = trailer;
		v.push_back(f);//insereaza in fisier
		cout << "Filmul a fost adaugat cu succes";
	}
	else
		cout << "Numele exista deja";
}
//afisarea tuturor filmelor
void Film::afisare_filme()
{
	for (auto it : v)
		cout << it.titel << " " << it.genre << " " << it.erscheinungsjahr << " " << it.anzahl_likes << " " << it.trailer << endl;
}
//stergerea unui film
void Film::stergere_film()
{
	vector<Film> aux;
	Film f;
	string nume;
	cout << "Ce filme doriti sa stergeti?";
	cin >> nume;
	int ok = 0;
	//daca exista numele,il poate sterge
	for (auto it : v)
		if (it.titel == nume)
			ok = 1;
	if (ok == 1)
	{
		for (const auto& film : v)
			if (film.titel != nume)
			{
				f.titel = film.titel;
				f.genre = film.genre;
				f.erscheinungsjahr = film.erscheinungsjahr;
				f.anzahl_likes = film.anzahl_likes;
				f.trailer = film.trailer;
				aux.push_back(f);//creaza un nou vector,fara filmul pe care dorim sa l stergem
			}
		v = aux;//se pune aux in vectoru v
		cout << "Filmul a fost sters cu succes";
	}
	else
		cout << "Filmul pe care doriti sa-l stergeti nu exista!";
}
//modificarea filmului
void Film::modificare_film()
{
	string nume,titlu,gen,tr;
	Film f;
	int an,nr;
	int ok = 0;
	int n;
	vector<Film> aux;
	cout << "Ce film doriti sa modificati?"<<endl;
	cin >> nume;
	//se va cauta filmul care va trebui modificat
	for (auto it : v)
		if (it.titel == nume)
		{
			ok = 1;
			//administratorul alege ce sa modifice
			cout << "Alegeti ce doriti sa modificati la acest film:"<<endl;
			cout << "1.Titel" << endl;
			cout << "2.Genre"<<endl;
			cout << "3.Erscheinungsjahr" << endl;
			cout << "4.Anzahl Likes" << endl;
			cout << "5.Link trailer" << endl;
			cin >> n;
			//n=1,schimba titlu
			if (n == 1)
			{
				cout << "Titlul nou:" << endl;
				cin >> titlu;
				for (auto film : v)
				{
					if (film.titel == it.titel)
						f.titel = titlu;
					else
						f.titel = film.titel;
					f.genre = film.genre;
					f.erscheinungsjahr = film.erscheinungsjahr;
					f.anzahl_likes = film.anzahl_likes;
					f.trailer = film.trailer;
					aux.push_back(f);//creaza un vector nou,schimband titlul
				}
				cout << "Titlul a fost modificat!";
			}
			//n==2,schimba genul
			if (n == 2)
			{
				cout << "Gen nou:"<<endl;
				cin >> gen;
				for (auto film : v)
				{
					//parcurgere vectoru si unde titlu de la film.titel==it.titel..schimba genu,daca nu pune genul normal
					if (film.titel == it.titel)
						f.genre = gen;
					else
						f.genre = film.genre;
					f.titel = film.titel;
					f.erscheinungsjahr = film.erscheinungsjahr;
					f.anzahl_likes = film.anzahl_likes;
					f.trailer = film.trailer;
					aux.push_back(f);// creaza un vector nou, schimband genuk
				}
				cout << "Genul a fost modificat!" << endl;
			}
			//schimba anul aparitiei
			if (n == 3)
			{
				cout << "Erscheinungsjahr nou:";
				cin >> an;
				for (auto film : v)
				{
					
					if (film.titel == it.titel)
						f.erscheinungsjahr = an;
					else
						f.erscheinungsjahr = film.erscheinungsjahr;
					f.genre = film.genre;
					f.titel = film.titel;
					f.anzahl_likes = film.anzahl_likes;
					f.trailer = film.trailer;
					aux.push_back(f);
				}
				cout << "Anul aparitiei a fost modificat!";
			}
			//schimba numarul de like-uri
			if (n == 4)
			{
				cout << "Numar de like-uri nou:";
				cin >> nr;
				for (auto film : v)
				{

					if (film.titel == it.titel)
						f.anzahl_likes = nr;
					else
						f.anzahl_likes = film.anzahl_likes;
					f.genre = film.genre;
					f.titel = film.titel;
					f.erscheinungsjahr = film.erscheinungsjahr;
					f.trailer = film.trailer;
					aux.push_back(f);
				}
				cout << "Numarul de like-uri a fost modificat!";
			}
			//schimba link ul
			if (n == 5)
			{
				cout << "Link-ul trailerului nou:";
				cin >> tr;
				for (auto film : v)
				{

					if (film.titel == it.titel)
						f.trailer = tr;
					else
						f.trailer = film.trailer;
					f.genre = film.genre;
					f.titel = film.titel;
					f.anzahl_likes = film.anzahl_likes;
					f.erscheinungsjahr = film.erscheinungsjahr;
					aux.push_back(f);
				}
				cout << "Link-ul trailerui a fost modificat!";
			}
			v = aux;
		}
		//daca numele ii gresit sau nu exista in vector,se afiseaza mesajul
	if (ok == 0)
		cout << "Filmul pe care doriti sa-l modificati,nu exista!";
}

/// Cautarea dupa gen A Utilizatorului
void Film::Cautare()
{
	string gen;
	cout << "Genul este: ";
	cin >> gen;
	int ok = 0;
	int k = 1;
	for (auto it : v) /// Cautam in lista de filme
	{
			if (gen == it.genre && k==1) /// afisam primul gen 
			{
				cout << it.titel << " " << it.genre << " " << it.erscheinungsjahr << " " << it.anzahl_likes << " " << it.trailer << endl;
				string From = string(it.trailer);
				wstring To(From.begin(), From.end()); ///am transformat din string in wstring
				LPCWSTR Last = To.c_str(); /// din wstring in LPCWSTR
				LPCWSTR C = TEXT("open");
				ShellExecute(NULL,C, Last, NULL, NULL, SW_SHOWNORMAL); ///aceseaza browserul
				ok = 1;
				int m;
				do
					{
						///Meniul pentru problema 3 care contine problema 2 incorporata 
						cout << "1.Continuati / Adaugati" << endl;
						cout << "2.Nu Adaugati / Continuati" << endl;
						cout << "0.Iesiti " << endl;
						cout << "Alegeti ce doriti sa faceti apasand tasta de tip numar,din stanga celor de mai sus: ";
						cin >> m;
						//optiune continuare si adaugare
						if (m == 1)
						{
							addListaFilme(it);
							break;
						}
						else
							//optiune continuare
							if (m == 2)
								break;
								else
									if (m == 0)
									{
										cout << "Ati iesit din modul cautare";
										k = 0;
										break;
									}
						//Sleep(3000);
						//system("CLS");
				} while (m != 0);
			}
	}
	if (ok == 0) ///daca nu a gasit genul afisam toate filmele
	{
		afisare_filme();
	}
}

// adaugam in lista de filme

void Film::addListaFilme(Film it) {
	int ok = 1;
	// veerificam daca filmul nu este deja in watchlist
	for (auto i : ListaFilme) {
		if (i.titel == it.titel) {
			cout << "\nFilm se afla in Lista!\n";
			ok = 0;
		}
	}
	if (ok == 1) {
		ListaFilme.push_back(it);
		cout << "\nFilm Adaugat cu succes.\n";
	}
}
void Film::stergere()
{
	vector<Film> aux;
	vector<Film> aux1;
	int ok = 0;
	Film f;
	string titlu;
	cout << "Dati titlul: ";
	cin >> titlu;
	for (auto it : ListaFilme) ///Parcurgem lista de vizionari 
	{
		if (it.titel == titlu) ///Cautam titlul
		{
			ok = 1;
			cout << "Doriti sa dati un like la aceast film\n";
			cout << "Tasta 1 = Da\n";
			cout << "Tasta 2 = Nu\n";
			cout << "Apasati Tasta = ";
			int n;
			cin >> n;
			if (n == 1) ///Partea de modificare a like-ului in lista de filme si stergerea filmului in lista de vizionari
			{ 
				for (const auto& film : v) /// parcurgem pentru lista de filme 
					if (film.titel == titlu)
					{
						f.titel = film.titel;
						f.genre = film.genre;
						f.erscheinungsjahr = film.erscheinungsjahr;
						f.anzahl_likes = film.anzahl_likes + 1; ///Cand gasim filmul modificam pretul
						f.trailer = film.trailer;
						aux.push_back(f);
					}
					else
					{
						f.titel = film.titel;
						f.genre = film.genre;
						f.erscheinungsjahr = film.erscheinungsjahr;
						f.anzahl_likes = film.anzahl_likes;
						f.trailer = film.trailer;
						aux.push_back(f);
					}
				v = aux;//se pune aux in vectoru v 
				for (const auto& film : ListaFilme)
					if (film.titel != titlu)   ///Stergem filmul din lista de Vizionare
					{
						f.titel = film.titel;
						f.genre = film.genre;
						f.erscheinungsjahr = film.erscheinungsjahr;
						f.anzahl_likes = film.anzahl_likes;
						f.trailer = film.trailer;
						aux1.push_back(f);//creaza un nou vector,fara filmul pe care dorim sa l stergem
					}
				ListaFilme = aux1;//se pune aux in vectoru ListaFilme
				cout << "Filmul a fost sters cu succes";
			}

			else
				if (n == 2)
				{
					for (const auto& film : ListaFilme)
						if (film.titel != titlu)	///Stergem filmul din lista de Vizionare
						{
							f.titel = film.titel;
							f.genre = film.genre;
							f.erscheinungsjahr = film.erscheinungsjahr;
							f.anzahl_likes = film.anzahl_likes;
							f.trailer = film.trailer;
							aux.push_back(f);//creaza un nou vector,fara filmul pe care dorim sa l stergem
						}
					ListaFilme = aux1;//se pune aux in vectoru v
					cout << "Filmul a fost sters cu succes";

				}
				else
					if (n != 1 && n != 2)
						cout << "Tasta incorecta";
		}
				
		
	}
	if (ok == 0)
		cout << "Nu exista filmul";
}
void Film :: Afisare()
{/// Afisam lista de vizionare
	for (auto it: ListaFilme)
		 cout << it.titel << " " << it.genre << " " << it.erscheinungsjahr << " " << it.anzahl_likes << " " << it.trailer << endl;
}


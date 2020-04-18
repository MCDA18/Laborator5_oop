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
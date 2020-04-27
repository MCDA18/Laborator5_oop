#pragma once
#include <string>;
#include <vector>;
#include <windows.h>
using namespace std;
class Film
{
private:
	string titel;
	string genre;
	int erscheinungsjahr;
	int anzahl_likes;
	string trailer;
	vector<Film> v;
	vector<Film> ListaFilme;
public:
	Film();
	//Film(string, string, int, int, string);
	void adaugare_film(string, string, int, int, string);
	void insert_film();
	void stergere_film();
	void afisare_filme();
	void modificare_film();
	void Cautare();
	void openTrailer(string trailer);
	void addListaFilme(Film it);
	void stergere();
	void Afisare();
};



#pragma once
#include <string>;
#include <vector>;
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
public:
	Film();
	//Film(string, string, int, int, string);
	void adaugare_film(string, string, int, int, string);
	void insert_film();
	void stergere_film();
	void afisare_filme();
	void modificare_film();

};



#pragma once
#include "repository.h"
#include "cos.h"
#include <fstream>
using std::string;
using std::ofstream;
using std::ifstream;
class Repof :public Lista
{

private:
	std::string path;
	void writetofile();
public:
	Repof(string path);
	//~Repof() { }

	/*
		Adauga un produs in lista de produse si scrie in fisier
		param:Produs:Produsul ce urmeaza sa fie adaugat
	
	*/
	void adauga_produs(Produs) override;

	/*
		Sterge un produs din lista de produse si din fisier
		param:int:pozitia produsului in lista de produse
	*/
	void sterge_produs(int)override;
	//void salveaza_cos(Cos& cos);

	void modifica_produs(const Produs&,int);

	/*
		Goleste fisierul
	*/
	void goleste_fisier();


};
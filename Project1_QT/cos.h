#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "domain.h"
#include "repository.h"

class Cos
{
	//friend class Repof;
private:

	std::vector<Produs> cosulet;


public:

	/*
		Adauga un produs din magazin in cos
		param:Produs:produsul de adaugat
		
	
	*/
	void adauga_produs_cos(Produs);

	/*
		Goleste cosul
	*/
	void sterge_cos();

	/*
		Returneaza lista cu toate produsele din cos
		return:vector<Produs>:lista cu produse
	*/
	std::vector<Produs>& get_all_cos();

	/*
		Salveaza produsele din cos intr-un fisier dat de utilizator
	
	*/
	void salveaza_cos(std::string path);

	/*
		Returneaza numarul de produse din cos
		return:int:numarul de produse din cos
	*/
	int get_size();
};
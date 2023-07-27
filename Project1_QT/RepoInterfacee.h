#pragma once
#include "domain.h"
#include <vector>

class RepoInterface
{


private:
public:
	virtual ~RepoInterface()=default;
	//virtual void golire()=0;
	/*
		Adauga un produs valid in lista de produse
		param:Produs:produsul de tip Produs ce trebuie adaugat in lista
		return:-


	*/
	virtual void adauga_produs(Produs)=0;

	/*
		Sterge un produs existent din lista de produse
		param:int:pozitia produsului in lista
		return:-

	*/
	virtual void sterge_produs(int)=0;

	/*
		Cauta un produs in lista de produse
		param:string:numele de tip string al produsului cautat
		param:int&:referinta catre pozitia de tip int din lista a produsului
		raises:RepoExceptions-daca produsul nu a fost gasit
		return:Produs&:referinta catre produsul gasit


	*/
	virtual Produs& cauta_produs(std::string, int&)=0;

	/*
		Modifica un produs din lista de produse
		param:Produs&:referinta catre produsul de tip Produs care urmeaza a fi modificat
		param:int:pozitia produsului in lista
	*/
	virtual void modifica_produs(const Produs&, int)=0;

	/*
		Returneaza un produs din lista
		param:int:pozitia de tip int a produsului din lista
		return:Produ&:referinta catre produs
	*/
	virtual Produs& get_produs(int)=0;

	/*
		Returneaza dimensiunea listei de produe
		return:int:dimensiunea de tip int a listei
	*/
	virtual int get_size() =0;

	/*
		Returneaza lista de produse
		return:vector<Produs>:lista de produse

	*/
	virtual std::vector<Produs>& get_all() =0;
	//VectorDinamic<Produs>& get_all() noexcept;

};
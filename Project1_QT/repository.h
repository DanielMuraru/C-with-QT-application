#pragma once
#include "RepoInterfacee.h"
#include <vector>
#include "Exceptions.h"
#include "domain.h"
class Lista:public RepoInterface
{
	
private:
	std::vector<Produs> lista;
	//VectorDinamic<Produs> lista;
public:
	Lista() noexcept;
	//virtual ~Lista() =default; //{ lista.clear() };
	Lista(const Lista&) = delete;
	//void golire() override;
	/*
		Adauga un produs valid in lista de produse
		param:Produs:produsul de tip Produs ce trebuie adaugat in lista
		return:-


	*/
	 void adauga_produs(Produs) override;

	/*
		Sterge un produs existent din lista de produse
		param:int:pozitia produsului in lista
		return:-

	*/
	 void sterge_produs(int) override;

	/*
		Cauta un produs in lista de produse
		param:string:numele de tip string al produsului cautat
		param:int&:referinta catre pozitia de tip int din lista a produsului
		raises:RepoExceptions-daca produsul nu a fost gasit
		return:Produs&:referinta catre produsul gasit

	
	*/
	Produs& cauta_produs(std::string,int&)override;

	/*
		Modifica un produs din lista de produse
		param:Produs&:referinta catre produsul de tip Produs care urmeaza a fi modificat
		param:int:pozitia produsului in lista
	*/
	void modifica_produs(const Produs&,int)override;

	/*
		Returneaza un produs din lista
		param:int:pozitia de tip int a produsului din lista
		return:Produ&:referinta catre produs
	*/
	Produs& get_produs(int);

	/*
		Returneaza dimensiunea listei de produe
		return:int:dimensiunea de tip int a listei
	*/
	int get_size() noexcept override;

	/*
		Returneaza lista de produse
		return:vector<Produs>:lista de produse
	
	*/
	std::vector<Produs>& get_all() noexcept override;
	//VectorDinamic<Produs>& get_all() noexcept;

	


};
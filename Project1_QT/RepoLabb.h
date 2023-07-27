#pragma once
#include "RepoInterfacee.h"
#include <unordered_map>
#include <string>
#include <vector>

using std::unordered_map;
using std::string;
class RepoLab :public RepoInterface
{


private:
	std::vector<Produs> produse;
	Produs par{ "a","b",20,"c" };
	float prob;
	unordered_map<string, Produs> dict;
	//VectorDinamic<Produs> lista;
public:
	RepoLab(float) noexcept;
	//virtual ~Repo() = default; //{ lista.clear() };
	//Lista(const Lista&) = delete;
	//void golire() override;
	/*
		Adauga un produs valid in lista de produse
		param:Produs:produsul de tip Produs ce trebuie adaugat in lista
		return:-


	*/
	virtual void adauga_produs(Produs) override;

	/*
		Sterge un produs existent din lista de produse
		param:int:pozitia produsului in lista
		return:-

	*/
	virtual void sterge_produs(int) override;

	/*
		Cauta un produs in lista de produse
		param:string:numele de tip string al produsului cautat
		param:int&:referinta catre pozitia de tip int din lista a produsului
		raises:RepoExceptions-daca produsul nu a fost gasit
		return:Produs&:referinta catre produsul gasit


	*/
	Produs& cauta_produs(std::string, int&)override;

	/*
		Modifica un produs din lista de produse
		param:Produs&:referinta catre produsul de tip Produs care urmeaza a fi modificat
		param:int:pozitia produsului in lista
	*/
	void modifica_produs(const Produs&, int)override;

	/*
		Returneaza un produs din lista
		param:int:pozitia de tip int a produsului din lista
		return:Produ&:referinta catre produs
	*/
	Produs& get_produs(int)override;

	/*
		Returneaza dimensiunea listei de produe
		return:int:dimensiunea de tip int a listei
	*/
	int get_size()  override;

	/*
		Returneaza lista de produse
		return:vector<Produs>:lista de produse

	*/
	std::vector<Produs>& get_all()  override;
	//VectorDinamic<Produs>& get_all() noexcept;






};
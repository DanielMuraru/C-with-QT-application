#pragma once
#include "RepoInterfacee.h"
#include "repository.h"
#include "Repofile.h"
#include "cos.h"
#include "dto.h"
#include <map>
#include "Validator.h"
#include "Undo.h"
class Service
{
	//friend class Lista;
	friend class ActiuneUndo;
	friend class Repof;
	friend class Cos;
	friend class Produs;
private:
	std::vector<ActiuneUndo*>undoactiuni;
	Cos& cos;
	RepoInterface& repo;
	//Repof& repo;
	Validator& val;
public:
    Service(Cos&,RepoInterface&,Validator&) noexcept ;
	//~Service() { repo.~Lista(); val.~Validator(); }
	~Service() = default;
	Service(const Service&) = delete;


	/*
		Adauga un produs valid in lista de produse
		param:string: numele de tip string al produsului
		param:string: tipul de tip string al produsului
		param:int:pretul de tip int al produsului
		param:string:producatorul de tip string al produsului
		raises:ValidatorExceptions-daca produsul nu e valid
		return:-
		
	
	*/
	void adauga_produs_service(std::string,std::string,int,std::string);

	/*
		Sterge un produs existent din lista de produse
		param:string:numele produsului
		raises:RepoExceptions-daca produsul nu exista in lista
		return:-
	
	
	*/
	void sterge_produs_service(std::string);

	/*
		Cauta un produs in lista de produse
		param:string:numele produsului cautat
		raises:RepoExceptions-daca produsul nu a fost gasit
		return:Produs:produsul cautat de tip produs
	
	*/
	Produs& cauta_produs_service(std::string);

	/*
		Modifica un produs din lista de produse
		param:string:numele de tip string al produsului pe care vrem sa il modificam
		param:int:pretul nou
		param:string:producatorul nou
		raise:RepoExceptions-daca produsul nu a fost gasit in lista de produse
	*/
	void modifica_produs_service(std::string, int, std::string);
	
	/*
		Functia de comparare string-uri pentru sortare
		param:string:primul string
		param:string:al doilea string
		return:int: 0-daca sunt egale
					1-daca primul string e mai mare decat al doilea
					-1-daca primul string e mai mic decat al doilea
	*/
	//bool compare_string(const Produs&,const Produs&);
	//
	///*
	//	Functia de comparare int-uri pentru sortare
	//	param:int:primul int
	//	param:int:al doilea int
	//	return:int: 0-daca sunt egale
	//				1-daca primul int e mai mare decat al doilea
	//				-1-daca primul int e mai mic decat al doilea
	//*/
	//bool compare_int(const Produs&, const Produs&);

	///*
	//	Functia de comparare a altor 2 string-uri daca primele 2 sunt egale
	//	param:Produs&:referinta catre primul produs
	//	param:Produs&:Referinta catrea al doilea produs
	//	return:int:0-daca sunt egale
	//				1-daca primul int e mai mare decat al doilea
	//				-1-daca primul int e mai mic decat al doilea
	//*/
	//bool compare_doua(const Produs&, const Produs&) ;

	/*
		Sorteaza lista de produse
		param:vector<Produs>&:referinta catre lista de produse
		param:string:filtru dupa care se face sortarea
		param:int(*)():functia de comparare string-uri
		param:int(*)():functia de comparare int-uri
		param:bool:indicator al ordinii elementelor dupa sortare

	*/
	void sortare_service(std::vector<Produs>&,std::string, bool );
	
	/*
		Returneaza lista cu produse
		return:vector<Produs>:lista de produse
	*/
	std::vector<Produs>& get_all_service() ;
	//VectorDinamic<Produs>& get_all_service() noexcept;
	/*
		Returneaza lista filtrata
		param:int&:referinta catre filtru dupa care se filtreaza lista
		return:vector<Produs>:lista filtrata
	*/
	std::vector<Produs> filtrare_pret(const int&);

	std::vector<Produs> filtrare_nume(const std::string&);
	std::vector<Produs> filtrare_producator(const std::string&);
	/*
		Returneaza dimensiunea listei de produse
		return:int:dimensiunea de tip int a listei de produse
	*/
	int get_size_service() ;


	/*
		Returneaza lista cu produsele din cos
		return:vector<Produs>:lista cu produsele din cos
	*/
	std::vector<Produs>& get_all_cos() ;

	/*
		Adauga un produs in cos
		param:string:numele produsului din magazin
	*/
	void adauga_produs_cos(std::string);

	/*
		Goleste cosul de cumparaturi
	*/
	void sterge_cos();

	/*
		Genereaza un cos cu produsele din magazin
		param:int:numarul de produse care vor fi adaugate in cos
	*/
	void generare_cos(int);

	/*
		Returneaza pretul tuturor produselor din cos
		return:int:pretul tuturor produselor
	*/
	int get_pret_cos() noexcept;

	void salveaza_cos_service(std::string path);
	std::map<std::string, DTO> statistica();

	

	void undo_service();

};
//bool coompare_string(const Produs& a, const Produs& b);
//bool coompare_int(const Produs& a, const Produs& b);
//bool coompare_doua(const Produs& a, const Produs& b);
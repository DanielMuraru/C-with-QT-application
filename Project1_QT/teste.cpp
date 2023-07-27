#include "teste.h"
#include "domain.h"
#include "repository.h"
#include "service.h"
#include "Exceptions.h"
#include <assert.h>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>

void teste_domain()
{
	
	Produs p("Prajitura","Dulce",200,"Broromir");
	assert(p.get_nume() == "Prajitura");
	assert(p.get_tip() == "Dulce");
	assert(p.get_pret() == 200);
	assert(p.get_producator() == "Broromir");
	std::string nume="Tort", tip="Cofetarie", producator="Green flower";
	int constexpr pret = 500;
	p.set_nume(nume);
	p.set_tip(tip);
	p.set_pret(pret);
	p.set_producator(producator);
	assert(p.get_nume() == "Tort");
	

}

void teste_repo()
{
	Lista l;
	Produs p("Prajitura", "Dulce", 200, "Broromir");
	l.adauga_produs(p);
	assert(l.get_size() == 1);
	l.sterge_produs(0);
	assert(l.get_size() == 0);
	l.adauga_produs(p);
	int poz = 0;
	assert(l.cauta_produs("Prajitura",poz).get_pret() != 0);
	try
	{
		assert(l.cauta_produs("Tort",poz).get_pret() == 0);
	}
	catch (RepoExceptions&) {}
	int constexpr pret = 100;
	std::string producator = "Amandia";
	p.set_pret(pret);
	p.set_producator(producator);
	l.modifica_produs(p,0);
	assert(l.get_produs(0).get_pret() == 100);
	//std::vector<Produs> l_all = l.get_all();
	std::vector<Produs> l_all = l.get_all();

}

void teste_service()
{
	//Lista l2;

	Repof l{"teste.csv"};
	Cos cos;
	Validator v;
	Service s(cos,l,v);
	s.adauga_produs_service("Prajitura", "Dulce", 100, "Amandia");
	assert(s.get_size_service() == 1);
	s.modifica_produs_service("Prajitura", 150, "Broromir");
	assert(l.get_produs(0).get_pret() == 150);
	assert(s.cauta_produs_service("Prajitura").get_pret()!=0);
	s.sterge_produs_service("Prajitura");
	assert(s.get_size_service() == 0);
	s.adauga_produs_service("Tort", "Dulce", 200, "Prodo");
	s.adauga_produs_service("Prajitura", "Dulce", 100, "Amandia");
	s.adauga_produs_service("Prajitura", "Cofetarie", 120, "Prod");
	std::vector<Produs> l_noua = s.get_all_service();
	//VectorDinamic<Produs> l_noua = s.get_all_service();
	int constexpr pret = 150;
	std::vector<Produs> l_filtrare = s.filtrare_pret(pret);
	s.sortare_service(l_noua, "nume", false);
	s.sortare_service(l_noua, "pret", true);
	s.sortare_service(l_noua, "nume", true);
	std::vector<Produs> l_filtrare2 = s.filtrare_nume("T");
	std::vector<Produs> l_filtrare3 = s.filtrare_producator("A");
	s.sortare_service(l_noua,"nume+tip", false);
	//l_noua.clear();
	std::map<std::string, DTO> dict = s.statistica();
	DTO p("ana", 0);
	assert(p.get_nr()==0);
	//l.goleste_fisier();

	s.adauga_produs_service("Caramel", "Dulce", 100, "Amandia");
	s.adauga_produs_service("Tort", "Cofetarie", 120, "Prod");
	assert(s.get_size_service() == 5);
	s.undo_service();
	assert(s.get_size_service() == 4);
	s.modifica_produs_service("Caramel", 150, "Dino");
	s.undo_service();
	s.sterge_produs_service("Caramel");
	s.undo_service();
	l.goleste_fisier();
	try
	{
		s.salveaza_cos_service("");
	}
	catch (RepoExceptions& e) { assert(e.getmsg() == "Fisierul nu a putut fi deschis\n"); }
	Repof r2{ "nimic.csv" };
}
void teste_exceptii()
{
	//Lista l2;
	Repof l{ "teste.csv" };
	Cos cos;
	Validator v;
	Service s(cos,l, v);
	Produs p("Tort", "Cofetarie", 200, "Acadia");
	try
	{
		int poz = 0;
		l.cauta_produs("Tort",poz);
	}
	catch (const RepoExceptions& e) { std::string err = e.getmsg(); }
	try
	{
		s.adauga_produs_service("", "", -2, "");
	}
	catch (const ValidatorExceptions& err) { assert(err.getmsg() == "Nume invalid\nPret invalid\nProducator invalid\nTip invalid\n"); }
	l.adauga_produs(p);
	try
	{
		s.modifica_produs_service("Tort", -2, "");
	}
	catch(const ValidatorExceptions& e){ assert(e.getmsg() == "Pret invalid\nProducator invalid\n"); }
	try
	{
		s.modifica_produs_service("Pale", 1, "Top");
	}
	catch (const RepoExceptions& e) { assert(e.getmsg() == "Produsul nu a fost gasit\n"); }
	try
	{
		s.sterge_produs_service("Nume");
	}
	catch (const RepoExceptions& e) { assert(e.getmsg() == "Produsul nu a fost gasit\n"); }
	try
	{
		s.undo_service();
	}
	catch (const RepoExceptions& e) { assert(e.getmsg() == "Nu exista actiuni undo\n"); }
	l.goleste_fisier();
}
void run_tests()
{
	teste_domain();
	teste_repo();
	teste_service();
	teste_exceptii();

}

#include "service.h"
#include "Validator.h"
#include <iostream>
#include <algorithm>
#include <functional>
#include <type_traits>
Service::Service(Cos& co,RepoInterface& repo,Validator& val) noexcept:cos(co),repo(repo),val(val) {}


void Service::adauga_produs_service(std::string nume, std::string tip, int pret, std::string producator)
{
	Produs p(nume, tip, pret, producator);
	std::string err=val.validare(p);
	if (err.size() == 0)
		repo.adauga_produs(p);
	else
		throw(ValidatorExceptions(err));
	undoactiuni.push_back(new UndoAdaugare{ repo,repo.get_size()-1});
}
Produs& Service::cauta_produs_service(std::string nume)
{
	int pozi=-1;
	return repo.cauta_produs(nume,pozi);
}
void Service::modifica_produs_service(std::string nume, int pret_nou, std::string producator_nou)
{
	int pozi = -1;
	try {
		Produs& poz = repo.cauta_produs(nume, pozi);
		Produs p2{ nume,poz.get_tip(),pret_nou,producator_nou };
		std::string err = val.validare(p2);
		if (err.size() == 0)
		{
			undoactiuni.push_back(new UndoModificare{ repo,poz,pozi });
			poz.set_pret(pret_nou);
			poz.set_producator(producator_nou);
			repo.modifica_produs(poz, pozi);
		}
		else
			throw(ValidatorExceptions(err));
		
	}
	catch (const RepoExceptions& e) {
		
		throw(RepoExceptions(e.getmsg()));}
	
	

	

}
void Service::sterge_produs_service(std::string nume)
{
	
	try {
		int poz = -1;
		Produs p=repo.cauta_produs(nume, poz);
		repo.sterge_produs(poz);
		undoactiuni.push_back(new UndoStergere{ repo,p });
	}
	catch (const RepoExceptions& e) {
		
		throw(RepoExceptions(e.getmsg()));}
	
	
}
std::vector<Produs> Service::filtrare_pret(const int& pret_dat)
{
	std::vector<Produs>& produse{ repo.get_all() };
	
	std::vector<Produs> l_filtrare;
	l_filtrare.resize(produse.size());
	
	auto it = std::copy_if(produse.begin(), produse.end(), l_filtrare.begin(), [pret_dat](Produs p) noexcept {return p.get_pret() < pret_dat; });

	l_filtrare.shrink_to_fit();
	return l_filtrare;

}
std::vector<Produs> Service::filtrare_nume(const std::string& nume)
{
	std::vector<Produs>& produse = repo.get_all();
	std::vector<Produs> l_filtrare;
	l_filtrare.resize(produse.size());

	auto it = std::copy_if(produse.begin(), produse.end(), l_filtrare.begin(), [nume](Produs p) {return p.get_nume()[0] == nume[0]; });
	
	l_filtrare.shrink_to_fit();
	return l_filtrare;

}
std::vector<Produs> Service::filtrare_producator(const std::string& nume)
{
	std::vector<Produs>& produse = repo.get_all();
	std::vector<Produs> l_filtrare;
	l_filtrare.resize(produse.size());

	auto it = std::copy_if(produse.begin(), produse.end(), l_filtrare.begin(), [nume](Produs p) {return p.get_producator()[0] == nume[0]; });

	l_filtrare.shrink_to_fit();
	return l_filtrare;

}
//bool Service::compare_string(const Produs& a, const Produs& b)
//{
//	
//	return a.get_nume() < b.get_nume();
//
//	
//}
//bool coompare_string(const Produs& a, const Produs& b)
//{
//	
//	return a.get_nume() < b.get_nume();
//
//
//}
//bool Service::compare_int(const Produs& a, const Produs& b) 
//{
//	
//	return a.get_pret()<b.get_pret();
//}
//bool coompare_int(const Produs& a, const Produs& b)
//{
//	
//	return a.get_pret() < b.get_pret();
//}
//bool Service::compare_doua(const Produs& a, const Produs& b) 
//{
//	if ((a.get_nume() > b.get_nume()) - (a.get_nume() < b.get_nume()) == 0)
//		return (a.get_tip() > b.get_tip()) - (a.get_tip() < b.get_tip());
//	return (a.get_nume() > b.get_nume()) - (a.get_nume() < b.get_nume());
//}
//bool coompare_doua(const Produs& a, const Produs& b)
//{
//	if (a.get_nume()==b.get_nume())
//		return a.get_tip()<b.get_tip();
//	return a.get_nume() < b.get_nume();
//}
void Service::sortare_service(std::vector<Produs>& produse,std::string filtru, bool reverse)
{
	
	if(filtru=="pret")
		std::sort(produse.begin(), produse.end(), [reverse](const Produs& a, const Produs& b) {if (reverse == true) return (a.get_pret() > b.get_pret()); else return (a.get_pret() < b.get_pret()); });
	if (filtru == "nume")
		std::sort(produse.begin(), produse.end(), [reverse](const Produs& a, const Produs& b) {if (reverse == true) return a.get_nume() > b.get_nume(); else return a.get_nume() < b.get_nume(); });
	if(filtru=="nume+tip")
		std::sort(produse.begin(), produse.end(), [reverse](const Produs& a, const Produs& b) {if (a.get_nume() == b.get_nume()) { if (reverse == true) return (a.get_tip() > b.get_tip()); else return (a.get_tip() < b.get_tip()); } else { if (reverse == true) return (a.get_nume() > b.get_nume()); else return (a.get_nume() < b.get_nume()); }});
	

}

std::vector<Produs>& Service::get_all_service() 
{
	return repo.get_all();
}
int Service::get_size_service() 
{
	return repo.get_size();
}
void Service::adauga_produs_cos(std::string nume)
{
	int pozi = -1;
	Produs p=repo.cauta_produs(nume, pozi);
	//cos.adauga_produs(p);
	cos.adauga_produs_cos(p);

}
void Service::sterge_cos()
{
	//cos.golire();
	cos.sterge_cos();
}
#include <random>
void Service::generare_cos(int nr)
{

	const int size = repo.get_size();
	
	if(size)
	for (int i = 1; i <= nr; i++)

	{
		std::mt19937 mt{ std::random_device{}() };
		std::uniform_int_distribution<> dist(0,repo.get_size() - 1);
		const int rndNr = dist(mt);// numar aleator intre [0,size-1]
		cos.adauga_produs_cos(repo.get_produs(rndNr));

	}
	//const std::vector<std::string> in{ "Alex","Constantin","Codrin","Bogdan"};
	//const std::vector<std::string> in2{ "Dulce","Cofetarie","Ala","Patiserie"};
	//const std::vector<std::string> in3{ "Ale","Cons","Cod","Broromir"};
	//const std::vector<int> in4{ 12,321,42,12,43};
	////const std::vector<std::string> in{ "Alex","Constantin","Codrin","Bogdan"};
	//std::vector<std::string> out;
	//std::vector<int>ou2;
	//for (int i = 1; i <= nr; i++)
	//{
	//	std::sample(in.begin(), in.end(), std::back_inserter(out), 1, std::mt19937{ std::random_device{}() });
	//	std::sample(in2.begin(), in2.end(), std::back_inserter(out), 1, std::mt19937{ std::random_device{}() });
	//	std::sample(in3.begin(), in3.end(), std::back_inserter(out), 1, std::mt19937{ std::random_device{}() });
	//	std::sample(in4.begin(), in4.end(), std::back_inserter(ou2), 1, std::mt19937{ std::random_device{}() });
	//	Produs p(out[0], out[1], ou2[0], out[2]);
	//	repo.adauga_produs(p);
	//}
	//
	


}
int Service::get_pret_cos() noexcept
{
	int pret = 0;
	std::vector<Produs>& produse = cos.get_all_cos();
	for (auto& it : produse)
		pret += it.get_pret();
	return pret;

}
std::vector<Produs>& Service::get_all_cos() 
{
	return cos.get_all_cos();

}
void Service::salveaza_cos_service(std::string path)
{
	//Repof::salveaza_cos();
	//std::vector<Produs>& produse = cos.get_all_cos();
	//repo.salveaza_cos(cos);
	try
	{
		cos.salveaza_cos(path);
	}
	catch (RepoExceptions e) { throw e; }
}
std::map<std::string, DTO> Service::statistica()
{
	std::map<std::string, DTO> stat;
	std::vector<Produs>& produse = repo.get_all();
	for (auto& it : produse)
	{
		
		if (stat.find(it.get_tip()) == stat.end())
		{
			DTO p(it.get_tip(), 1);
			stat[it.get_tip()] = p;
			//stat[it.get_tip()].increment();
		}
		else
		{
			stat[it.get_tip()].increment();
		}
	}
	return stat;


}
void Service::undo_service()
{
	if (undoactiuni.empty())
	{
		throw RepoExceptions("Nu exista actiuni undo\n");
	}
	ActiuneUndo* act = undoactiuni.back();
	act->doUndo();
	undoactiuni.pop_back();
	delete act;
}
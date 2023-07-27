//#include "repository.h"
//#include "VectorDinamic.h"
#include <iostream>
#include "RepoLabb.h"
#include <algorithm>
#include <functional>
#include <type_traits>
#include <random>
#include "Exceptions.h"
RepoLab::RepoLab(float pr) noexcept:prob(pr)
{

}


void RepoLab::adauga_produs(Produs p)
{
	
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_real_distribution<> dist(0,1);
	
	if (dist(mt) < prob)
		dict[p.get_nume()] = p;
	else
	{
		throw RepoExceptions("Mesaj\n");
	}
}
void RepoLab::sterge_produs(int poz)
{
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_real_distribution<> dist(0, 1);

	if (dist(mt) < prob)
	{
		int c = 0;
		for (auto it = dict.begin(); it != dict.end(); it++, c++)
			if (c == poz)
			{
				it = dict.erase(it);
				break;}
	}
	else
	{
		throw RepoExceptions("Mesaj\n");
	}
}

Produs& RepoLab::cauta_produs(std::string nume, int& poz)
{

	std::mt19937 mt{ std::random_device{}() };
	std::uniform_real_distribution<> dist(0, 1);

	if (dist(mt) < prob)
	{
		poz = 0;
		auto it = std::find_if(dict.begin(), dict.end(), [nume](std::pair<string,Produs> p) {return p.first == nume; });
		if (it == dict.end())
			throw(RepoExceptions("Produsul nu a fost gasit\n"));
		poz = static_cast<int>(std::distance(dict.begin(), it));
		return dict[nume];}
	else
	{
		throw RepoExceptions("Mesaj\n");}}
void RepoLab::modifica_produs(const Produs& p, int poz)
{
	poz = 0;
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_real_distribution<> dist(0, 1);

	if (dist(mt) < prob)
	{
		dict.at(p.get_nume()) = p;
	}
	else
	{
		throw RepoExceptions("Mesaj\n");
	}


}
Produs& RepoLab::get_produs(int poz)
{

	std::mt19937 mt{ std::random_device{}() };
	std::uniform_real_distribution<> dist(0, 1);


	if (dist(mt) < prob)
	{
		int c = 0;
		for (auto& it : dict)
		{
			if (c == poz)
			{
				return it.second;

			}
			c++;
		}
	}
	else
	{
		throw (RepoExceptions("Mesaj\n"));
	}
	return par;
}

int RepoLab::get_size() 
{
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_real_distribution<> dist(0, 1);

	if (dist(mt) < prob)
	{
		return static_cast<int>(dict.size());}
	else
	{
		throw RepoExceptions("Mesaj\n");
	}
}
std::vector<Produs>& RepoLab::get_all() 
{
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_real_distribution<> dist(0, 1);
	if (dist(mt) < prob)
	{
		produse.clear();
		for (auto& it : dict)
			produse.push_back(it.second);

		return produse;}
	else
	{
		throw RepoExceptions("Mesaj\n");
	}
}


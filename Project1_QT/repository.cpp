#include "repository.h"

	

Lista::Lista() noexcept
{

}

//Lista::~Lista()
//{
//	lista.~vector();
//}
//void Lista::golire()
//{
//	lista.resize(0);
//}
void Lista::adauga_produs(Produs p)
{

	lista.push_back(p);

}
void Lista::sterge_produs(int poz)
{
	int c = 0;
	for (auto it = lista.begin();it != lista.end(); it++, c++)
		if (c == poz)
		{
			it=lista.erase(it);
			break;}

}

Produs& Lista::cauta_produs(std::string nume,int &poz)
{
	
	poz = 0;
	auto it = std::find_if(lista.begin(), lista.end(), [nume](Produs p) {return p.get_nume()==nume; });
	if(it==lista.end())
		throw(RepoExceptions("Produsul nu a fost gasit\n"));
	poz = static_cast<int>(std::distance(lista.begin(),it));
	return *it;
	
}
void Lista::modifica_produs(const Produs& p,int poz)
{
	lista.at(poz) = p;
		
}
Produs& Lista::get_produs(int poz)
{
	return lista.at(poz);
}
int Lista::get_size() noexcept
{
	
	return static_cast<int>(lista.size());
}
std::vector<Produs>& Lista::get_all() noexcept
{
	return lista;

}


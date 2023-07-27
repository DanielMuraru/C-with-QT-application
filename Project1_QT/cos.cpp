#include "cos.h"


void Cos::adauga_produs_cos(Produs p)
{
	
	//cos.adauga_produs(p);
	cosulet.push_back(p);


}
void Cos::sterge_cos()
{
	cosulet.resize(0);
}

std::vector<Produs>& Cos::get_all_cos()
{
	return cosulet;
}
int Cos::get_size()
{
	return static_cast<int>(cosulet.size());
}
void Cos::salveaza_cos(std::string path)
{
	std::ofstream g;
	g.open(path);
	if (!g.fail())
	{
		std::vector<Produs> produse = cosulet;
		for (const auto& it : produse)
		{
			g << it.get_nume() << " " << it.get_tip() << " " << it.get_pret() << " " << it.get_producator() << "\n";
		}
		g.close();
	}
	else throw(RepoExceptions("Fisierul nu a putut fi deschis\n"));
}
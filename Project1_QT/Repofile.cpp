#include "Repofile.h"
using std::ifstream;
using std::ofstream;
using std::vector;
#include <vector>
Repof::Repof(string nume) :Lista(),path(nume) {
	ifstream f(path);
	string a;
	string b;
	string d;
	int c;
	while (f >> a >> b >> c >> d)
	{
		Produs p{ a,b,c,d };
		Lista::adauga_produs(p);
	}
	f.close();
}
void Repof::adauga_produs(Produs p)
{	
	Lista::adauga_produs(p);
	writetofile();
	
}
void Repof::sterge_produs(int poz)
{
	int c = 0;
	for (auto it = Lista::get_all().begin(); it != Lista::get_all().end(); it++, c++)
		if (c == poz)
		{
			it = Lista::get_all().erase(it);
			break;}
	writetofile();

}
void Repof::modifica_produs(const Produs& p,int poz)
{
	Lista::modifica_produs(p,poz);
	writetofile();


}
void Repof::writetofile()
{
	ofstream g(path);
	std::vector<Produs> produse = Lista::get_all();
	for (const auto& it : produse)
	{
		g << it.get_nume() << " " << it.get_tip() << " " << it.get_pret() << " " << it.get_producator() << "\n";
	}
	g.close();

}

void Repof::goleste_fisier()
{
	ofstream g(path);
	g.close();


}
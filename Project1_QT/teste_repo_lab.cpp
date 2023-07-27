#include "teste_repo_lab.h"
#include "Exceptions.h"
void test_r()
{
	RepoLab repo{ 1 };
	Produs p{ "Tort","Dulce",200,"Prod" };
	repo.adauga_produs(p);
	assert(repo.get_size() == 1);
	int poz = 0;
	repo.get_produs(0);
	repo.get_produs(2);
	repo.cauta_produs("Tort", poz);
	try 
	{
		repo.cauta_produs("Casa", poz);
	}
	catch (RepoExceptions&){}
	Produs p_modificat("Tort", "Dulce", 1000, "Broro");
	repo.modifica_produs(p_modificat, 0);
	std::vector<Produs> repolab = repo.get_all();
	repo.sterge_produs(0);
	
	

}

void test_r2()
{
	RepoLab repo{ 0 };

	Produs p{ "Tort","Dulce",200,"Prod" };
	try { repo.adauga_produs(p); }
	catch (RepoExceptions&) {}
	try
	{
		repo.get_produs(0);
	}
	catch (RepoExceptions&){}
	try
	{
		repo.get_size();
	}
	catch(RepoExceptions&){}
	int poz = 0;
	try {
		repo.cauta_produs("Tort", poz);
	}
	catch (RepoExceptions&) {}
	Produs p_modificat("Tort", "Dulce", 1000, "Broro");
	try
	{
		repo.modifica_produs(p_modificat, 0);
	}
	catch (RepoExceptions&) {}
	try
	{
		repo.sterge_produs(0);
	}
	catch (RepoExceptions&){}
	try
	{
		std::vector<Produs> repolab = repo.get_all();}
	catch (RepoExceptions&){}
}
void run_teste_lab()
{
	test_r();
	test_r2();


}
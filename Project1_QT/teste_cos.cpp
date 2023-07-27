#include <iostream>
#include "teste_cos.h"
#include <assert.h>
void run_teste_cos()
{
	Lista mag2;
	Repof mag{ "teste.csv" };
	Cos cos;
	Validator v;
	Service magazin(cos,mag,v);
	Produs p{ "And","DULCE",21,"Bror" };
	mag.adauga_produs(p);
	magazin.adauga_produs_cos("And");
	assert(cos.get_size() == 1);
	magazin.sterge_cos();
	assert(cos.get_size() == 0);
	magazin.generare_cos(5);
	assert(cos.get_size() == 5);
	magazin.get_pret_cos();
	std::vector<Produs> cosulet = magazin.get_all_cos();
	magazin.salveaza_cos_service("test_cos.csv");
	/*std::vector<Produs> lis = cos.get_all();
	for (auto& it : lis)
		std::cout << it.get_nume() << " " << it.get_tip() << " " << it.get_pret() << " " << it.get_producator() << "\n";*/
	mag.goleste_fisier();


}
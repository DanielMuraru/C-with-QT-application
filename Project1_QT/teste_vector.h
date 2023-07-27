#pragma once
//#include "VectorDinamic.h"
#include "VectorDTemplate.h"
#include <assert.h>

void runnning()
{

	VectorDinamic<Produs> v;
	Produs p("Torta", "Dulce", 200, "Prod");
	Produs p2("Praj", "Dulce", 200, "Prod");
	Produs p3("Pralina", "Dulce", 200, "Prod");
	v.push_back(p);
	v.push_back(p2);
	v.push_back(p3);
	assert(v.size() == 3);
	assert(v.at(0).get_nume() == p.get_nume());
	const Iterator<Produs> it = v.begin();
	v.erase(it);
	assert(v.size() == 2);
	Iterator<Produs> ic2 = v.begin();
	while (ic2.valid())
	{	
		Produs p_it = ic2.element();
		ic2.urmator();
	}

}

void run_teste_vector()
{
	runnning();
	//testAll<VectorDinamic<Produs>>();
}
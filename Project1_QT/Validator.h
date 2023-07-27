#pragma once
#include <string>
#include "repository.h"
class Validator
{

private:
	std::string erori="";

public:
//	~Validator() { erori.clear(); }
	std::string& validare(const Produs& p)
	{
		erori.erase();
		if (p.get_nume().size() == 0)
			erori += "Nume invalid\n";
		if (p.get_pret() <= 0)
			erori += "Pret invalid\n";
		if (p.get_producator().size() == 0)
			erori += "Producator invalid\n";
		if (p.get_tip().size() == 0)
			erori += "Tip invalid\n";
		return erori;
	}


};
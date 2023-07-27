#include "domain.h"

Produs::Produs(std::string num,std::string tip,int pret,std::string producator):nume(num),tip(tip),pret(pret),producator(producator)
{

}

//Produs::~Produs()
//{
//	nume.erase();
//	tip.erase();
//	pret = 0;
//	producator.erase();
//
//}
std::string Produs::get_nume() const
{
	return this->nume;

}
std::string Produs::get_tip() const
{
	return this->tip;
}
int Produs::get_pret() const noexcept
{
	return this->pret;
}
std::string Produs::get_producator() const
{
	return this->producator;
}
void Produs::set_nume(const std::string& nume_nou)
{
	this->nume = nume_nou;
}
void Produs::set_tip(const std::string& tip_nou)
{
	this->tip = tip_nou;
}
void Produs::set_pret(const int& pret_nou) noexcept
{
	this->pret = pret_nou;
}
void Produs::set_producator(const std::string& producator_nou)
{
	this->producator = producator_nou;
}
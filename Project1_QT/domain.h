#pragma once
#include <string>
#include <iostream>
class Produs
{
private:
	std::string nume;
	std::string tip;
	int pret=0;
	std::string producator;

public:
	Produs() = default;
	Produs(std::string,std::string,int,std::string);
	//Produs(const Produs& ot):nume(ot.nume),tip(ot.tip),pret(ot.pret),producator(ot.producator){ }
	~Produs()=default;
	/*
		Returneaza numele produsului
		return: string -numele produsului
	
	*/
	std::string get_nume() const ;

	/*
		Returneaza tipul produsului
		return:string-tipul produsului
	*/
	std::string get_tip()const ;

	/*
		Returneaza pretul produsului
		return:int-pretul produsului
	
	*/
	int get_pret()const noexcept;

	/*
		Returneaza producatorul produsului
		return:string-producatorul produsului
	*/
	std::string get_producator()const ;

	/*
		Seteaza numele unui produs
		param:string&:referinta catre string-ul cu numele nou
		return:-
	*/
	void set_nume(const std::string&);

	/*
		Seteaza tipul unui produs
		param:string&:referinta catre string-ul cu tipul nou
		return:-
	*/
	void set_tip(const std::string&);

	/*
		Seteaza pretul unui produs
		param:int&:referinta catre pretul nou de tip int
		return:-
		
	*/
	void set_pret(const int&) noexcept;

	/*
		Seteaza producatorul unui produs
		param:string&:referinta catre string-ul cu producatorul nou
		return:-
	*/
	void set_producator(const std::string&);



};
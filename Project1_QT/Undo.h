#pragma once
//#include "ui.h"
class ActiuneUndo
{

public:
	virtual void doUndo()=0;
	virtual ~ActiuneUndo() {};

};
class UndoAdaugare :public ActiuneUndo
{
private:
	int pozitie ;
	RepoInterface& repo;
public:
	
	UndoAdaugare(RepoInterface& r, int p) :repo(r), pozitie(p) {}
	void doUndo() override {
		
		repo.sterge_produs(pozitie);
	}
	
	

};
class UndoStergere :public ActiuneUndo
{
private:
	Produs p_sters;
	RepoInterface& repo;
public:
	UndoStergere(RepoInterface& r, Produs p) :repo(r),p_sters(p){}
	void doUndo() override{
	
		repo.adauga_produs(p_sters);
	}

};
class UndoModificare:public ActiuneUndo
{
private:
	Produs p_nemodificat;
	int pozitie;
	RepoInterface& repo;
public:
	UndoModificare(RepoInterface& r, Produs p,int poz) :repo(r), p_nemodificat(p),pozitie(poz) {}
	void doUndo() override {
		
		repo.modifica_produs(p_nemodificat, pozitie);
	}

};

#pragma once
#include "GUI.h"

class Observer
{
private:

public:
	virtual void update() = 0;
};
class Observable
{
private:
	std::vector<Observer*> list_of_observers;

public:

	void addObs(Observer* o)
	{
		list_of_observers.push_back(o);
	}
	void removeObs(Observer* o)
	{
		list_of_observers.erase(std::remove(begin(list_of_observers), end(list_of_observers), o),
			list_of_observers.end());

	}
	void notify() const
	{
		for (auto& it : list_of_observers)
			it->update();
	}

};
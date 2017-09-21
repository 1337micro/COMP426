#pragma once
#include "Observer.h"
#include <vector>
#include <algorithm>
using std::vector;

class Observable {
private:
	vector<Observer*> observers;
public:
	virtual void attach(Observer* o) {
		observers.push_back(o);
	}
	virtual void detach(Observer* o) {
		observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());
	};
	virtual void notify() {
		for (vector<Observer*>::size_type i = 0; i < observers.size(); i++) {
			observers[i]->update();
		}
	};
};
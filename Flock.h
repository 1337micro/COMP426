#pragma once
#include "Observer.h"
#include "Position.h"
enum FlockNames {
	A, B, C, D, E, F, G, H, J, K
};
class Flock : public Observer {
private:
	Euclidean::Position position;
	FlockNames name;
public:
	void setPosition(Euclidean::Position position) {
		this->position = position;

	}
	void setPosition(float x, float y, float z) {
		setPosition(Euclidean::Position(x, y, z));
	}
	void setName(FlockNames name) {
		this->name = name;
	}
	Flock() {

	}
	Flock(int name) {
		setName(FlockNames(name));
	}
	Flock(int name,  float x, float y, float z) {
		setName(FlockNames(name));
		setPosition(x, y, z);
	}
	FlockNames getName() {
		return name;
	}
	void Observer::update() {
	}
};
#pragma once
#include "Position.h"
#include "Observable.h"

class Bird : public Observable {
	
public:
	const static float Bird::Size;
	FlockNames flockName;
	Euclidean::Position position;
	Euclidean::Velocity velocity;

	

	Bird() {

	}
	Bird(FlockNames name) {
		this->flockName = name;
	}
};
const float Bird::Size = 0.1;
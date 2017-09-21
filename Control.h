#pragma once
#include "Flock.h"
#include "Bird.h"
#include <vector>

class Control
{
public:
	std::vector<Bird> birds; //
	Control();
	~Control();
	void initBirds();
};



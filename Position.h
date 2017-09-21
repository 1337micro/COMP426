#pragma once

#include <random>

namespace Euclidean {
	class Position {
	public:
		float x, y, z;
		Position(float x, float y, float z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}
		Position() {
			this->x = 0;
			this->y = 0;
			this->z = 0;
		}

	
	};
	


	class Vector {
	public:
		float i, j, k;
		Vector() {

		}
		Vector(float i, float j, float k) {
			this->i = i;
			this->j = j;
			this->k = k;
		}
		Vector operator+(const Vector& v) {
			i = v.i;
			j = v.j;
			k = v.k;
		}

	};

	class Velocity {
	public:
		Vector velocity;
		Velocity() {
			this->velocity = Vector(0, 0, 0);
		}
		Velocity(float i, float j, float k) {
			this->velocity = Vector(i, j, k);
		}
	};
}
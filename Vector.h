#ifndef VECTOR_CJM
#define VECTOR_CJM
#include "Planet.h"
#include "Star.h"

class Vector {
	public:
		Vector() {
			this->size = -1;
			this->arr = NULL;
		}
		Vector(int);
		Vector(int, Planet**);
		unsigned size() {
			return this->size;
		}
		Vector(const Vector & vec);
		~Vector();
		void insert (int, Planet *);
		Planet* read(int);
		bool remove(int);
		Planet** arr;
	private:
		unsigned size;
};

class Starvector {
	public:
		Starvector();
		~Starvector();
		long addPlanet();
		bool removePlanet();
		Planet * getPlanet(int);
		void orbit();
		void printStarInfo();
		unsigned int getCurrentNumPlanets();
};
#endif

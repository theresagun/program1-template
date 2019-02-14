#ifndef VECTOR_CJM
#define VECTOR_CJM
#include "Planet.h"
#include "Star.h"

class Vector {
	public:
		unsigned size();
		~Vector();
		void insert (int, Planet *);
		Planet* read(int);
		bool remove(int);
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

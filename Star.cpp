#include "Star.h"
#include <cstdlib>
#include <iostream>

Star::Star() {
	this->current_planets = 0;
	this->next_id = 0;
	this->planets = NULL;
}

Star::~Star() {
	for (int i = 0; i < this->current_planets; i++) {
		delete planets[i];
	}

	delete [] planets;
}

int Star::addPlanet() {
	int distance = rand() % 3000; 
	Planet ** nextplanets = new Planet * [this->current_planets + 1];

	for (int i = 0; i < this->current_planets; i++) {
		nextplanets[i] = planets[i];
	}

	Planet * new_planet = new Planet(distance);

	nextplanets [this->current_planets] = new_planet;

	delete [] planets;

	planets = nextplanets;
	this->current_planets++;
	this->next_id++;
	return new_planet->getID();
}

bool Star::removePlanet(int del) {
	if (!getPlanet(del)) return false;

	Planet ** new_planets = new Planet*[this->current_planets - 1];

	int j = 0;
	for (int i = 0; i < this->current_planets; i++) {
		if (this->planets[i]->getID() == del) delete this->planets[i];
		else {
			new_planets[j] = this->planets[i];
			j++;
		}
	}

	delete [] this->planets;
	this->planets = new_planets;
	this->current_planets--;

	return true;
}

Planet * Star::getFurthest() {
	int maxdist = 0;
	int index = 0;
	for (int i = 0; i < this->current_planets; i++) {
		if (this->planets[i]->getDistance() > maxdist) {
			index = i;
			maxdist = planets[i]->getDistance();
		}
	}
	return planets[index];
}

Planet * Star::getPlanet(int id) {
	for (int i = 0; i < this->current_planets; i++) {
		if (planets[i]->getID() == id) {
			return planets[i];
		}
	}
	return NULL;
}

void Star::orbit() {
	for (int i = 0; i < this->current_planets; i++) {
		planets[i]->orbit();
	}
}

void Star::printStarInfo() {
	std::cout << "This star has " << this->current_planets << " planets." << std::endl;
	std::cout << "Planets:" << std::endl;
	for (int i = 0; i < this->current_planets; i++) {
		std::cout << "\tPlanet " << planets[i]->getType() << planets[i]->getID()<< " is " << planets[i]->getDistance() << " miles away at position " << planets[i]->getPos() << " around the star." << std::endl;
	}
}



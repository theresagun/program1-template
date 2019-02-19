#include "Star.h"
#include <cstdlib>
#include <iostream>

Planet::Planet(int distance){
	int rev = rand() % 360;
	char types[3] = {'h', 'r', 'g'};
	this->id = &this;
	this->distance = distance;
    	this->pos = rev;
	this->type = types[rand() % 3];
}

int Planet::orbit(){
	if (pos >= 0 && pos < 359) {
		this->pos++;
	}
	else {
		this->pos = 0;
	}
	return this->pos;
}

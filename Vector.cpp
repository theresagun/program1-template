#include "Vector.h"

Vector::Vector(int len) {
	this->size = len;
	this->arr = new Planet* [this->size];
}

Vector::Vector(int len, Planet** newarr) {
	this->size = len;
	this->arr = newarr;
}

Vector::Vector (const Vector &vec) {
	copy = new Planet* [vec->size];
	for (int i = 0; i < vec->size(); i++) {
		copy[i] = vec->arr[i];
	}
	cvec = new Vector(vec->size, copy);
	return cvec;
}

Vector::~Vector() {
	for (int i = 0; i < this->size(); i++) {
		delete this->arr[i];
	}
	delete [] this->arr;
}

void Vector::insert (int index, Planet * p) {
	Planet ** newarr = new Planet * [this->size() + 1];
	int oldindex = 0;
	for (int i = 0; i < this->size()+1; i++) {
		if (i == index) {
			newarr[i] = p;
		}
		else {
			newarr[i] = this->arr[oldindex];
			oldindex++;
		}
	}

	for (int i = 0; i < this->size(); i++) {
		delete this->arr[i];
	}
	this->arr = newarr;
	this->size++;

	delete [] planets;
}


	
	

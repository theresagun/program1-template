#ifndef LIST_TG
#define LIST_TG
#include "Planet.h"
#include "Star.h"
#include <iostream>

class Node{
	public:
		Node(Planet);
		Planet data;
		Node * next;
		Node * previous;
};

class List{
	private:
		Node * head;
		Node * tail;
		int listSize;
	public:
		List();
		~List();
		void insert(int, Planet *);
		Planet * read(int);
		bool remove(int);
		unsigned size();
};

class Starlist{
	public:
		Starlist();
		~Starlist();
		long addPlanet();
		bool removePlanet(int);
		Planet * getPlanet(int);
		void orbit();
		void printStarInfo();
		unsigned int getCurrentNumPlanets();
};
#endif

#include "List.h"
#include "Planet.h"
#include "Star.h"
#include <cstdlib>
#include <iostream>

Node::Node(Planet d){
	data = d;
	next = NULL;
	previous = NULL;
}

List::List(){
	this->head = NULL;
	this->tail = NULL;
	this->listSize = 0;
}

List::~List(){
	if(head != NULL){
		Node * temp = head;
		while(head != NULL){
			temp = head;
			head = head->next;
			delete temp;
		}
	}
}

void List::insert(int index, Planet * p){
	Node * newPlanet = new Node(*p);
	if(head == NULL){
		head = newPlanet;
		tail = newPlanet;
	}
	else if(index > listSize){
		tail->next = newPlanet;
		newPlanet->previous = tail;
		tail = newPlanet;
	}
	else{
		Node * temp = head;
		for(int i = 0; i < index; i++){
			temp = temp->next;
		}
		newPlanet->previous = temp;
		newPlanet->next = temp->next;
		(newPlanet->previous)->next = newPlanet;
		(newPlanet->next)->previous = newPlanet;
	}
	listSize++;
}

Planet * List::read(int index){
	if(index > listSize){
		return NULL;
	}
	Node * temp = head;
	for(int i = 0; i <= index; i++){
		temp = temp->next;
	}
	return &(temp)->data;
}

bool List::remove(int index){
	if(index > listSize){
		return false;
	}
	else{
		Node * temp = head;
		for(int i = 0; i <= index; i++){
			temp = temp->next;
		}
		(temp->previous)->next = temp->next;
		(temp->next)->previous = temp->previous;
		delete temp;
		listSize--;
		return true;
	}
}

unsigned List::size(){
	return listSize;
}

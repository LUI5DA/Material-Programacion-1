#pragma once
#include "Nodo.h"

class Pila
{
	Nodo2* head;
public:
	Pila();

	// metodos a implementar
	void push(char);

	char pop();

	char top();

	bool isEmpty();

};


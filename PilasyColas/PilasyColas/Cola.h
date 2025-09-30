#pragma once
#include "Nodo.h"
class Cola
{
	Nodo1* first;
	Nodo1* last;

public:
	Cola();
	~Cola();

	// Metodos a implementar
	void enqueue(Paquete*);

	Paquete* dequeue();

	Paquete* head(); // este es el metodo front, lo llamamos head para evitar colisiones de nombre con otra funcion con ese mismo nombre...

	bool isEmpty();
};


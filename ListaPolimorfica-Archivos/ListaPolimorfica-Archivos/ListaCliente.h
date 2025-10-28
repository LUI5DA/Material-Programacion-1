#pragma once
#include "Cliente.h"

class NodoCliente {
public:
	Cliente* p;
	NodoCliente* siguiente;
	NodoCliente(Cliente* pr, NodoCliente* sig);
};

class ListaCliente
{
private:
	NodoCliente* first;

public:
	ListaCliente();
	virtual ~ListaCliente();

	void add(Cliente*);
	Cliente* search(int id);
	void remove(int id);

	string toString();
	void write(ofstream& f);
};


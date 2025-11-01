#pragma once
#include "Producto.h"
#include "Fecha.h"

class NodoProducto {
public:
	Producto* p;
	NodoProducto* siguiente;
	NodoProducto(Producto* pr, NodoProducto* sig);
};

class ListaProducto
{
private:
	NodoProducto* first;

public:
	ListaProducto();
	virtual ~ListaProducto();

	void add(Producto*);
	Producto* search(int id);
	void remove(int id);

	string toString();
	string mostrarProductosVencidos(Fecha*);
	void write(ofstream& f);
};


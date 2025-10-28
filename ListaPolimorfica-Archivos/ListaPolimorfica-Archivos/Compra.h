#pragma once
#include "Cliente.h"	
#include "ListaLineas.h"
#include "ListaProducto.h"
#include "ListaCliente.h"


class Compra
{
private:
	int id;
	Cliente* cliente;
	ListaLineas* productos;

public:
	Compra(int, Cliente*, ListaLineas* productos);
	~Compra();
	int getId();
	Cliente* getCliente();
	ListaLineas* getProductos();
	void setId(int);
	void setCliente(Cliente*);
	void addProducto(Producto*, int, double);
	string toString();
	void write(ofstream&);
	static Compra* read(ifstream&, ListaCliente*, ListaProducto*);


};


#pragma once
#include "ListaCliente.h"
#include "ListaProducto.h"
#include "ListaCompras.h"

class Serializer
{
public:
	static void saveData(ListaCliente*, ListaProducto*, ListaCompras*);
	static ListaCliente* readClientes();
	static ListaProducto* readProductos();
	static Producto* readProducto(ifstream& f);
	static ListaCompras* readCompras(ListaCliente*, ListaProducto*);
};


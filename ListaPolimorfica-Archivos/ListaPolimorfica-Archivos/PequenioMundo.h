#pragma once
#include "ListaCompras.h"
#include "ListaCliente.h"
#include "ListaProducto.h"
#include "Serializer.h"
#include "Fecha.h"
class PequenioMundo
{
private:
	ListaCliente* clientes;
	ListaProducto* productos;
	ListaCompras* compras;
public:
	PequenioMundo();
	virtual ~PequenioMundo();
	void cargarDatos();
	void guardarDatos();

	ListaCliente* getClientes();
	ListaProducto* getProductos();

	void agregarCliente(Cliente* c);
	void agregarProducto(Producto* p);
	void agregarCompra(Compra* c);

	string mostrarClientes();
	string mostrarProductos();
	string mostrarCompras();
	string mostrarProductosVencidos(Fecha*);
};


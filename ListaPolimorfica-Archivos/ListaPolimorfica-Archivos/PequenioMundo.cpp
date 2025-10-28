#include "PequenioMundo.h"

PequenioMundo::PequenioMundo()
{
	cargarDatos();
}

PequenioMundo::~PequenioMundo()
{
    delete clientes;
    delete productos;
	delete compras;
}

void PequenioMundo::cargarDatos()
{
	this->clientes = Serializer::readClientes();
	this->productos = Serializer::readProductos();
	this->compras = Serializer::readCompras(clientes, productos);
}

void PequenioMundo::guardarDatos()
{
	Serializer::saveData(clientes, productos, compras);
}

void PequenioMundo::agregarCliente(Cliente* c)
{
	clientes->add(c);
}

void PequenioMundo::agregarProducto(Producto* p)
{
	productos->add(p);
}

void PequenioMundo::agregarCompra(Compra* c)
{
	compras->add(c);
}


ListaCliente* PequenioMundo::getClientes()
{
	return clientes;
}

ListaProducto* PequenioMundo::getProductos() {
	return productos;
}


string PequenioMundo::mostrarClientes()
{
    return clientes->toString();
}

string PequenioMundo::mostrarProductos()
{
	return productos->toString();
}

string PequenioMundo::mostrarCompras()
{
    return compras->toString();
}

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

// una clase de servicio es una para realizar una tarea especifica

void PequenioMundo::guardarDatos()
{
	Serializer::saveData(clientes, productos, compras); // clase de servicio
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

string PequenioMundo::mostrarProductosVencidos(Fecha* f)
{
	return productos->mostrarProductosVencidos(f);
}

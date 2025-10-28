#include "LineaCompra.h"

LineaCompra::LineaCompra(Producto* p, int cantidad, double descuento)
{
	this->cantidad = cantidad;
	this->descuento = descuento;
	this->producto = p;
}

LineaCompra::~LineaCompra()
{
	// no eliminamos el producto porque es una agregacion
}

Producto* LineaCompra::getProducto()
{
    return producto;
}

int LineaCompra::getCantidad()
{
    return cantidad;
}

int LineaCompra::getId()
{
	return id;
}

void LineaCompra::setId(int i)
{
	id = i;
}

double LineaCompra::getDescuento()
{
    return descuento;
}

void LineaCompra::setCantidad(int c)
{
	cantidad = c;
}

void LineaCompra::setDescuento(double d)
{
	descuento = d;
}

double LineaCompra::calcularSubtotal()
{
	double precioTotal = producto->calcularPrecio() * cantidad;
	double descuentoTotal = precioTotal * (descuento / 100.0);
	return precioTotal - descuentoTotal;
}

string LineaCompra::toString()
{
	stringstream s;
	s << "--------------------------------------------------------" << endl;
	s << "Linea de compra:" << endl;
	s << producto->toString();
	s << "Cantidad: " << cantidad << endl;
	s << "Descuento: " << descuento << "%" << endl;
	s << "Subtotal: " << calcularSubtotal() << endl;
	s << "--------------------------------------------------------" << endl;
	return s.str();
}

void LineaCompra::write(ofstream& descriptor)
{
	// escribir el id del producto
	descriptor << producto->getId() << '\t';
	descriptor << cantidad << '\t';
	descriptor << descuento << '\n';
}

LineaCompra* LineaCompra::read(ifstream& descriptor, ListaProducto* listaProductos)
{
	string idStr;
	string cantidadStr;
	string descuentoStr;
	descriptor >> idStr;
	descriptor >> cantidadStr;
	descriptor >> descuentoStr;
	int id = stoi(idStr);
	int cantidad = stoi(cantidadStr);
	double descuento = stod(descuentoStr);
	Producto* p = listaProductos->search(id);
	if (p == nullptr) {
		// manejar el error si el producto no se encuentra
		return nullptr;
	}
	return new LineaCompra(p, cantidad, descuento);
}
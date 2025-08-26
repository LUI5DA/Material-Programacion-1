#include "Producto.h"

Producto::Producto()
{
	codigo = 0;
	nombre = "SIN DEFINIR";
	precio = 0;
	cantidad = 0;
	iva = nullptr;
	fechaVencimiento = NULL;
}

Producto::Producto(int codigo, string nombre, float precio, int cantidad, IVA* iva, int dia, int mes, int anio)
{
	this->codigo = codigo;
	this->nombre = nombre;
	this->precio = precio;
	this->cantidad = cantidad;
	this->iva = iva;
	this->fechaVencimiento = new Fecha(dia, mes, anio);
}

Producto::Producto(Producto* producto)
{
	codigo = producto->codigo;
	nombre = producto->nombre;
	precio = producto->precio;
	cantidad = producto->cantidad;
	iva = producto->iva;
	fechaVencimiento = new Fecha(producto->fechaVencimiento);
}

Producto::~Producto()
{
	delete fechaVencimiento;
}

int Producto::getCodigo()
{
	return codigo;
}

string Producto::getNombre()
{
	return nombre;
}

float Producto::getPrecio()
{
	return precio;
}

int Producto::getCantidad()
{
	return cantidad;
}

string Producto::getFechaVencimiento()
{
	return fechaVencimiento->mostrarFecha();
}

void Producto::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Producto::setPrecio(float precio)
{
	this->precio = precio;
}

float Producto::calcularPrecioConIva()
{
	return precio + iva->calcularIva(precio);
}

string Producto::mostrarProducto()
{
	stringstream s;
	s << "Codigo: " << codigo << endl;
	s << "Nombre: " << nombre << endl;
	s << "Unidades disponibles: " << cantidad << endl;
	s << "Precio sin IVA: " << precio << endl;
	s << "Precio con IVA: " << calcularPrecioConIva() << " (+" << iva->getIva()<< "%)" << endl;
	s << "Fecha de vencimiento: " << getFechaVencimiento() << endl;
	return s.str();
}



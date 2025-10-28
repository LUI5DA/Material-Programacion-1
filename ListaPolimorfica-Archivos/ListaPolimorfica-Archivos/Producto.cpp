#include "Producto.h"
#include "Fecha.h"

Producto::Producto(int id, string descripcion, double precio , double IVA, string marca)
{
    this->id = id;
    this->descripcion = descripcion;
    this->precio = precio;
    this->IVA = IVA;
    this->marca = marca;
}

Producto::~Producto()
{
}

int Producto::getId()
{
    return this->id;
}

string Producto::getDescripcion()
{
    return this->descripcion;
}

double Producto::getPrecio()
{
    return this->precio;
}

double Producto::getIVA()
{
    return this->IVA;
}

string Producto::getMarca()
{
    return this->marca;
}

void Producto::setDescripcion(string descripcion)
{
    this->descripcion = descripcion;
}

void Producto::setPrecio(double precio)
{
    this->precio = precio;
}

void Producto::setIVA(double IVA)
{
    this->IVA = IVA;
}

string Producto::toString()
{
    stringstream s;
    s << "Producto: " << endl <<
        "id: " << this->id << endl <<
        "descripcion: " << this->descripcion << endl <<
        "precio: " << this->precio << endl <<
        "IVA: " << this->IVA << "%" << endl;

    return s.str();
}

double Producto::calcularPrecio()
{
    return this->precio + this->IVA * this->precio;
}

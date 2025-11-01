#pragma once
#include "Producto.h"
#include "Fecha.h"
class Perecedero : public Producto
{
protected:
    Fecha* expira;

public:
    Perecedero(int, string, double, double, string, Fecha*);
    virtual ~Perecedero();

    Fecha* getFecha();
    void setFecha(Fecha*);

    virtual string toString();

    virtual void write(ofstream&) = 0;
    bool estaVencido(Fecha* f);
};


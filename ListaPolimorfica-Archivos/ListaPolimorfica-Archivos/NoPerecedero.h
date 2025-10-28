#pragma once
#include "Producto.h"

class NoPerecedero: public Producto
{
protected:
	int aniosGarantia;
public:
	NoPerecedero(int, string, double, double, string, int);
	virtual ~NoPerecedero();
	int getAniosGarantia();
	void setAniosGarantia(int);
	virtual string toString();
	// metodos para usar archivos
	virtual void write(ofstream&) = 0;
};


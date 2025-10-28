#pragma once
#include "Perecedero.h"

class Bebida :
    public Perecedero
{
private:
	double porcentajeAzucar;
	double porcentajeAlcohol;

public:
	Bebida(int, string, double, double, string, Fecha*, double, double);
	virtual ~Bebida();
	double getPorcentajeAzucar();
	double getPorcentajeAlcohol();
	void setPorcentajeAzucar(double);
	void setPorcentajeAlcohol(double);
	virtual string toString();
	// metodos para usar archivos
	static Bebida* read(ifstream& descriptor);
	void write(ofstream& descriptor);
};


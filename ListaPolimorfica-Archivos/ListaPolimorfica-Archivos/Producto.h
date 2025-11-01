#pragma once
#include<iostream>
#include <sstream>
#include<fstream>
#include "Fecha.h"
using namespace std;

class Producto
{
protected:
	int id;
	string descripcion;
	double precio;
	double IVA;
	string marca;

public:
	Producto(int, string, double, double, string);
	virtual ~Producto();

	int getId();
	string getDescripcion();
	double getPrecio();
	double getIVA();
	string getMarca();


	void setDescripcion(string);
	void setPrecio(double);
	void setIVA(double); 

	virtual string toString();
	virtual double calcularPrecio();

	virtual void write(ofstream&) = 0;
	virtual bool estaVencido(Fecha*);

};


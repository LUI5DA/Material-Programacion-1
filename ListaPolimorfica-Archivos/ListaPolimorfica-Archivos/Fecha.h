#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;


class Fecha
{
private:
	int dia;
	int mes;
	int anio;

public:
	Fecha(int dia, int mes, int anio);
	virtual ~Fecha();

	int getDia();
	int getMes();
	int getAnio();

	void setDia(int dia);
	void setMes(int mes);
	void setAnio(int anio);

	string toString();

	// 2 metodos para trabajar con archivos

	static Fecha* read(ifstream& descriptor);
	void write(ofstream& descriptor);


};


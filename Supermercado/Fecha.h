#pragma once

#include <iostream>
#include <sstream>

using namespace std;

class Fecha
{
	private:
		int* dia;
		int* mes;
		int* anio;

	public:
		Fecha();
		Fecha(int, int, int);
		Fecha(Fecha*);
		~Fecha();

		int getDia();
		void setDia(int dia);

		int getMes();
		void setMes(int mes);

		int getAnio();
		void setAnio(int anio);

		string mostrarFecha();
		string mostrarFechaCorta();
};


#pragma once
#include "NoPerecedero.h"

class Herramienta : public NoPerecedero
{
	private:
		double peso;
	public:
		Herramienta(int, string, double, double, string, int, double);
		virtual ~Herramienta();
		double getPeso();
		void setPeso(double);
		virtual string toString();
		// metodos para usar archivos
		static Herramienta* read(ifstream& descriptor);
		void write(ofstream& descriptor);
};


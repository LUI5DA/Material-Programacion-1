#pragma once
#include "NoPerecedero.h"
class Electrodomestico : public NoPerecedero
{
	private:
		double voltaje;
	public:
		Electrodomestico(int, string, double, double, string, int, double);
		virtual ~Electrodomestico();
		double getVoltaje();
		void setVoltaje(double);
		virtual string toString();
		// metodos para usar archivos
		static Electrodomestico* read(ifstream& descriptor);
		void write(ofstream& descriptor);

};


#pragma once
#include "NoPerecedero.h"
class Ropa : public NoPerecedero
{
private:
	string talla;

public:
	Ropa(int, string, double, double, string, int, string);
	virtual ~Ropa();
	string getTalla();
	void setTalla(string);
	virtual string toString();
	// metodos para usar archivos
	static Ropa* read(ifstream& descriptor);
	void write(ofstream& descriptor);

};


#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class Mascota {
private:
	int edad;
	string id;
	string nombre;
	string especie;

public:

	Mascota(int, string, string, string);
	Mascota();
	virtual ~Mascota();

	int getEdad();
	string getId();
	string getNombre();
	string getEspecie();

	void setEdad(int);
	void setId(string);
	void setNombre(string);
	void setEspecie(string);

	string toString();
};
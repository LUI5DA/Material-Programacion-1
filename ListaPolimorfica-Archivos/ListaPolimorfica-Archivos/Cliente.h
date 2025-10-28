#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

class Cliente
{
private:
	int id;
	string nombre;

public:	
	Cliente(int, string);
	int getId();
	string getNombre();
	void mostrar();
	string toString();
	void setId(int);
	void setNombre(string);

	void write(ofstream&);
	static Cliente* read(ifstream&);
};


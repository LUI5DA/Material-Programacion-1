#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Paquete {
	int id;
	string direccion;
	string Cedulacliente;

public:
	Paquete(int i, string direc, string ced);
	string toString();
};

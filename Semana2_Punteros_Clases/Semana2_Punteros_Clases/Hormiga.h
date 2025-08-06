#pragma once
#include <iostream>
#include <sstream>
using namespace std;
static int idCont = 0;

class Hormiga {
private:
	int id;
	string nombre;

public:
	Hormiga(string nombre) :nombre(nombre), id(++idCont) {
		cout << "Hormiga: " << endl;
		cout << this->toString();
		cout << "Ha sido creada :)" << endl << endl;
	}

	Hormiga() {

	}

	virtual ~Hormiga() {
		cout << "Hormiga: " << endl;
		cout << this->toString();
		cout << "Ha muerto :(" << endl << endl;
	}

	string toString() {
		stringstream s;
		s << "ID: " << id << endl;
		s << "nombre: " << nombre << endl;

		return s.str();
	}
};

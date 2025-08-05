#include <iostream>
#include <sstream>

using namespace std;
int idCont = 0;


// demostracion de memoria dinamica y memoria automatica


class Hormiga {
	private:
		int id;
		string nombre;

	public:
		Hormiga(string nombre):nombre(nombre), id(idCont + 1) {
			cout << "Hormiga: " << endl;
			cout << this->toString();
			cout << "Ha sido creada :)" << endl << endl;
		}

		virtual ~Hormiga() {
			cout << "Hormiga: " << endl;
			cout << this->toString();
			cout << "Ha muerto :(" << endl << endl ;
		}

		string toString() {
			stringstream s;
			s << "ID: " << id << endl;
			s << "nombre: " << nombre << endl;

			return s.str();
		}
};


// funcion para simular que nos traemos una hormiga de un lugar
// creamos una hormiga dentro de la funcion
// sin embargo la hormiga solo puede vivir dentro de la funcion
// porque es un objeto automatico (vive en el stack es decir dentro de la funcion)
Hormiga* narnia() {
	Hormiga hormigaDeNarnia = Hormiga("Tummus");

	cout << "saliendo de narnia" << endl;
	return &hormigaDeNarnia;
}


// funcion para simular que nos traemos una hormiga de un lugar
// creamos una hormiga en la memoria dinamica (heap)
// La hormiga no vive dentro de la funcion, vive en otro lado
// Esta es una hormiga dinamica, si salimos de la funcion la hormiga seguira viviendo.
Hormiga* hogwarts() {
	Hormiga* hormigaDeHogwarts = new Hormiga("HP");

	cout << "saliendo de hogwarts" << endl;
	return hormigaDeHogwarts;
}


int main() {
	cout << "yendo a narnia por una hormiga" << endl << endl;
	Hormiga* hormigaDeNarnia = narnia();

	// que pasara si intento invocar el toString de la hormiga de narnia?
	// probablemente funcione

	cout << endl << "-------------------------------------------------" << endl;
	cout << "hormiga de narnia desde el main" << endl;
	cout << hormigaDeNarnia->toString();
	return 0;
}
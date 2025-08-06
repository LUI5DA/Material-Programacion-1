#include "Hormiguero.h"

using namespace std; //para no tener que hacer std:: a todo a lo que pertenece a std


// demostracion de memoria dinamica y memoria automatica




// funcion para simular que nos traemos una hormiga de un lugar
// creamos una hormiga dentro de la funcion
// sin embargo la hormiga solo puede vivir dentro de la funcion
// porque es un objeto automatico (vive en el stack es decir dentro de la funcion)
Hormiga* narnia() {
	Hormiga* hormigaDeNarnia = new Hormiga("Tummus");

	cout << "saliendo de narnia" << endl;
	return hormigaDeNarnia;
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
	// probablemente funcione, pero no como se espera

	cout << endl << "-------------------------------------------------" << endl;
	cout << "hormiga de narnia desde el main" << endl;
	cout << hormigaDeNarnia->toString();

	//-----------------------------------------------------------------------
	cout << endl << endl << endl;
	cout << endl << "-------------------------------------------------" << endl;
	cout << endl << "-------------------------------------------------" << endl;

	cout << "yendo a hogwarts por una hormiga" << endl << endl;
	Hormiga* hormigaDeHogwarts = hogwarts();

	// que pasara si intento invocar el toString de la hormiga de hogwarts?
	// es 100% seguro que funcione

	cout << endl << "-------------------------------------------------" << endl;
	cout << "hormiga de hogwarts desde el main" << endl;
	cout << hormigaDeHogwarts->toString();
	

	// ----------------------------------------------------------------
	// ejercicios

	// #1 cual es la direccion de memoria de cada una de las hormigas
	cout << "Hormiga narnia: " << hormigaDeNarnia<<endl;
	cout << "Hormiga hogwarts: " << hormigaDeHogwarts<<endl;


	// #2 cual es la direccion de memoria de los punteros a las hormigas
	cout << "Puntero a hormiga narnia: " << &hormigaDeNarnia << endl;
	cout << "Puntero a hormiga hogwarts: " << &hormigaDeHogwarts << endl;

	// #3 como podemos hacer que la hormiga de narnia tambien pueda "viajar" al main
	
	//poniendole new a la funcion narnia


	cout << "ejemplo vectores" << endl;
	Hormiga* v[5];
	Hormiga** ptr = v;

	cout << (*ptr + 1)->toString() << endl;
	cout << v[1]->toString() << endl;

	//delete hormigaDeHogwarts;
	//delete hormigaDeNarnia;
	return 0;
}
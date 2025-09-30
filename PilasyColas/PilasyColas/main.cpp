#include "Pila.h"
#include "Cola.h"

using namespace std;

// implementar una funcion que utilice una pila para saber si la cantidad de parentesis de una expresion esta balanceada...
// ejemplo
// 2*(1+(x-2)/5) -> true, para cada "(" hay un ")" 
// 2*(1+(x-2/5) -> false, sobra un (
bool isBalanced(string s) {
	// funcion a implementar
	return false;
}


int main() {
	int puntos = 0;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Probando ejercicio 1" << endl;
	string s1 = "2*(1+(x-2)/5)";
	string s2 = "2*(1+(x-2/5)";
	bool esperado = true;

	cout << "Probando la expresion: " << s1 <<  " Esperado: true" << endl;

	if (isBalanced(s1)) {
		cout << "La expresion es correcta" << endl;
		cout << "pasa la prueba 1" << endl;
		puntos++;
	}
	else {
		cout << "La expresion es incorrecta" << endl;
		cout << "No pasa la prueba 1" << endl;
	}

	cout << endl << endl << "Probando la expresion: " << s2 << " Esperado: false" << endl;
	if (isBalanced(s2)) {
		cout << "La expresion es correcta" << endl;
		cout << "No pasa la prueba 2" << endl;
	}
	else {
		cout << "La expresion es incorrecta" << endl;
		cout << "pasa la prueba 2" << endl;
		puntos++;
	}

	cout <<endl<<endl<<endl<< "-------------------------------------------------------------------------------" << endl;
	cout << "Probando ejercicio 2" << endl;
	Paquete* p1 = new Paquete(1, "Heredia", "123");
	Paquete* p2 = new Paquete(2, "Alajuela", "321");
	Paquete* p3 = new Paquete(3, "San Jose", "567");
	Paquete* p4 = new Paquete(4, "Cartago", "987");
	Paquete* p5 = new Paquete(5, "Puntarenas", "345");

	Cola* cola = new Cola();
	cola->enqueue(p1);
	cola->enqueue(p2);
	cola->enqueue(p3);
	cola->enqueue(p4);
	cola->enqueue(p5);

	Paquete* pprueba1 = cola->head();
	Paquete* pprueba2 = cola->head();
	if (pprueba1 == pprueba2 && pprueba1->getId() == 1) {
		cout << "Metodo head correcto... Pasa la prueba 3" << endl;
		puntos++;
	} else {
		cout << "Metodo head incorrecto... No pasa la prueba 3" << endl;
	}

	pprueba1 = cola->dequeue();
	if (pprueba1->getId() == 2) {
		cout << "Metodo dequeue correcto... Pasa la prueba 4" << endl;
		puntos++;
	}
	else {
		cout << "Metodo head incorrecto... No pasa la prueba 3" << endl;
	}
	

	return 0;
}
#pragma once
#include "Paquete.h"

// ==============================================================================================
// ==============================================================================================
// Nodo para guardar un paquete 
class Nodo1
{
	Paquete* value;
	Nodo1* siguiente;
public:
	Nodo1(Paquete* val, Nodo1* sig);
	~Nodo1();

	Paquete* getValor();
	void setValor(Paquete* val);

	Nodo1* getSiguiente();
	void setSiguiente(Nodo1* sig);
};






// ==============================================================================================
// ==============================================================================================
// Nodo para almacenar un char

class Nodo2
{
	char value;
	Nodo2* siguiente;
public:
	Nodo2(char val, Nodo2* sig);
	~Nodo2();

	char getValor();
	void setValor(char val);

	Nodo2* getSiguiente();
	void setSiguiente(Nodo2* sig);
};




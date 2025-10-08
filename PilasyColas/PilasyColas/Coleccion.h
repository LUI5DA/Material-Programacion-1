#pragma once
#include <iostream>
#include "Base.h"
using namespace std;
// clase para almacenar objetos de tipo base
class Coleccion
{
	// --------------------------------------------------------------
	// Metodos de la interfaz
	// MVP 
public:
	virtual ~Coleccion() {}
	virtual void agregar(Base*) = 0;
	virtual void eliminar(Base* filter) = 0;
	virtual Base* buscar(Base* filter) = 0;
	virtual string toString() = 0;
};




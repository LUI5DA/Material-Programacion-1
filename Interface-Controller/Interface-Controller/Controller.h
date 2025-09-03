#pragma once
#include "Interfaz.h"
#include "ContenedorMascotas.h"

class Controller
{
private:
	ContenedorMascotas* mascotas;
public:
	Controller();
	virtual ~Controller();

	void menuPrincipal();
	void opcion1();
	void opcion2();
	void opcion3();
	void opcion4();
	void opcion5();
	void opcion6();
};


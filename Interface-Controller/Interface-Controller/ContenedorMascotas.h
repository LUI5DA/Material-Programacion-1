#pragma once
#include "Mascota.h"
class ContenedorMascotas
{
private:
	int can;
	int tam;
	Mascota** vec;

public:
	ContenedorMascotas();
	~ContenedorMascotas();

	bool agregarMascota(Mascota* m);
	bool eliminar(string id);
	int getPos(string id);
	Mascota* buscar(string id);
	void ordenar();
	void mySawap(int i, int j);

	string toString();
};


#pragma once

#include "Seccion.h"

class Supermercado
{
	private:
		string nombre;
		Seccion** secciones;
		int capacidad;
		int cantidad;

	public:
		Supermercado(string nombre, int capacidad);
		~Supermercado();

		string getNombre();
		int getCapacidad();
		int getCantidad();

		bool agregarSeccion(string, int);
		bool agregarProducto(string, Producto*);

		bool eliminarSeccion(string);
		string mostrarSecciones();
		string mostrarSupermercado();
};


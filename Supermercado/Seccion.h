#pragma once

#include "Producto.h"

class Seccion
{
	private:
		string nombre;
		Producto** productos;
		int capacidad;
		int cantidad;

	public:
		Seccion(string nombre, int capacidad);
		~Seccion();

		string getNombre();
		int getCapacidad();
		int getCantidad();

		bool agregarProducto(Producto* producto);
		bool eliminarProducto(int id);
		string mostrarProductos();
		string mostrarSeccion();
};


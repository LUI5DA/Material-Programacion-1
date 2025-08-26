#pragma once

#include "IVA.h"
#include "Fecha.h"

class Producto
{
	private:
		int codigo;
		string nombre;
		float precio;
		int cantidad;
		IVA* iva;
		Fecha* fechaVencimiento;

	public:
		Producto();
		Producto(int, string, float, int, IVA*, int, int, int);
		Producto(Producto*);
		~Producto();

		int getCodigo();
		string getNombre();
		float getPrecio();
		int getCantidad();
		string getFechaVencimiento();

		void setNombre(string);
		void setPrecio(float);

		float calcularPrecioConIva();

		string mostrarProducto();
};


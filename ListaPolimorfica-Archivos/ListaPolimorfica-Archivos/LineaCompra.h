#pragma once
#include "ListaProducto.h"
class LineaCompra
{
	private:
	int id;
	Producto* producto;
	int cantidad;
	double descuento; // porcentaje de descuento (0 a 100)

	public:
		LineaCompra(Producto*, int, double);
		virtual ~LineaCompra();
		Producto* getProducto();
		int getCantidad();
		int getId();
		void setId(int);
		double getDescuento();
		void setCantidad(int);
		void setDescuento(double);
		double calcularSubtotal();
		string toString();

		virtual void write(ofstream& descriptor);
		static LineaCompra* read(ifstream& descriptor, ListaProducto*);
};


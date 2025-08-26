#include "Supermercado.h"

int main() {
	IVA* iva = new IVA(13);

	Supermercado* supermercado = new Supermercado("Maxipali Lagunilla", 10);
	Supermercado* supermercado2 = new Supermercado("Maxipali San Pedro", 10);

	supermercado->agregarSeccion("Bebidas", 10);
	supermercado2->agregarSeccion("Bebidas", 10);
	Producto* p1 = new Producto(1, "Coca-Cola", 1400, 20, iva, 31, 10, 2024);
	Producto* p2 = new Producto(2, "Pepsi", 1300, 20, iva, 31, 11, 2024);
	Producto* p3 = new Producto(3, "Fanta", 1200, 20, iva, 15, 10, 2024);
	Producto* p4 = new Producto(4, "Sprite", 1100, 20, iva, 15, 11, 2024);

	supermercado->agregarProducto("Bebidas", p1);
	supermercado->agregarProducto("Bebidas", p2);
	supermercado->agregarProducto("Bebidas", p3);
	supermercado->agregarProducto("Bebidas", p4);

	supermercado2->agregarProducto("Bebidas", p1);
	supermercado2->agregarProducto("Bebidas", p2);
	supermercado2->agregarProducto("Bebidas", p3);
	supermercado2->agregarProducto("Bebidas", p4);

	supermercado->agregarSeccion("Botanas", 10);
	Producto* p5 = new Producto(5, "Doritos", 1500, 10, iva, 31, 10, 2024);
	Producto* p6 = new Producto(6, "Cheetos", 1600, 10, iva, 31, 11, 2024);
	Producto* p7 = new Producto(7, "Ruffles", 1700, 10, iva, 15, 10, 2024);
	Producto* p8 = new Producto(8, "Sabritas", 1800, 10, iva, 15, 11, 2024);
	Producto* p9 = new Producto(9, "Tostitos", 1900, 10, iva, 15, 11, 2024);

	supermercado->agregarProducto("Botanas", p5);
	supermercado->agregarProducto("Botanas", p6);
	supermercado->agregarProducto("Botanas", p7);
	supermercado->agregarProducto("Botanas", p8);
	supermercado->agregarProducto("Botanas", p9);

	supermercado->agregarSeccion("Carnes", 10);
	Producto* p10 = new Producto(10, "Res", 2000, 10, iva, 31, 10, 2024);
	Producto* p11 = new Producto(11, "Pollo", 2100, 10, iva, 31, 11, 2024);
	Producto* p12 = new Producto(12, "Pescado", 2200, 10, iva, 15, 10, 2024);
	Producto* p13 = new Producto(13, "Cerdo", 2300, 10, iva, 15, 11, 2024);

	supermercado->agregarProducto("Carnes", p10);
	supermercado->agregarProducto("Carnes", p11);
	supermercado->agregarProducto("Carnes", p12);
	supermercado->agregarProducto("Carnes", p13);

	cout << supermercado->mostrarSupermercado() << endl;

	delete supermercado;

	cout << supermercado2->mostrarSupermercado() << endl;

	delete supermercado2;

	delete iva;
	delete p2;
	delete p3;
	delete p4;
	delete p5;
	delete p6;
	delete p7;
	delete p8;
	delete p9;
	delete p10;
	delete p11;
	delete p12;
	delete p13;

	return 0;
}
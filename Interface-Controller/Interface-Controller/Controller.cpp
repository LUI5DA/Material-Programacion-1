#include "Controller.h"

Controller::Controller()
{
	mascotas = new ContenedorMascotas();
}

Controller::~Controller()
{
	delete mascotas;
}

void Controller::menuPrincipal()
{
	int opcion;
	do {
		system("cls");
		opcion = Interfaz::menuPrincipal();
		switch (opcion) {
			case 1: {opcion1(); }break;

			case 2: {opcion2(); }break;

			case 3: {opcion3(); }break;

			case 4: {opcion4(); }break;

			case 5: {opcion5(); }break;

			case 6: {opcion6(); }break;
		default:{}
		}
		system("pause");
	} while (opcion != 6);
}

void Controller::opcion1()
{
	Mascota* m = Interfaz::crearMascota();
	if (mascotas->agregarMascota(m)) {
		Interfaz::imprimirMensaje("Mascota agregada con exito");
	}
	else {
		Interfaz::imprimirMensaje("Mascota no se pudo agregar");
		delete m;
	}
}

void Controller::opcion2()
{
	Interfaz::imprimirMensaje(mascotas->toString());
	
	// esto deberia hacerse en la interfaz
	string id;
	cout << "ingrese el id de la mascota que quiere eliminar" << endl;
	cin >> id;
	if (mascotas->eliminar(id)) {
		Interfaz::imprimirMensaje("Mascota eliminada con exito");
	}
	else {
		Interfaz::imprimirMensaje("No se pudo eliminar la mascota");
	}
}

void Controller::opcion3()
{
	// esto deberia hacerse en la interfaz
	string id;
	cout << "ingrese el id de la mascota que quiere buscar" << endl;
	cin >> id;
	Mascota* m = mascotas->buscar(id);
	if (m) {
		Interfaz::imprimirMensaje("Mascota encontrada con exito");
		Interfaz::imprimirMensaje(m->toString());
	}
	else {
		Interfaz::imprimirMensaje("No se pudo encontrar la mascota");
	}
}

void Controller::opcion4()
{
	Interfaz::imprimirMensaje(mascotas->toString());
}

void Controller::opcion5()
{
	mascotas->ordenar();
}

void Controller::opcion6()
{
	Interfaz::imprimirMensaje("Saliendo del programa");
}

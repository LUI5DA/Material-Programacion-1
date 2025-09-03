#pragma once
#include "Mascota.h"

class Interfaz
{
public:
	// todos los metodos son static

	// menus
	static int menuPrincipal();
	static int ingresarInt(int min, int max);
	static int ingresarIntPositivo();


	// metodos para crear objetos
	static Mascota* crearMascota();


	// metodos para imprimir mensajes
	static void imprimirMensaje(string m);
};


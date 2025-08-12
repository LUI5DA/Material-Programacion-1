#pragma once
#include "Libro.h"


// 2 maneras de declarar y definir constantes
#define TAMANO 100
const int tamanio = 100;


// =========================================================================
// En este encabezado se muestran las 4 maneras de hacer colecciones
// =========================================================================



// =========================================================================
// #1 Vector automatico de objetos

class ContenedorLibros1
{
	private:
		Libro vec[TAMANO];
		int can;
		int tam;

	public:
		ContenedorLibros1();

		~ContenedorLibros1();

		bool insert(Libro&);

		int search(int);

		Libro getAt(int);

		bool deleteL(int);

		string toString();
};



// =========================================================================
// #2 Vector automatico de punteros




// =========================================================================
// #3 Vector dinamico de objetos




// =========================================================================
// #4 Vector dinamico de punteros



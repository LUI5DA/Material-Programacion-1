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

class ContenedorLibros2 {
private:
	Libro* vec[TAMANO];
	int can;
	int tam;

public:
	ContenedorLibros2();

	~ContenedorLibros2();

	bool insert(Libro&);

	int search(int);

	Libro* getAt(int);

	bool deleteL(int);

	string toString();
};


// =========================================================================
// #3 Vector dinamico de objetos
class ContenedorLibros3 {
private:
	Libro* vec;
	int can;
	int tam;

public:
	ContenedorLibros3();

	~ContenedorLibros3();

	bool insert(Libro&);

	int search(int);

	Libro* getAt(int);

	bool deleteL(int);

	string toString();
};




// =========================================================================
// #4 Vector dinamico de punteros

class ContenedorLibros4 {
private:
	Libro** vec;
	int can;
	int tam;

public:
	ContenedorLibros4();

	~ContenedorLibros4();

	bool insert(Libro&);

	int search(int);

	Libro* getAt(int);

	bool deleteL(int);

	string toString();
};


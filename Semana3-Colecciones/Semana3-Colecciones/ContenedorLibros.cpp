#include "ContenedorLibros.h"

ContenedorLibros1::ContenedorLibros1()
{
	this->can = 0;
	this->tam = TAMANO;
}

ContenedorLibros1::~ContenedorLibros1()
{
	// no hay que liberar memoria
}

bool ContenedorLibros1::insert(Libro& l)
{
	// comprobar si queda espacio
	if (can < tam) {
		this->vec[can++] = l;
		return true;
	}

	// ya no queda espacio, no se pueden insertar mas libros
	return false;
}

int ContenedorLibros1::search(int isbn)
{
	for (int i = 0; i < can; i++) {
		if (vec[i].getISBN() == isbn) {
			return i;
		}
	}

	return -1;
}

Libro ContenedorLibros1::getAt(int i)
{
	if (i >= 0 && i < can) {
		return vec[i];
	}
	return Libro();
}

bool ContenedorLibros1::deleteL(int isbn)
{
	int index = search(isbn);

	if (index ==  -1) {
		return false;
	}

	for (int i = index; i < can; i++) {
		vec[i] = vec[i + 1];
	}

	--can;

	return true;
}

string ContenedorLibros1::toString()
{
	stringstream s;

	for (int i = 0; i < can; i++) {
		s << vec[i].toString() << endl;
	}

	s << endl;

	return s.str();
}

ContenedorLibros2::ContenedorLibros2()
{
	can = 0;
	tam = TAMANO;

	for (int i = 0; i < tam; i++) {
		vec[i] = nullptr;
	}
}

ContenedorLibros2::~ContenedorLibros2()
{
	for (int i = 0; i < can; i++) {
		delete vec[i];
	}
}

bool ContenedorLibros2::insert(Libro& l)
{
	// comprobar si queda espacio
	if (can < tam) {
		this->vec[can++] = &l;
		return true;
	}

	// ya no queda espacio, no se pueden insertar mas libros
	return false;
}

int ContenedorLibros2::search(int isbn)
{
	for (int i = 0; i < can; i++) {
		if (vec[i]->getISBN() == isbn) {
			return i;
		}
	}

	return -1;
}

Libro* ContenedorLibros2::getAt(int i)
{
	if (i >= 0 && i < can) {
		return vec[i];
	}

	return nullptr;
}

bool ContenedorLibros2::deleteL(int isbn)
{
	int index = search(isbn);

	if (index == -1) {
		return false;
	}

	delete vec[index];

	for (int i = index; i < can; i++) {
		vec[i] = vec[i + 1];
	}

	vec[can - 1] = nullptr;

	--can;

	return true;
}

string ContenedorLibros2::toString()
{
	stringstream s;

	for (int i = 0; i < can; i++) {
		s << vec[i]->toString() << endl;
	}

	s << endl;

	return s.str();
}

ContenedorLibros3::ContenedorLibros3()
{
	can = 0;
	tam = TAMANO;

	vec = new Libro[tam];
}

ContenedorLibros3::~ContenedorLibros3()
{
	delete[] vec;
}

bool ContenedorLibros3::insert(Libro&)
{
	return false;
}

int ContenedorLibros3::search(int)
{
	return 0;
}

Libro* ContenedorLibros3::getAt(int)
{
	return nullptr;
}

bool ContenedorLibros3::deleteL(int)
{
	return false;
}

string ContenedorLibros3::toString()
{
	return string();
}

ContenedorLibros4::ContenedorLibros4()
{
	can = 0;
	tam = TAMANO;

	vec = new Libro * [tam];
	for (int i = 0; i < tam; i++) {
		vec[i] = nullptr;
	}
}

ContenedorLibros4::~ContenedorLibros4()
{
	for (int i = 0; i < can; i++) {
		delete vec[i];
	}
	delete[]vec;
}

bool ContenedorLibros4::insert(Libro&)
{
	return false;
}

int ContenedorLibros4::search(int)
{
	return 0;
}

Libro* ContenedorLibros4::getAt(int)
{
	return nullptr;
}

bool ContenedorLibros4::deleteL(int)
{
	return false;
}

string ContenedorLibros4::toString()
{
	return string();
}

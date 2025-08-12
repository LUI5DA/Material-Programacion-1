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

#include "ListaProducto.h"

ListaProducto::ListaProducto()
{
	first = nullptr;
}

ListaProducto::~ListaProducto()
{
	while (first) {
		NodoProducto* el = first;
		first = first->siguiente;
		delete el->p;
		delete el;
	}
}

void ListaProducto::add(Producto* pr)
{
	first = new NodoProducto(pr, first);
}

Producto* ListaProducto::search(int id)
{
	NodoProducto* aux = first;
	while (aux) {
		if (aux->p->getId() == id) {
			return aux->p;
		}
		aux = aux->siguiente;
	}
	return nullptr;
}

void ListaProducto::remove(int id)
{
	NodoProducto* aux = first;
	if (aux->p->getId() == id) {
		NodoProducto* del = aux->siguiente;
		aux->siguiente = del->siguiente;
		delete del->p;
		delete del;
		return;
	}
	
	while (aux->siguiente) {
		if (aux->p->getId() == id) {
			NodoProducto* del = aux->siguiente;
			aux->siguiente = del->siguiente;
			delete del->p;
			delete del;
			return;
		}
		aux = aux->siguiente;
	}
}

string ListaProducto::toString() {
	stringstream s;

	NodoProducto* aux = first;
	while (aux) {
		s << aux->p->toString() << endl;
		aux = aux->siguiente;
	}
	return s.str();

}

string ListaProducto::mostrarProductosVencidos(Fecha* f) {
	NodoProducto* n = first;
	stringstream s;
	while (n) {
		if (n->p->estaVencido(f)) {
			s << n->p->toString() << endl;
		}
	}
	return s.str();
}

NodoProducto::NodoProducto(Producto* pr, NodoProducto* sig)
{
	p = pr;
	siguiente = sig;
}


void ListaProducto::write(ofstream& f) {
	NodoProducto* aux = first;
	while (aux) {
		aux->p->write(f); // llamo este metodo sin saber que implementacion especifica de producto hay dentro del puntero
		aux = aux->siguiente;
	}
}
#include "ListaCompras.h"

ListaCompras::ListaCompras()
{
	first = nullptr;
}

ListaCompras::~ListaCompras()
{
	while (first) {
		NodoCompra* el = first;
		first = first->siguiente;
		delete el->p;
		delete el;
	}
}

void ListaCompras::add(Compra* pr)
{
	first = new NodoCompra(pr, first);
}

Compra* ListaCompras::search(int id)
{
	NodoCompra* aux = first;
	while (aux) {
		if (aux->p->getId() == id) {
			return aux->p;
		}
		aux = aux->siguiente;
	}
	return nullptr;
}

void ListaCompras::remove(int id)
{
	NodoCompra* aux = first;
	if (aux->p->getId() == id) {
		NodoCompra* del = aux->siguiente;
		aux->siguiente = del->siguiente;
		delete del->p;
		delete del;
		return;
	}

	while (aux->siguiente) {
		if (aux->p->getId() == id) {
			NodoCompra* del = aux->siguiente;
			aux->siguiente = del->siguiente;
			delete del->p;
			delete del;
			return;
		}
		aux = aux->siguiente;
	}
}

string ListaCompras::toString() {
	stringstream s;

	NodoCompra* aux = first;
	while (aux) {
		s << aux->p->toString() << endl;
		aux = aux->siguiente;
	}
	return s.str();

}

NodoCompra::NodoCompra(Compra* pr, NodoCompra* sig)
{
	p = pr;
	siguiente = sig;
}


void ListaCompras::write(ofstream& f) {
	NodoCompra* aux = first;
	while (aux) {
		aux->p->write(f);
		aux = aux->siguiente;
	}
}
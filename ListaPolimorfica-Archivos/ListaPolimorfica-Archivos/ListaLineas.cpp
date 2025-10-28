#include "ListaLineas.h"

ListaLineas::ListaLineas()
{
	first = nullptr;
}

ListaLineas::~ListaLineas()
{
	while (first) {
		NodoLinea* el = first;
		first = first->siguiente;
		delete el->p;
		delete el;
	}
}

void ListaLineas::add(LineaCompra* pr)
{
	first = new NodoLinea(pr, first);
}


LineaCompra* ListaLineas::search(int id)
{
	NodoLinea* aux = first;
	while (aux) {
		if (aux->p->getId() == id) {
			return aux->p;
		}
		aux = aux->siguiente;
	}
	return nullptr;
}

void ListaLineas::remove(int id)
{
	NodoLinea* aux = first;
	if (aux->p->getId() == id) {
		NodoLinea* del = aux->siguiente;
		aux->siguiente = del->siguiente;
		delete del->p;
		delete del;
		return;
	}
	while (aux->siguiente) {
		if (aux->p->getId() == id) {
			NodoLinea* del = aux->siguiente;
			aux->siguiente = del->siguiente;
			delete del->p;
			delete del;
			return;
		}
		aux = aux->siguiente;
	}
}

string ListaLineas::toString() {
	stringstream s;
	NodoLinea* aux = first;
	while (aux) {
		s << aux->p->toString() << endl;
		aux =  aux->siguiente;
	}
	return s.str();
}

void ListaLineas::write(ofstream& f)
{
	NodoLinea* aux = first;
	while (aux) {
		aux->p->write(f);
		aux = aux->siguiente;
	}
}

NodoLinea::NodoLinea(LineaCompra* pr, NodoLinea* sig)
{
	p = pr;
	siguiente = sig;
}


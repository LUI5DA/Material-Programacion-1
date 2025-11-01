#include "ListaCliente.h"

ListaCliente::ListaCliente()
{
	first = nullptr;
}

ListaCliente::~ListaCliente()
{
	while (first) {
		NodoCliente* el = first;
		first = first->siguiente;
		delete el->p;
		delete el;
	}
}

void ListaCliente::add(Cliente* pr)
{
	first = new NodoCliente (pr, first);
}

Cliente* ListaCliente::search(int id)
{
	NodoCliente* aux = first;
	while (aux) {
		if (aux->p->getId() == id) {
			return aux->p;
		}
		aux = aux->siguiente;
	}
	return nullptr;
}

void ListaCliente::remove(int id)
{
	NodoCliente* aux = first;
	if (aux->p->getId() == id) {
		NodoCliente* del = aux->siguiente;
		aux->siguiente = del->siguiente;
		delete del->p;
		delete del;
		return;
	}

	while (aux->siguiente) {
		if (aux->p->getId() == id) {
			NodoCliente* del = aux->siguiente;
			aux->siguiente = del->siguiente;
			delete del->p;
			delete del;
			return;
		}
		aux = aux->siguiente;
	}
}

string ListaCliente::toString() {
	stringstream s;

	NodoCliente* aux = first;
	while (aux) {
		s << aux->p->toString() << endl;
		aux = aux->siguiente;
	}
	return s.str();

}

NodoCliente::NodoCliente(Cliente* pr, NodoCliente* sig)
{
	p = pr;
	siguiente = sig;
}


void ListaCliente::write(ofstream& f) {
	NodoCliente* aux = first;
	while (aux) {
		aux->p->write(f); // en las listas polimorficas solo podemos llamar a los metodos que son comunes a todos los objetos
		// es decir los que estan en la clase base
		aux = aux->siguiente;
	}
}
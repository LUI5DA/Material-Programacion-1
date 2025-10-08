#include "Cola.h"

Cola::Cola()
{
	first = nullptr;
	last = nullptr;
}

Cola::~Cola()
{
	while (!isEmpty()) {
		Paquete* el = dequeue();
		delete el;
	}
}

void Cola::enqueue(Paquete* p)
{
	if (!last) {
		last = new Nodo1(p, nullptr);
		first = last;
		return;
	}
	last->setSiguiente(new Nodo1(p, nullptr));
	last = last->getSiguiente();
}

Paquete* Cola::dequeue()
{
	if (isEmpty()) return nullptr;
	Nodo1* temp = first;
	first = first->getSiguiente();
	Paquete* val = temp->getValor();
	delete temp;
	return val;
}

Paquete* Cola::head()
{
	if (isEmpty()) return nullptr;
	return first->getValor();
}

bool Cola::isEmpty()
{
	return !first;
}

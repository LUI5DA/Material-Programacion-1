#include "Pila.h"


Pila::Pila()
{
	head = nullptr;
}

void Pila::push(char c)
{
	head = new Nodo2(c, head);
}

char Pila::pop()
{
	if (!head) {
		return ' ';
	}
	Nodo2* temp = head;
	head = head->getSiguiente();
	char val = temp->getValor();
	delete temp;
	return val;
}

char Pila::top()
{
	if (!head) {
		return ' ';
	}
	return head->getValor();
}

bool Pila::isEmpty()
{
	return !head;
}

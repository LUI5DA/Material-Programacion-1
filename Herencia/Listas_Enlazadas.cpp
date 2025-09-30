#include <iostream>
#include <sstream>
using namespace std;

class Persona{
	string nombre;
	string cedula;
	int edad;
public:
	Persona(){
		
	}
	
	Persona(string nom, string ced, int ed){
		nombre = nom;
		cedula = ced;
		edad = ed;
	}
		
	virtual ~Persona(){}
	
	string getNombre(){
		return nombre;
	}
		
	string getCedula(){
		return cedula;
	}
		
	int getEdad(){
		return edad;
	}
		
	void setNombre(string n){
		nombre = n;
	}
		
	void setEdad(int ed){
		edad = ed;
	}

	void setCedula(string c){
		cedula = c;
	}
		
	string toString(){
		stringstream s;
		s<< "Nombre: " << nombre<< endl;
		s<< "Cedula: " << cedula << endl;
		s << "Edad: " << edad <<  endl;
		
		return s.str();
	}
}

class Nodo{
	Persona* persona;
	Nodo* siguiente;
	
public:
	Nodo(Persona* p, Nodo* s){
		persona = p;
		siguiente = s;
	}
	
	~Nodo(){}
	
	Persona* getPersona(){return persona;}
	
	Nodo* getSiguiente(){return siguiente;}
	
	void setPersona(Persona* p){persona = p;}
	
	void setSiguiente(Nodo* s){siguiente = s;}
}


//first 
//|
//v
//5 -> 7 -> 8 -> 10 -> 14



//		aux
//		|
//		v
//p3->p2->p1->p4->null


class Lista{
	Nodo* first; // puntero al primer elemento
	
public:
	Lista(){
		first = nullptr;
	}
	
	~Lista(){
		// aqui es el unico lugar en donde usamos el first para recorrer la lista
		while(first != nullptr){
			Nodo* eliminar = first;
			first = first->getSiguiente();
			delete eliminar->getPersona();
			delete eliminar;
		}
	}
	
	// agregar al inicio
	void agregarAlInicio(Persona* p){
		first = new Nodo(p, first);
	}
		
	// agregar al final 
	void agregarAlFinal(Persona* p){
		if(first == null){
			first = new Nodo(p, first);
			return;
		}
		
		Nodo* aux = first; // aux es un puntero apuntando al primer nodo de la Lista
		
		// este ciclo lo que hace es dejar el nodo aux apuntando al ultimo nodo de la lista
		while(aux->getSiguiente() != nullptr){
			aux = aux->getSiguiente();
		}
		
		Nodo* nuevo = new Nodo(p, nullptr);
		aux->setSiguiente(nuevo);
	}
		
	// buscar una persona por cedula
	Persona* buscar(string cedula){
		Nodo* aux = first;
		while(aux){
			if(aux->getPersona()->getCedula() == cedula){
				return aux->getPersona();
			}
			aux = aux->getSiguiente();
		}
		return nullptr;
	}
		
	// eliminar un elemento de la Lista
	bool eliminar(string cedula){
		if(first){
			if(first->getPersona()->getCedula() == cedula){
				Nodo* elimninar = first;
				first = first->getSiguiente();
				delete eliminar->getPersona();
				delete eliminar;
				return true;
			}
		}
		
		Nodo* aux = first;
		while(aux->getSiguiente()){
			if(aux->getSiguiente()->getPersona()->getCedula() == cedula){
				Nodo* eliminar = aux->getSiguiente(); // este es el que vamos a eliminar
				aux->setSiguiente(eliminar->getSiguiente()); // aqui cortamos la lista
				delete eliminar->getPersona();
				delete eliminar;
				return true;
			}
			aux = aux->getSiguiente();
		}
		return false;
	}
		
	void intercambiar(Nodo* n1, Nodo* n2){
		Nodo* n3 = n1->getSiguiente();
		n1->setSiguiente(n2->getSiguiente());
		n1 = n1->getSiguiente();
		n2->setSiguiente(n3);
		n2 = n3->getSiguiente();
		n3->setSiguiente(n1->getSiguiente());
		n1->setSiguiente(n2);
	}
		
	// toString de una Lista
	string toString(){
		stringstream s;
		Nodo* aux = first;
		
		while(aux){
			s << aux->getPersona()->toString() << endl;
			aux = aux->getSiguiente(); // este es el equivalente al i++ en un for, no pude faltar
		}
		return s.str();
	}
};

p0->p1->p2->p3->p4

int main(int argc, char *argv[]) {
	
	return 0;
}


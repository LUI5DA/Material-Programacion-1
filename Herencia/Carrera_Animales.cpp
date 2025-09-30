#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;



// cuando una clase tiene almenos un MVP es una clase abstracta, es decir que yo no puedo crear objetos de esa clase
// Cuando todos los metodos de una clase son MVP se llama una Interfaz
// en java si tenemos interfaces  -> Interface


class Animal{
protected:
	string nombre;
	string evento;
	int posicion;
	
public:
	Animal(){
		
	}
	
	Animal(string n){
		nombre = n;
		posicion = 0;
		evento = "";
	}
	
	// recuerden siempre ponerle virtual al destructor...
	virtual ~Animal(){
		cout << "Eliminando animal..." << nombre << endl; 
	}
		
	virtual void correr() = 0; // Metodo Virtual Puro MVP
	
	virtual string toString(){ // metodo virtual
		stringstream s;
		
		s << "Nombre: "<< nombre<< " | Posicion: " << posicion << " | Evento de esta ronda: " << evento << endl;
		
		return s.str();
	}
	int getPosicion(){
		return posicion;
	}
};


class Perro : public Animal {
private:
	string raza;
public:
	// esta es una manera de hacer el constructor
	Perro(string n, string r): Animal(n){
		raza = r;
	}
	
	virtual ~Perro(){
		cout << "Destruyendo un perro" << endl;
	}
		
	virtual void correr(){
		int prob = rand()% 100;
		
		if(prob < 30){
			posicion += 10;
			evento = "El perro hizo un sprint +10";
		} else if (prob <= 50){
			posicion += 5;
			evento = "El perro se distrajo +5";
		} else {
			posicion += 7;
			evento = "El perro corre normal +7";
		}
	}
		
	virtual string toString(){
		stringstream s;
		s << "Soy un Perro de raza: "<< raza<<" | ";
		s << Animal::toString();
 		return s.str();
	}
};






class Liebre : public Animal {
public:
	// esta es una manera de hacer el constructor
	Liebre(string n): Animal(n){
	}
	
	virtual ~Liebre(){
		cout << "Destruyendo una liebre" << endl;
	}
		
	virtual void correr(){
		int prob = rand()% 100;
		if(prob <= 30){
			evento = "La liebre se durmio +0";
		} else{
			posicion += 15;
			evento = "La liebre corre normal +15";
		}
	}
			
	virtual string toString(){
		stringstream s;
		s << "Soy una Liebre | ";
		s << Animal::toString();
		return s.str();
		
	}
};




class Tortuga : public Animal {
public:
	// esta es una manera de hacer el constructor
	Tortuga(string n) : Animal(n) {
		
	}
	
	virtual ~Tortuga(){
		cout << "Destruyendo una tortuga" << endl;
	}
		
	virtual void correr(){
		posicion += 5;
		evento = "La Tortuga corre a un ritmo constante +5";
	}
	
	virtual string toString(){
		stringstream s;
		s << "Soy una Tortuga | ";
		s << Animal::toString();
		return s.str();
		
	}
};


class Juego{
	Animal** participantes;
	int can;
	int tam;
	int distancia;
	
public:
	Juego(int d){
		participantes = new Animal*[10];
		can = 0;
		tam = 10;
		distancia = d;
		for(int i=0; i<tam;i++){
			participantes[i] = nullptr;
		}
	}
	
	bool agregarParticipante(Animal* a){
		if(can < tam){
			participantes[can++] = a;
			return true;
		}
		return false;
	}
	
	virtual ~Juego(){
		for(int i=0; i< can; i++){
			delete participantes[i];
		}
		delete[]participantes;
	}
		
	void carrera(){
		srand(time(NULL));
		int r = 1;
		while(true){
			bool llego = false;
			cout << "=================== Round ==================== " << r++ << endl << endl;
			for(int i=0; i<can; i++){
				participantes[i]->correr(); // aqui se aplica polimorfismo
				cout << participantes[i]->toString() << endl;
				if(participantes[i]->getPosicion() >= distancia){
					cout << "ha llegado a la meta" << endl;
					llego = true;
				}
			}
			
			cout << endl << endl;
			
			if(llego){
				break;
			}
			
		}
	}
};



int main(int argc, char *argv[]) {
	Juego* j = new Juego(300);
	j->agregarParticipante(new Perro("Tobias", "Pastor Australiano"));
	j->agregarParticipante(new Perro("Firulais", "Saguate"));
	j->agregarParticipante(new Tortuga("Donatelo"));
	j->agregarParticipante(new Liebre("Buck"));
	
	j->carrera();
	
	delete j;
	
	return 0;
}


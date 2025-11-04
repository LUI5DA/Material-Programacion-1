#include <iostream>
#include <sstream>
#include <memory>
#include <string>
using namespace std;

// cuando una clase tiene almenos un metodo virtual pura, es una clase abstracta
// una clase abstracta no se puede instanciar directamente

// Empleado* ptr = new Empleado(); // Error: no se puede instanciar una clase abstracta
class Empleado {
public:
    virtual ~Empleado() = default;
    virtual double calcularSalario() const = 0;
    virtual string toString() const = 0;
};

class TiempoCompleto : public Empleado {
    double base;
	// Plaza* plaza; // Suponiendo que Plaza es otra clase
public:
    ~TiempoCompleto() {
		// delete plaza; // Liberar recursos si es necesario
		// si el destructor del padre no fuera virtual, no se llamaria al destructor de la clase derivada
		// y aqui se generaria un memory leak
		// un memory leak ocurre cuando se pierde la referencia a un bloque de memoria asignado dinamicamente
    }
    explicit TiempoCompleto(double b) : base(b) {}
    double calcularSalario() const override { return base; }
    string toString() const override { return "TiempoCompleto: " + to_string(base); }
    void subirBono(double x) { base += x; }
};

class MedioTiempo : public Empleado {
    double horas, tarifa;
public:
    MedioTiempo(double h, double t) : horas(h), tarifa(t) {}
    double calcularSalario() const override { return horas * tarifa; }
    string toString() const override { return "MedioTiempo: " + to_string(horas * tarifa); }
    void ajustarHoras(double h) { horas = h; }
};

class Consultor : public Empleado {
    double tarifa, proyectos;
public:
    Consultor(double t, double p) : tarifa(t), proyectos(p) {}
    double calcularSalario() const override { return tarifa * proyectos; }
    string toString() const override { return "Consultor: " + to_string(tarifa * proyectos); }
    void agregarProyecto() { ++proyectos; }
};

class Nodo {
    unique_ptr<Empleado> persona;
    Nodo* sig;
public:
    explicit Nodo(unique_ptr<Empleado> e) : persona(move(e)), sig(nullptr) {}
    Nodo(const Nodo&) = delete;
    Nodo& operator=(const Nodo&) = delete;
    Empleado* get() const { return persona.get(); }
    void setSig(Nodo* n) { sig = n; }
    Nodo* next() const { return sig; }
    ~Nodo() = default;
};

class Lista {
    Nodo* primero = nullptr;
public:
    Lista() = default;
    Lista(const Lista&) = delete;
    Lista& operator=(const Lista&) = delete;
    Lista(Lista&& o) noexcept : primero(o.primero) { o.primero = nullptr; }
    Lista& operator=(Lista&& o) noexcept {
        if (this != &o) { limpiar(); primero = o.primero; o.primero = nullptr; }
        return *this;
    }
    ~Lista() { limpiar(); }
    void agregar(unique_ptr<Empleado> e) {
        Nodo* n = new Nodo(move(e));
        n->setSig(primero);
        primero = n;
    }
	// primero -> b -> c -> d -> e -> nullptr
	// n -> primero 
	// n -> primero -> b -> c -> d -> e -> nullptr


    string toString() const {
        stringstream s; Nodo* a = primero;
        while (a) { s << a->get()->toString() << "\n"; a = a->next(); }
        return s.str();
    }

    double salarioTotal() const {
        double t = 0.0; Nodo* a = primero;
        while (a) { t += a->get()->calcularSalario(); a = a->next(); }
        return t;
    }
    size_t contar() const {
        size_t c = 0; for (Nodo* a = primero; a; a = a->next()) ++c; return c;
    }
    void actualizar() {
        Nodo* a = primero;
        while (a) {
            if (auto* tc = dynamic_cast<TiempoCompleto*>(a->get())) tc->subirBono(100);
            if (auto* mt = dynamic_cast<MedioTiempo*>(a->get())) mt->ajustarHoras(mt->calcularSalario() / 10);
            if (auto* c = dynamic_cast<Consultor*>(a->get())) c->agregarProyecto();
            a = a->next();
        }
    }
private:
    void limpiar() {
        while (primero) { Nodo* x = primero; primero = primero->next(); delete x; }
    }
};

//int main() {
//    Lista lista;
//    // lista + otralista programo una funcion para que se puedan sumar dos listas 
//	// eso es sobrecarga de operadores
//
//    lista.agregar(make_unique<TiempoCompleto>(2500));
//    lista.agregar(make_unique<MedioTiempo>(80, 10));
//    lista.agregar(make_unique<Consultor>(500, 3));
//    cout << lista.toString(); // con que codigo lo linkeo??
//    cout << lista.salarioTotal() << "\n";
//    cout << lista.contar() << "\n";
//    lista.actualizar();
//    cout << lista.toString();
//    cout << lista.salarioTotal() << "\n";
//    cout << lista.contar() << "\n";
//    return 0;
//}

// 01010101011100011110011001101010101010101010101010101010101010101010101010101010101010101010101010101
// luego esto se junta con el codigo de las librerias estandar y se genera el ejecutable

// Empleado es: 
// A) Concreta ☐ 
// B) Abstracta ☐ 
// C) Final ☐ 
// D) Plantilla ☐

// Respuesta: B) Abstracta ☑


// ----------------------------------------------------------
// El destructor virtual en Empleado permite: 
// A) Evitar RTTI ☐
// B) Destrucción correcta vía puntero base ☐
// C) Herencia múltiple ☐ 
// D) Copias profundas ☐


// Respuesta: B) Destrucción correcta vía puntero base ☑
// Empleado* ptr = new TiempoCompleto(1000, plaza);
// delete ptr; // Llama al destructor de TiempoCompleto y luego al de Empleado
// destructor de la clase derivarivada (TiempoCompleto) -> destructor de la clase base (Empleado)


// ----------------------------------------------------------
// Lista::agregar inserta: 
// A) Al final ☐ 
// B) Al inicio ☐ 
// C) En orden ☐ 
// D) Aleatorio ☐

// Respuesta: B) Al inicio ☑


// ----------------------------------------------------------   
// unique_ptr<Empleado> evita: 
// A) Polimorfismo ☐ 
// B) Fugas del objeto Empleado ☐ 
// C) Herencia ☐ 
// D) Despacho virtual ☐

// Respuesta: B) Fugas del objeto Empleado ☑


// ----------------------------------------------------------
// toString() se resuelve: 
// A) En compilación ☐ 
// B) En ejecución (virtual) ☐ 
// C) En linkeo ☐ 
// D) Nunca ☐

// Respuesta: B) En ejecución (virtual) ☑

// HAY que entender el proceso de compilación, linkeo y ejecución
// Compilación: Traduce el código fuente a código objeto (binario)


// ----------------------------------------------------------
// 
// dynamic_cast<TiempoCompleto*> es: 
// A) Upcast ☐ 
// B) Downcast seguro ☐ 
// C) Implícito ☐ 
// D) reinterpret_cast ☐

// Respuesta: B) Downcast seguro ☑

// que es upcast y downcast? -> cast significa conversión de tipos
// "53" -> int(53) casteo estoy pasando de string a int
// Empleado* e = new TiempoCompleto(1000); // upcast
// TiempoCompleto* tc = dynamic_cast<TiempoCompleto*>(e); // downcast seguro

// Tiempocompleto* tc = (TiempoCompleto*)e; // downcast inseguro (C-style cast)

// ----------------------------------------------------------
// subirBono(100) produce: 
// A) base += 100 ☐
// B) base -= 100 ☐
// C) Sin efecto ☐
// D) Excepción ☐

// Respuesta: A) base += 100 ☑
// Para poder llamarlo hay que hacer un downcast seguro a TiempoCompleto*
// if (auto* tc = dynamic_cast<TiempoCompleto*>(a->get())) tc->subirBono(100);




// ----------------------------------------------------------
// MedioTiempo::calcularSalario() calcula: 
// A) base ☐ 
// B) tarifa ☐ 
// C) horas * tarifa ☐ 
// D) tarifa * proyectos ☐

// Respuesta: C) horas * tarifa ☑

// ----------------------------------------------------------
// Consultor::calcularSalario() calcula: 
// A) tarifa * proyectos ☐ 
// B) tarifa + proyectos ☐ 
// C) horas * tarifa ☐ 
// D) base ☐

// Respuesta: A) tarifa * proyectos ☑

// ----------------------------------------------------------
// Lista::limpiar() debe: 
// A) Ignorar next ☐ 
// B) Destruir nodos y sus empleados ☐ 
// C) Solo liberar cabeza ☐ 
// D) No hacer nada ☐


// Respuesta: D) No hacer nada ☑
// Porque los empleados son manejados por unique_ptr dentro de Nodo

// ----------------------------------------------------------

// Lista prohíbe: 
// A) Movimiento ☐ 
// B) Copia ☐ 
// C) Destructor ☐ 
// D) unique_ptr ☐

// Respuesta: B) Copia ☑


// ----------------------------------------------------------
// El move-constructor deja la lista movida en: 
// A) Duplicada ☐ 
// B) nullptr ☐ 
// C) Inválida ☐ 
// D) Igual ☐

// Respuesta: B) nullptr ☑
// Lista(Lista&& o) noexcept : primero(o.primero) { o.primero = nullptr; }


// ----------------------------------------------------------
// En actualizar(), MedioTiempo recibe : 
// A) ajustarHoras(10) ☐ 
// B) ajustarHoras(calcularSalario() / 10) ☐ 
// C) ajustarHoras(tarifa) ☐ 
// D) ajustarHoras(horas + 1) ☐

// Respuesta: B) ajustarHoras(calcularSalario() / 10) ☑

// ----------------------------------------------------------
// Nodo elimina copias para: 
// A) Evitar doble propiedad ☐ 
// B) Acelerar ☐ 
// C) Permitir polimorfismo ☐ 
// D) Ordenar ☐

// Respuesta: A) Evitar doble propiedad ☑
// unique_ptr no permite copias porque eso generaria doble propiedad del mismo recurso

// ----------------------------------------------------------

/* salarioTotal() usa: 
A) Campos privados ☐ 
B) calcularSalario() ☐ 
C) reinterpret_cast ☐ 
D) sizeof ☐

Respuesta: B) calcularSalario() ☑


------------------------------------------------------------


toString() devuelve: 
A) Mismo texto siempre ☐ 
B) Texto polimórfico ☐ 
C) Un double ☐ 
D) Un int ☐

Respuesta: B) Texto polimórfico ☑

------------------------------------------------------------

El orden de toString() corresponde a: 
A) FIFO ☐ (first in first out)
B) LIFO ☐ (last in first out) 
C) Alfabético ☐ 
D) Aleatorio ☐

Respuesta: B) LIFO ☑

------------------------------------------------------------

La firma correcta en la base es: (cual es la declaracion del tostring en la clase Empleado)
A) virtual string toString(); ☐ 
B) virtual string toString() const = 0; ☐ 
C) string toString() const; ☐ 
D) static string toString(); ☐

Respuesta: B) virtual string toString() const = 0; ☑

------------------------------------------------------------

Para añadir Becario: 
A) Heredar de Empleado y overridear ☐ 
B) Heredar de TiempoCompleto ☐ 
C) Quitar virtuales ☐ 
D) Guardar por valor ☐

Respuesta: A) Heredar de Empleado y overridear ☑

------------------------------------------------------------

Sin destructor virtual en Empleado:
A) Correcto desde base ☐ 
B) Riesgo de destrucción incompleta ☐ 
C) No compila ☐ 
D) Igual ☐


Respuesta: B) Riesgo de destrucción incompleta ☑
*/


#include "Prestamo.h"

using namespace std;

// Constructores
Prestamo::Prestamo()
    : estudiante(nullptr), libro(nullptr), devuelto(false) {}

Prestamo::Prestamo(Estudiante* est, Libro* lib, bool devuelto)
    : estudiante(est), libro(lib), devuelto(devuelto) {}

// Setters
void Prestamo::setEstudiante(Estudiante* est) { this->estudiante = est; }

void Prestamo::setLibro(Libro* lib) { this->libro = lib; }

void Prestamo::setDevuelto(bool estado) { this->devuelto = estado; }

// Getters
Estudiante* Prestamo::getEstudiante() const { return estudiante; }

Libro* Prestamo::getLibro() const { return libro; }

bool Prestamo::estaDevuelto() const { return devuelto; }

// Operaciones
void Prestamo::marcarDevuelto() { devuelto = true; }

// Utilidad
string Prestamo::toString() const {
    ostringstream oss;
    oss << "[PRESTAMO]\n";
    oss << "Devuelto: " << (devuelto ? "Si" : "No") << "\n";

    if (estudiante) {
        oss << "-- Estudiante --\n" << estudiante->toString() << "\n";
    }
    else {
        oss << "-- Estudiante --\n(nullptr)\n";
    }

    if (libro) {
        oss << "-- Libro --\n" << libro->toString() << "\n";
    }
    else {
        oss << "-- Libro --\n(nullptr)\n";
    }

    return oss.str();
}

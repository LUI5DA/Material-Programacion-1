#include "Estudiante.h"

// Constructores
Estudiante::Estudiante()
    : cedula(""), telefono(""), email(""), nombre("") {}

Estudiante::Estudiante(const string& cedula, const string& telefono, const string& email, const string& nombre)
    : cedula(cedula), telefono(telefono), email(email), nombre(nombre) {}

// Setters
void Estudiante::setCedula(const string& cedula) { this->cedula = cedula; }

void Estudiante::setTelefono(const string& telefono) { this->telefono = telefono; }

void Estudiante::setEmail(const string& email) { this->email = email; }

void Estudiante::setNombre(const string& nombre) { this->nombre = nombre; }

// Getters
string Estudiante::getCedula() { return cedula; }

string Estudiante::getTelefono() { return telefono; }

string Estudiante::getEmail() { return email; }

string Estudiante::getNombre() { return nombre; }

// Funciones útiles
string Estudiante::toString() {
    ostringstream oss;
    oss << "Cedula: " << cedula
        << "\nNombre: " << nombre
        << "\nTelefono: " << telefono
        << "\nEmail: " << email;
    return oss.str();
}

#include "Libro.h"

// Constructores
Libro::Libro()
    : ISBN(0), precio(0.0), nombre(""), autor(""), prestado(false) {}

Libro::Libro(int isbn, double precio, const string& nombre, const string& autor)
    : ISBN(isbn), precio(precio), nombre(nombre), autor(autor), prestado(false) {}

// Setters
void Libro::setISBN(int isbn) { this->ISBN = isbn; }

void Libro::setPrecio(double precio) { this->precio = precio; }

void Libro::setNombre(const string& nombre) { this->nombre = nombre; }

void Libro::setAutor(const string& autor) { this->autor = autor; }

void Libro::setPrestado(bool estado) { this->prestado = estado; }

// Getters
int Libro::getISBN() const { return ISBN; }

double Libro::getPrecio() const { return precio; }

string Libro::getNombre() const { return nombre; }

string Libro::getAutor() const { return autor; }

bool Libro::estaPrestado() const { return prestado; }

// Funciones útiles
void Libro::prestar() { prestado = true; }

void Libro::devolver() { prestado = false; }

string Libro::toString() const {
    ostringstream oss;
    oss << "ISBN: " << ISBN
        << "\nTitulo: " << nombre
        << "\nAutor: " << autor
        << "\nPrecio: $" << precio
        << "\nEstado: " << (prestado ? "Prestado" : "Disponible");
    return oss.str();
}

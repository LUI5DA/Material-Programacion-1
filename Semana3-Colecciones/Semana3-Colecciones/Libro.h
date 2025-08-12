#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Libro
{
private:
    int ISBN;
    double precio;
    string nombre;
    string autor;
    bool prestado; // true si est� prestado, false si est� disponible

public:
    // Constructores
    Libro();

    Libro(int isbn, double precio, const string& nombre, const string& autor);

    // Setters
    void setISBN(int isbn);

    void setPrecio(double precio);

    void setNombre(const string& nombre);

    void setAutor(const string& autor);

    void setPrestado(bool estado);

    // Getters
    int getISBN() const;

    double getPrecio() const;

    string getNombre() const;

    string getAutor() const;

    bool estaPrestado() const;

    // Funciones �tiles
    void prestar();

    void devolver();

    string toString() const;
};

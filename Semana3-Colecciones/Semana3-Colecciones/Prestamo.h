#pragma once
#include <string>
#include <sstream>
#include "Estudiante.h"
#include "Libro.h"

using namespace std;

class Prestamo
{
private:
    Estudiante* estudiante; // puntero no-propietario (no se libera aquí)

    Libro* libro;           // puntero no-propietario (no se libera aquí)

    bool devuelto;          // true si el préstamo fue devuelto/finalizado

public:
    // Constructores
    Prestamo();                                      // punteros a nullptr, devuelto=false

    Prestamo(Estudiante* est, Libro* lib, bool devuelto = false);

    // Setters (asignan direcciones existentes; no toman propiedad)
    void setEstudiante(Estudiante* est);

    void setLibro(Libro* lib);

    void setDevuelto(bool estado);

    // Getters
    Estudiante* getEstudiante() const;

    Libro* getLibro() const;

    bool estaDevuelto() const;

    // Operaciones
    void marcarDevuelto();

    // Utilidad
    string toString() const;
};

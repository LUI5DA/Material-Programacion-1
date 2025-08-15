#pragma once
#include "Prestamo.h"

using namespace std;

class ContenedorPrestamosDyn
{
private:
    Prestamo** vec; // arreglo dinámico de punteros a Prestamo (objetos dinámicos)
    int can;        // cantidad usada
    int tam;        // capacidad

    void resize(int nuevoTam);

public:
    // Ctor / Dtor
    ContenedorPrestamosDyn(int capacidadInicial = 4);

    ~ContenedorPrestamosDyn();

    // Operaciones
    bool insert(Prestamo& p);                      

    bool insert(Estudiante* est, Libro* lib, bool devuelto = false); // atajo

    int  search(string& cedula, int isbn);   // -1 si no existe

    Prestamo* getAt(int i);                         // copia; Prestamo() si índice inválido

    bool deleteP(string& cedula, int isbn);        // elimina y compacta

    // Utilidades
    string toString();

    int size() { return can; }

    int capacity() { return tam; }


    bool prestado(int);

    bool prestamosActivos(string);

    string listarActivos();
};

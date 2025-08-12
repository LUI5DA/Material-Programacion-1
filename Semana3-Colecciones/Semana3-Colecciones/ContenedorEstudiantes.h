#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Estudiante.h"

using namespace std;

class ContenedorEstudiantesDyn
{
private:
    Estudiante** vec; // arreglo din�mico de punteros a Estudiante (objetos din�micos)
    int can;          // cantidad usada
    int tam;          // capacidad

    void resize(int nuevoTam);

public:
    // Ctor / Dtor
    ContenedorEstudiantesDyn(int capacidadInicial = 4);

    ~ContenedorEstudiantesDyn();

    // Operaciones
    bool insert(Estudiante& e);

    int  search(string& cedula);   // -1 si no existe

    Estudiante* getAt(int i);             // copia por valor; Estudiante() si i inv�lido

    bool deleteE(string& cedula);        // elimina y compacta

    // Utilidades
    string toString();

    int size() { return can; }

    int capacity() { return tam; }
};

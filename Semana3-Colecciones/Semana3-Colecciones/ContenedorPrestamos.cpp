#include "ContenedorPrestamos.h"

// ----------- Privado -----------
void ContenedorPrestamosDyn::resize(int nuevoTam)
{
    if (nuevoTam <= tam) return;

    Prestamo** nuevo = new Prestamo * [nuevoTam];
    for (int i = 0; i < can; ++i) nuevo[i] = vec[i];  // mover punteros existentes
    for (int i = can; i < nuevoTam; ++i) nuevo[i] = nullptr;

    delete[] vec;
    vec = nuevo;
    tam = nuevoTam;
}

// ----------- Públicos -----------
ContenedorPrestamosDyn::ContenedorPrestamosDyn(int capacidadInicial)
    : vec(nullptr), can(0), tam(capacidadInicial > 0 ? capacidadInicial : 4)
{
    vec = new Prestamo * [tam];
    for (int i = 0; i < tam; ++i) vec[i] = nullptr;
}

ContenedorPrestamosDyn::~ContenedorPrestamosDyn()
{
    for (int i = 0; i < can; ++i) delete vec[i]; // borra los Prestamo
    delete[] vec;
}


bool ContenedorPrestamosDyn::insert(const Prestamo& p)
{
    if (can >= tam) resize(tam * 2);
    vec[can++] = new Prestamo(p); // copia del Prestamo (sus punteros se comparten)
    return true;
}

bool ContenedorPrestamosDyn::insert(Estudiante* est, Libro* lib, bool devuelto)
{
    if (can >= tam) resize(tam * 2);
    vec[can++] = new Prestamo(est, lib, devuelto);
    return true;
}

int ContenedorPrestamosDyn::search(const string& cedula, int isbn) const
{
    for (int i = 0; i < can; ++i) {
        if (!vec[i]) continue;
        Estudiante* e = vec[i]->getEstudiante();
        Libro* l = vec[i]->getLibro();
        if (e && l && e->getCedula() == cedula && l->getISBN() == isbn) {
            return i;
        }
    }
    return -1;
}

Prestamo ContenedorPrestamosDyn::getAt(int i) const
{
    if (i >= 0 && i < can && vec[i] != nullptr) return *vec[i]; // devuelve copia
    return Prestamo();
}

bool ContenedorPrestamosDyn::deleteP(const string& cedula, int isbn)
{
    int index = search(cedula, isbn);
    if (index == -1) return false;

    delete vec[index]; // borra el Prestamo, NO estudiante/libro
    for (int i = index; i < can - 1; ++i) vec[i] = vec[i + 1];
    vec[--can] = nullptr;

    return true;
}

string ContenedorPrestamosDyn::toString() const
{
    ostringstream s;
    for (int i = 0; i < can; ++i) {
        if (vec[i]) s << vec[i]->toString() << endl;
    }
    s << endl;
    return s.str();
}

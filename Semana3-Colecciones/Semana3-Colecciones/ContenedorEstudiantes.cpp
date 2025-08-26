#include "ContenedorEstudiantes.h"

// -------------------- Privado --------------------
void ContenedorEstudiantesDyn::resize(int nuevoTam)
{
    if (nuevoTam <= tam) return;

    Estudiante** nuevo = new Estudiante * [nuevoTam];
    for (int i = 0; i < can; ++i) {
        nuevo[i] = vec[i]; // mover punteros existentes
    }
    for (int i = can; i < nuevoTam; ++i) {
        nuevo[i] = nullptr;
    }

    delete[] vec;
    vec = nuevo;
    tam = nuevoTam;
}

// -------------------- Públicos --------------------
ContenedorEstudiantesDyn::ContenedorEstudiantesDyn(int capacidadInicial)
    : vec(nullptr), can(0), tam(capacidadInicial > 0 ? capacidadInicial : 4)
{
    vec = new Estudiante * [tam];
    for (int i = 0; i < tam; ++i) vec[i] = nullptr;
}

ContenedorEstudiantesDyn::~ContenedorEstudiantesDyn()
{
    for (int i = 0; i < can; ++i) {
        delete vec[i];
    }
    delete[] vec;
}

bool ContenedorEstudiantesDyn::insert(Estudiante& e)
{
    if (can >= tam) {
        resize(tam * 2); // crecer
    }
    vec[can++] = &e;
    return true;
}

int ContenedorEstudiantesDyn::search(string& cedula)
{
    for (int i = 0; i < can; ++i) {
        if (vec[i] && vec[i]->getCedula() == cedula) return i;
    }
    return -1;
}

Estudiante* ContenedorEstudiantesDyn::getAt(int i)
{
    if (i >= 0 && i < can && vec[i] != nullptr) {
        return vec[i]; // devolver copia
    }
    return nullptr;
}

bool ContenedorEstudiantesDyn::deleteE(string& cedula)
{
    int index = search(cedula);
    if (index == -1) return false;

    // liberar el objeto dinámico
    delete vec[index];

    // compactar desplazando punteros
    for (int i = index; i < can - 1; ++i) {
        vec[i] = vec[i + 1];
    }
    vec[can - 1] = nullptr;
    --can;

    return true;
}

string ContenedorEstudiantesDyn::toString()
{
    ostringstream s;
    for (int i = 0; i < can; ++i) {
        if (vec[i]) s << vec[i]->toString() << endl << endl;
    }
    s << endl;
    return s.str();
}

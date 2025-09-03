#include "ContenedorMascotas.h"

ContenedorMascotas::ContenedorMascotas()
{
    can = 0;
    tam = 20;
    vec = new Mascota * [tam];
    for (int i = 0; i < tam; i++) {
        vec[i] = nullptr;
    }
}

ContenedorMascotas::~ContenedorMascotas()
{
    for (int i = 0; i < can; i++) {
        delete vec[i];
    }
    delete[] vec;
}

bool ContenedorMascotas::agregarMascota(Mascota* m)
{
    if (can < tam) {
        vec[can++] = m;
        return true;
    }
    return false;
}

bool ContenedorMascotas::eliminar(string id)
{
    int pos = getPos(id);
    if (pos == -1) {
        return false;
    }

    delete vec[pos];
    for (int i = pos; i < can-1; i++) {
        vec[i] = vec[i + 1];
    }
    can--;
    return true;
}

int ContenedorMascotas::getPos(string id)
{
    for (int i = 0; i < can; i++) {
        if (vec[i]->getId() == id) {
            return i;
        }
    }
    return -1;
}

Mascota* ContenedorMascotas::buscar(string id)
{
    for (int i = 0; i < can; i++) {
        if (vec[i]->getId() == id) {
            return vec[i];
        }
    }
    return nullptr;
}

void ContenedorMascotas::ordenar()
{
    for (int i = 0; i < can; i++) {
        for (int j = i; j < can; j++) {
            if (vec[j]->getId() < vec[i]->getId()) {
                mySawap(i, j);
            }
        }
    }
}

void ContenedorMascotas::mySawap(int i, int j)
{
    Mascota* aux = vec[i];
    vec[i] = vec[j];
    vec[j] = aux;
}

string ContenedorMascotas::toString()
{
    stringstream s;
    for (int i = 0; i < can; i++) {
        s << vec[i]->toString() << endl;
    }
    return s.str();
}

#include "Biblioteca.h"

bool Biblioteca::hayPrestamoActivoDeISBN(int isbn)
{
    return prestamos->prestado(isbn);
}

bool Biblioteca::tienePrestamosActivosEstudiante(string& cedula)
{
    return prestamos->prestamosActivos(cedula);
}

Biblioteca::Biblioteca()
{
    this->libros = new ContenedorLibros4();
    this->estudiantes = new ContenedorEstudiantesDyn();
    this->prestamos = new ContenedorPrestamosDyn();
}

Biblioteca::~Biblioteca()
{
    delete prestamos;
    delete libros;
    delete estudiantes;
}

bool Biblioteca::registrarEstudiante(Estudiante& e)
{
    string ced = e.getCedula();
    if (estudiantes->search(ced) != -1) {
        return false;
    }
    return estudiantes->insert(e);
    return true;
}

bool Biblioteca::eliminarEstudiante(string& cedula)
{
    return estudiantes->deleteE(cedula);
}

Estudiante* Biblioteca::buscarEstudiantePtr(string& cedula)
{
    return estudiantes->getAt(estudiantes->search(cedula));
}

string Biblioteca::listarEstudiantes()
{
    return estudiantes->toString();
}

bool Biblioteca::agregarLibro(Libro& l)
{
    return libros->insert(l);
}

bool Biblioteca::eliminarLibro(int isbn)
{
    return libros->deleteL(isbn);
}

Libro* Biblioteca::buscarLibroPtr(int isbn)
{
    return libros->getAt(libros->search(isbn));
}

string Biblioteca::listarLibros()
{
    return libros->toString();
}

bool Biblioteca::prestarLibro(string& cedula, int isbn)
{
    Libro* l = buscarLibroPtr(isbn);
    Estudiante* e = buscarEstudiantePtr(cedula);

    // validaciones
    if (!l || !e) {
        return false;
    }
    if (hayPrestamoActivoDeISBN(isbn)) {
        return false;
    }

    //insertar el prestamo
    Prestamo* p = new Prestamo(e, l, false);
    if(prestamos->insert(*p)){
        return true;
    }
    else {
        delete p;
        return false;
    }
}

bool Biblioteca::devolverLibro(string& cedula, int isbn)
{
    Prestamo* p = prestamos->getAt(prestamos->search(cedula, isbn));
    if (!p) {
        return false;
    }

    if (p->estaDevuelto()) {
        return false;
    }

    p->marcarDevuelto();
    return true;
}

string Biblioteca::listarPrestamos()
{
    return prestamos->toString();
}

string Biblioteca::listarPrestamosActivos()
{
    return prestamos->listarActivos();
}

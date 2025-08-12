#pragma once
#include "ContenedorEstudiantes.h"
#include "ContenedorPrestamos.h"
#include "ContenedorLibros.h"

using namespace std;

class Biblioteca
{
private:
    ContenedorEstudiantesDyn* estudiantes;
    ContenedorLibros1*      libros;
    ContenedorPrestamosDyn*   prestamos;

    // Helpers
    bool hayPrestamoActivoDeISBN(int isbn) const;
    bool tienePrestamosActivosEstudiante(const string& cedula) const;

public:
    Biblioteca();

    // Gesti�n de estudiantes
    bool registrarEstudiante(const Estudiante& e);
    bool eliminarEstudiante(const string& cedula); // solo si no tiene pr�stamos activos
    Estudiante* buscarEstudiantePtr(const string& cedula) const;
    string listarEstudiantes() const;

    // Gesti�n de libros
    bool agregarLibro(const Libro& l);
    bool eliminarLibro(int isbn); // solo si no est� prestado
    Libro* buscarLibroPtr(int isbn) const;
    string listarLibros() const;

    // Pr�stamos
    bool prestarLibro(const string& cedula, int isbn);
    bool devolverLibro(const string& cedula, int isbn);

    // Reportes
    string listarPrestamos() const;
    string listarPrestamosActivos() const;
};

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

    // Gestión de estudiantes
    bool registrarEstudiante(const Estudiante& e);
    bool eliminarEstudiante(const string& cedula); // solo si no tiene préstamos activos
    Estudiante* buscarEstudiantePtr(const string& cedula) const;
    string listarEstudiantes() const;

    // Gestión de libros
    bool agregarLibro(const Libro& l);
    bool eliminarLibro(int isbn); // solo si no está prestado
    Libro* buscarLibroPtr(int isbn) const;
    string listarLibros() const;

    // Préstamos
    bool prestarLibro(const string& cedula, int isbn);
    bool devolverLibro(const string& cedula, int isbn);

    // Reportes
    string listarPrestamos() const;
    string listarPrestamosActivos() const;
};

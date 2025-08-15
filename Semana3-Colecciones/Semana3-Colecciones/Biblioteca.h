#pragma once
#include "ContenedorEstudiantes.h"
#include "ContenedorPrestamos.h"
#include "ContenedorLibros.h"

using namespace std;

class Biblioteca
{
private:
    ContenedorEstudiantesDyn* estudiantes;
    ContenedorLibros4*      libros;
    ContenedorPrestamosDyn*   prestamos;

    // Helpers
    bool hayPrestamoActivoDeISBN(int isbn);

    bool tienePrestamosActivosEstudiante(string& cedula);

public:
    Biblioteca();

    ~Biblioteca();

    // Gestión de estudiantes
    bool registrarEstudiante(Estudiante& e);

    bool eliminarEstudiante(string& cedula); // solo si no tiene préstamos activos

    Estudiante* buscarEstudiantePtr(string& cedula);

    string listarEstudiantes();

    // Gestión de libros
    bool agregarLibro(Libro& l);

    bool eliminarLibro(int isbn); // solo si no está prestado

    Libro* buscarLibroPtr(int isbn);

    string listarLibros();

    // Préstamos
    bool prestarLibro(string& cedula, int isbn);

    bool devolverLibro(string& cedula, int isbn);

    // Reportes
    string listarPrestamos();

    string listarPrestamosActivos();
};

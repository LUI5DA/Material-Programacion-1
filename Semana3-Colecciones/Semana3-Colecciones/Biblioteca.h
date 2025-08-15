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

    // Gesti�n de estudiantes
    bool registrarEstudiante(Estudiante& e);

    bool eliminarEstudiante(string& cedula); // solo si no tiene pr�stamos activos

    Estudiante* buscarEstudiantePtr(string& cedula);

    string listarEstudiantes();

    // Gesti�n de libros
    bool agregarLibro(Libro& l);

    bool eliminarLibro(int isbn); // solo si no est� prestado

    Libro* buscarLibroPtr(int isbn);

    string listarLibros();

    // Pr�stamos
    bool prestarLibro(string& cedula, int isbn);

    bool devolverLibro(string& cedula, int isbn);

    // Reportes
    string listarPrestamos();

    string listarPrestamosActivos();
};

#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Estudiante
{
private:
    string cedula;
    string telefono;
    string email;
    string nombre;

public:
    // Constructores
    Estudiante();

    Estudiante(const string& cedula, const string& telefono, const string& email, const string& nombre);

    // Setters
    void setCedula(const string& cedula);

    void setTelefono(const string& telefono);

    void setEmail(const string& email);

    void setNombre(const string& nombre);

    // Getters
    string getCedula() const;

    string getTelefono() const;

    string getEmail() const;

    string getNombre() const;

    // Funciones útiles
    string toString() const;
};

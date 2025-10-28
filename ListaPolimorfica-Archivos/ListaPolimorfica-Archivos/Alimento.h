#pragma once
#include "Perecedero.h"
class Alimento :
    public Perecedero
{
private:
    double porcGrasa;

public:
    Alimento(int, string, double, double, string, Fecha*, double);
    virtual ~Alimento();

    double getPorcGrasa();
    void setPorcGrasa(double);

    virtual string toString();

    // metodos para usar archivos
    static Alimento* read(ifstream& descriptor);
    void write(ofstream& descriptor);
};


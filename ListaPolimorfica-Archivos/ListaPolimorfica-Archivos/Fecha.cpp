#include "Fecha.h"

Fecha::Fecha(int dia, int mes, int anio)
{
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

Fecha::~Fecha()
{
}

int Fecha::getDia()
{
    return this->dia;
}

int Fecha::getMes()
{
    return this->mes;
}

int Fecha::getAnio()
{
    return this->mes;
}

void Fecha::setDia(int dia)
{
    this->dia = dia;
}

void Fecha::setMes(int mes)
{
    this->mes = mes;
}

void Fecha::setAnio(int anio)
{ 
    this->anio = anio;
}

string Fecha::toString() {
    stringstream s;
    s << dia << "/" << mes << "/" << anio << endl;

    return s.str();
}


// funcion que recibe un descriptor de archivo de lectura y lee la informacion de una fecha y reteorna la fecha con   la info leida
// el ifstream es un descriptor de solo lectura
// todo lo lee como texto

// ifstream -> input file stream

Fecha* Fecha::read(ifstream& descriptor)
{
    string d;
    string m;
    string a;



    descriptor >> d; // lee hasta encontrar un espacio, tab, salto de linea (todo lo lee )
    descriptor >> m;
    descriptor >> a;

    int dd = stoi(d);
    int mm = stoi(m);
    int aa = stoi(a);


    // getline(descriptor, d); // lee toda la linea es decir hasta encontrarse con /n

    return new Fecha(dd, mm, aa);
}


// ofstream -> out file stream

void Fecha::write(ofstream& descriptor)
{
    descriptor << dia << '\t' << mes << '\t' << anio << '\n';
}




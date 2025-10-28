#include "Ropa.h"

Ropa::Ropa(int id, string descripcion, double precio , double iva, string marca, int garantia, string talla)
    : NoPerecedero::NoPerecedero(id, descripcion, precio, iva, marca, garantia)
{
    this->talla = talla;
}

Ropa::~Ropa()
{
}

string Ropa::getTalla()
{
    return talla;
}

void Ropa::setTalla(string)
{
	this->talla = talla;
}

string Ropa::toString() {
    stringstream s;
    s << "--------------------------------------------------------" << endl;
    s << "Ropa" << endl;
    s << NoPerecedero::toString();
    s << "Talla: " << this->talla << endl;
    s << "--------------------------------------------------------" << endl;
    return s.str();
}

Ropa* Ropa::read(ifstream& descriptor) {
    string id;
    string descripcion;
    string precio;
    string IVA;
    string marca;
    string garantia;
    string talla;
    descriptor >> id;
    descriptor >> descripcion;
    descriptor >> precio;
    descriptor >> IVA;
    descriptor >> marca;
    descriptor >> garantia;
    descriptor >> talla;
    int i = stoi(id);
    int g = stoi(garantia);
    stringstream pp(precio);
    stringstream ii(IVA);
    double ppp, iii;
    pp >> ppp;
    ii >> iii;
    Ropa* r = new Ropa(i, descripcion, ppp, iii, marca, g, talla);
    return r;
}

void Ropa::write(ofstream& descriptor) {
    descriptor << "R" << '\n';
    descriptor << this->id << '\t';
    descriptor << this->descripcion << '\t';
    descriptor << this->precio << '\t';
    descriptor << this->IVA << '\t';
    descriptor << this->marca << '\t';
    descriptor << this->aniosGarantia << '\t';
    descriptor << this->talla << '\n';
}

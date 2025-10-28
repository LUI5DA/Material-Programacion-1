#include "Herramienta.h"

Herramienta::Herramienta(int id, string descripcion, double precio, double iva, string marca, int garantia, double peso)
	:NoPerecedero::NoPerecedero(id, descripcion, precio, iva, marca, garantia)
{
	this->peso = peso;
}

Herramienta::~Herramienta()
{
}

double Herramienta::getPeso()
{
    return peso;
}

void Herramienta::setPeso(double)
{
	this->peso = peso;
}

string Herramienta::toString() {
	stringstream s;
	s << "--------------------------------------------------------" << endl;
	s << "Herramienta" << endl;
	s << NoPerecedero::toString();
	s << "Peso: " << this->peso << endl;
	s << "--------------------------------------------------------" << endl;
	return s.str();
}

Herramienta* Herramienta::read(ifstream& descriptor) {
	string id;
	string descripcion;
	string precio;
	string IVA;
	string marca;
	string garantia;
	string peso;
	descriptor >> id;
	descriptor >> descripcion;
	descriptor >> precio;
	descriptor >> IVA;
	descriptor >> marca;
	descriptor >> garantia;
	descriptor >> peso;
	int i = stoi(id);
	int g = stoi(garantia);
	stringstream pp(precio);
	stringstream ii(IVA);
	stringstream vv(peso);
	double ppp, iii, vvv;
	pp >> ppp;
	ii >> iii;
	vv >> vvv;
	Herramienta* h = new Herramienta(i, descripcion, ppp, iii, marca, g, vvv);
	return h;
}

void Herramienta::write(ofstream& descriptor) {
	descriptor << "H" << '\n';
	descriptor << this->id << '\t';
	descriptor << this->descripcion << '\t';
	descriptor << this->precio << '\t';
	descriptor << this->IVA << '\t';
	descriptor << this->marca << '\t';
	descriptor << this->aniosGarantia << '\t';
	descriptor << this->peso << '\n';
}

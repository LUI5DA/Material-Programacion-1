#include "Electrodomestico.h"

Electrodomestico::Electrodomestico(int id, string descripcion, double precio, double iva, string marca, int garantia, double voltajes)
	:NoPerecedero::NoPerecedero(id, descripcion, precio, iva, marca, garantia)
{
	this->voltaje = voltajes;
}

Electrodomestico::~Electrodomestico()
{
}

double Electrodomestico::getVoltaje()
{
	return voltaje;
}

void Electrodomestico::setVoltaje(double v)
{
	this->voltaje = v;
}

string Electrodomestico::toString() {
	stringstream s;
	s << "--------------------------------------------------------" << endl;
	s << "Electrodomestico" << endl;
	s << NoPerecedero::toString();
	s << "Voltaje: " << this->voltaje << endl;
	s << "--------------------------------------------------------" << endl;
	return s.str();
}

Electrodomestico* Electrodomestico::read(ifstream& descriptor) {
	string id;
	string descripcion;
	string precio;
	string IVA;
	string marca;
	string garantia;
	string voltaje;
	descriptor >> id;
	descriptor >> descripcion;
	descriptor >> precio;
	descriptor >> IVA;
	descriptor >> marca;
	descriptor >> garantia;
	descriptor >> voltaje;
	int i = stoi(id);
	int g = stoi(garantia);
	stringstream pp(precio);
	stringstream ii(IVA);
	stringstream vv(voltaje);
	double ppp, iii, vvv;
	pp >> ppp;
	ii >> iii;
	vv >> vvv;
	Electrodomestico* e = new Electrodomestico(i, descripcion, ppp, iii, marca, g, vvv);
	return e;
}

void Electrodomestico::write(ofstream& descriptor) {
	descriptor << "E" << '\n';
	descriptor << this->id << '\t';
	descriptor << this->descripcion << '\t';
	descriptor << this->precio << '\t';
	descriptor << this->IVA << '\t';
	descriptor << this->marca << '\t';
	descriptor << this->aniosGarantia << '\t';
	descriptor << this->voltaje << '\n';
}
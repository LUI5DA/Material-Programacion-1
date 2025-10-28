#include "Bebida.h"

Bebida::Bebida(int id, string descripcipn, double precio , double IVA, string Marca, Fecha* f, double paz, double pal)
	:Perecedero::Perecedero(id, descripcipn, precio, IVA, Marca, f)
{
	porcentajeAzucar = paz;
	porcentajeAlcohol = pal;
}

Bebida::~Bebida()
{
}

double Bebida::getPorcentajeAzucar()
{
	return porcentajeAzucar;
}

double Bebida::getPorcentajeAlcohol()
{
	return porcentajeAlcohol;
}

void Bebida::setPorcentajeAzucar(double p)
{
	this->porcentajeAzucar = p;
}

void Bebida::setPorcentajeAlcohol(double p)
{
	this->porcentajeAlcohol = p;
}

string Bebida::toString()
{
	stringstream s;
	s << "--------------------------------------------------------" << endl;
	s << "Bebida" << endl;
	s << Perecedero::toString();
	s << "Porcentaje de azucar: " << this->porcentajeAzucar << endl;
	s << "Porcentaje de alcohol: " << this->porcentajeAlcohol << endl;
	s << "--------------------------------------------------------" << endl;
	return s.str();
}

Bebida* Bebida::read(ifstream& f)
{
	string id;
	string descripcion;
	string precio;
	string IVA;
	string marca;
	Fecha* fe = nullptr;
	string paz;
	string pal;
	f >> id;
	f >> descripcion;
	f >> precio;
	f >> IVA;
	f >> marca;
	f >> paz;
	f >> pal;
	fe = Fecha::read(f);
	int i = stoi(id);
	stringstream pp(precio);
	stringstream ii(IVA);
	stringstream ppaz(paz);
	stringstream ppal(pal);
	double ppp, iii, ppazz, ppall;
	pp >> ppp;
	ii >> iii;
	ppaz >> ppazz;
	ppal >> ppall;
	return new Bebida(i, descripcion, ppp, iii, marca, fe, ppazz, ppall);
}

void Bebida::write(ofstream& f)
{
	f << "B" << '\n';
	f << this->id << '\t';
	f << this->descripcion << '\t';
	f << this->precio << '\t';
	f << this->IVA << '\t';
	f << this->marca << '\t';
	f << this->porcentajeAzucar << '\t';
	f << this->porcentajeAlcohol <<'\t';
	this->expira->write(f);
}
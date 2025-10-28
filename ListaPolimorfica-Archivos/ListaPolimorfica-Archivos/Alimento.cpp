#include "Alimento.h"

Alimento::Alimento(int id, string des, double prec, double iv, string marc, Fecha* f, double pg) :
	Perecedero::Perecedero(id, des, prec, iv, marc, f)
{
	porcGrasa = pg;
}

Alimento::~Alimento()
{
}

double Alimento::getPorcGrasa()
{
	return this->porcGrasa;
}

void Alimento::setPorcGrasa(double p)
{
	this->porcGrasa = p;
}

string Alimento::toString() {
	stringstream s;
	s << "--------------------------------------------------------" << endl;
	s << "Alimento" << endl;
	s << Perecedero::toString();
	s << "Porcentaje de grasa: " << this->porcGrasa << endl;
	s << "--------------------------------------------------------" << endl;

	return s.str();
}

Alimento* Alimento::read(ifstream& f) {
	string id;
	string descripcion;
	string precio;
	string IVA;
	string marca;
	Fecha* fe = nullptr;
	string pg;

	f >> id;
	f >> descripcion;
	f >> precio;
	f >> IVA;
	f >> marca;
	f >> pg;

	fe = Fecha::read(f);


	int i = stoi(id);

	stringstream pp(precio);
	stringstream ii(IVA);
	stringstream ppgg(pg);

	double ppp, iii, ppg;

	pp >> ppp;
	ii >> iii;
	ppgg >> ppg;


	return new Alimento(i, descripcion, ppp, iii, marca, fe, ppg);
}


void Alimento::write(ofstream& f) {
	f << "A" << '\n';
	f << id << '\t' << descripcion << '\t' << precio << '\t' << IVA << '\t' << marca << '\t' << porcGrasa << '\t';
	expira->write(f);
}
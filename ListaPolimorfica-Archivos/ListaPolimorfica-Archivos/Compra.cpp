#include "Compra.h"
#include "PequenioMundo.h"

Compra::Compra(int id, Cliente* cliente, ListaLineas* productos)
{
	this->id = id;
	this->cliente = cliente;
	this->productos = productos;
}


Compra::~Compra()
{
	delete productos;
}

int Compra::getId()
{
	return id;
}

Cliente* Compra::getCliente()
{
	return cliente;
}

ListaLineas* Compra::getProductos()
{
	return productos;
}

void Compra::setId(int i)
{
	id = i;
}

void Compra::setCliente(Cliente* c)
{
	cliente = c;
}

void Compra::addProducto(Producto* producto, int cantidad, double descuento)
{
	productos->add(new LineaCompra(producto, cantidad, descuento));
}

string Compra::toString()
{
	stringstream s;
	s << "==================== COMPRA ====================" << endl;
	s << "ID Compra: " << id << endl;
	s << "Cliente: " << cliente->toString() << endl;
	s << "Productos: " << endl;
	s << productos->toString() << endl;
	return s.str();
}

void Compra::write(ofstream& descriptor)
{
	descriptor << id << '\t';
	descriptor << cliente->getId() << '\n';
	productos->write(descriptor);
}

Compra* Compra::read(ifstream& descriptor, ListaCliente* clientes, ListaProducto* productos)
{
	string idCliente;
	string id;
	descriptor >> id;
	descriptor >> idCliente;
	// antes de leer las compras, hay que leer los clientes y productos para poder relacionarlos
	Cliente* cliente = clientes->search(stoi(idCliente));
	ListaLineas* listaLineas = new ListaLineas();

	if(cliente == nullptr) {
		return nullptr;
	}

	while(!descriptor.eof() && descriptor.good()) {
		LineaCompra* linea = LineaCompra::read(descriptor, productos);
		if (linea) {
			listaLineas->add(linea);
		}
		else
		{
			break;
		}
		descriptor.ignore('\n'); // leer el salto de linea
	}

	return new Compra(stoi(id), cliente, listaLineas);
}




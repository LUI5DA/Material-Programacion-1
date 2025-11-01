#include "Serializer.h"
#include "Alimento.h"
#include "Bebida.h"
#include "Ropa.h"
#include "Electrodomestico.h"
#include "Herramienta.h"

void Serializer::saveData(ListaCliente* clientes, ListaProducto* productos, ListaCompras* compras)
{
    // guardar los clientes
    ofstream f("clientes.txt", ios::out); // pasamos el nombre del archivo que queremos abrir
	// si no existe lo crea
    clientes->write(f);
    f.close();

    //guardar los productos
    ofstream f2("productos.txt", ios::out);
    productos->write(f2);
    f2.close();

    //guardar compras
    ofstream f3("compras.txt", ios::out);
    compras->write(f3);
    f3.close();
}

ListaCliente* Serializer::readClientes()
{
    ifstream f("clientes.txt", ios::in);
    ListaCliente* clientes = new ListaCliente();

    if (!f.is_open()) {
        return clientes;
    }

    while (!f.eof() && f.good()) {
        Cliente* cl = Cliente::read(f);
        if (cl) {
            clientes->add(cl);
        }
        else {
            break;
        }
		f.ignore('\n'); // leer el salto de linea
    }
    return clientes;
}

ListaProducto* Serializer::readProductos()
{
    ListaProducto* productos = new ListaProducto();
    ifstream f("productos.txt", ios::in);

    if (!f.is_open() || !f.good()) {
        return productos;
    }

    while (!f.eof() && f.good()) {
        Producto* p = readProducto(f);
        if (p) {
            productos->add(p);
        }
        else {
            break;
        }
    }

    return productos;
}

Producto* Serializer::readProducto(ifstream& f)
{
    char tipo;
    f >> tipo;
    switch (tipo) {
        case 'A': return Alimento::read(f);

        case 'B': return Bebida::read(f);

        case 'R': return Ropa::read(f);

        case 'E': return Electrodomestico::read(f);

        case 'H': return Herramienta::read(f);
    }
    return nullptr;
}

ListaCompras* Serializer::readCompras(ListaCliente* clientes, ListaProducto* productos)
{
    ListaCompras* compras = new ListaCompras();
    ifstream f("compras.txt", ios::in);

    if (!f.is_open() || !f.good()) {
        return compras;
    }

    while (!f.eof() && f.good()) {
        Compra* c = Compra::read(f, clientes, productos);
        if (c) {
            compras->add(c);
        }
        else {
            break;
        }
    }
    return compras;
}

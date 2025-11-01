#include "Interfaz.h"
#include <iostream>
#include "Alimento.h"
#include "Bebida.h"
#include "Ropa.h"
#include "Electrodomestico.h"
#include "Herramienta.h"

using namespace std;

void Interfaz::mostrarMenu() {
    cout << "\n===== MENU PRINCIPAL =====" << endl;
    cout << "1. Agregar cliente" << endl;
    cout << "2. Agregar producto" << endl;
    cout << "3. Agregar compra" << endl;
    cout << "4. Mostrar clientes" << endl;
    cout << "5. Mostrar productos" << endl;
    cout << "6. Mostrar compras" << endl;
    cout << "7. Guardar datos" << endl;
    cout << "8. Mostrar productos vencidos" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int Interfaz::leerOpcion() {
    int opcion;
    cin >> opcion;
    cin.ignore();
    return opcion;
}

Cliente* Interfaz::leerCliente() {
    int id;
    string nombre;
    cout << "Ingrese ID del cliente: ";
    cin >> id;
    cin.ignore();
    cout << "Ingrese nombre del cliente: ";
    getline(cin, nombre);
    return new Cliente(id, nombre);
}

Producto* Interfaz::leerProducto() {
    cout << "\nTipo de producto:" << endl;
    cout << "1. Alimento" << endl;
    cout << "2. Bebida" << endl;
    cout << "3. Ropa" << endl;
    cout << "4. Electrodomestico" << endl;
    cout << "5. Herramienta" << endl;
    cout << "Seleccione tipo: ";

    int tipo;
    cin >> tipo;
    cin.ignore();

    int id;
    string desc, marca;
    double precio, iva;
    cout << "ID: ";
    cin >> id;
    cin.ignore();
    cout << "Descripcion: ";
    getline(cin, desc);
    cout << "Precio: ";
    cin >> precio;
    cout << "IVA: ";
    cin >> iva;
    cin.ignore();
    cout << "Marca: ";
    getline(cin, marca);

    switch (tipo) {
    case 1: {
        int d, m, a;
        double grasa;
        cout << "Fecha de vencimiento (d m a): ";
        cin >> d >> m >> a;
        cout << "Porcentaje de grasa: ";
        cin >> grasa;
        return new Alimento(id, desc, precio, iva, marca, new Fecha(d, m, a), grasa);
    }
    case 2: {
        int d, m, a;
        double azucar, alcohol;
        cout << "Fecha de vencimiento (d m a): ";
        cin >> d >> m >> a;
        cout << "Porcentaje de azucar: ";
        cin >> azucar;
        cout << "Porcentaje de alcohol: ";
        cin >> alcohol;
        return new Bebida(id, desc, precio, iva, marca, new Fecha(d, m, a), azucar, alcohol);
    }
    case 3: {
        int garantia;
        string talla;
        cout << "Anios de garantia: ";
        cin >> garantia;
        cin.ignore();
        cout << "Talla: ";
        getline(cin, talla);
        return new Ropa(id, desc, precio, iva, marca, garantia, talla);
    }
    case 4: {
        int garantia;
        double volt;
        cout << "Anios de garantia: ";
        cin >> garantia;
        cout << "Voltaje: ";
        cin >> volt;
        return new Electrodomestico(id, desc, precio, iva, marca, garantia, volt);
    }
    case 5: {
        int garantia;
        double peso;
        cout << "Anios de garantia: ";
        cin >> garantia;
        cout << "Peso: ";
        cin >> peso;
        return new Herramienta(id, desc, precio, iva, marca, garantia, peso);
    }
    default:
        cout << "Tipo no valido, creando producto generico." << endl;
        return nullptr;
    }
}

Compra* Interfaz::leerCompra(PequenioMundo* mundo) {
    int idCompra, idCliente, idProducto, cantidad;
    double descuento;

    cout << "ID de la compra: ";
    cin >> idCompra;
    cout << "ID del cliente: ";
    cin >> idCliente;
    cout << "ID del producto: ";
    cin >> idProducto;
    cout << "Cantidad: ";
    cin >> cantidad;
    cout << "Descuento (%): ";
    cin >> descuento;

    Cliente* c = mundo->getClientes()->search(idCliente);
    Producto* p = mundo->getProductos()->search(idProducto);

    if (c == nullptr || p == nullptr) {
        return nullptr;
    }

    ListaLineas* lista = new ListaLineas();
    lista->add(new LineaCompra(p, cantidad, descuento));
    return new Compra(idCompra, c, lista);
}

Fecha* Interfaz::leerFecha()
{
    int d, m, a;
    cout << "Ingrese la fecha de hoy (d m a): ";
    cin >> d >> m >> a;
    return new Fecha(d, m, a);
}

void Interfaz::mostrarMensaje(const string& msg) {
    cout << msg << endl;
}

void Interfaz::mostrarTexto(const string& texto) {
    cout << "\n" << texto << endl;
}

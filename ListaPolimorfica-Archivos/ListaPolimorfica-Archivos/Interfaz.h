#pragma once
#include <string>
#include "Cliente.h"
#include "Producto.h"
#include "Compra.h"
#include "Fecha.h"
#include "PequenioMundo.h" // para acceder a listas

class Interfaz {
public:
    void mostrarMenu();
    int leerOpcion();

    Cliente* leerCliente();
    Producto* leerProducto();
    Compra* leerCompra(PequenioMundo* mundo);
    Fecha* leerFecha();

    void mostrarMensaje(const std::string& msg);
    void mostrarTexto(const std::string& texto);
};

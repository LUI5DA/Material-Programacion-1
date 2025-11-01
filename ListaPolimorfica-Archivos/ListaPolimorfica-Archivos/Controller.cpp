#include "Controller.h"
#include <iostream>

Controller::Controller() {
    mundo = new PequenioMundo();
    ejecutando = true;
}

Controller::~Controller() {
    delete mundo;
}

void Controller::iniciar() {
    int opcion;

    while (ejecutando) {
        system("cls");
        interfaz.mostrarMenu();
        opcion = interfaz.leerOpcion();
        procesarOpcion(opcion);
        system("pause");
    }
}

void Controller::procesarOpcion(int opcion) {
    switch (opcion) {
        case 1: {
            Cliente* c = interfaz.leerCliente();
            mundo->agregarCliente(c);
            interfaz.mostrarMensaje("✅ Cliente agregado correctamente.");
            break;
        }
        case 2: {
            Producto* p = interfaz.leerProducto();
            mundo->agregarProducto(p);
            interfaz.mostrarMensaje("✅ Producto agregado correctamente.");
            break;
        }
        case 3: {
            Compra* compra = interfaz.leerCompra(mundo);
            if (compra != nullptr) {
                mundo->agregarCompra(compra);
                interfaz.mostrarMensaje("✅ Compra registrada correctamente.");
            } else {
                interfaz.mostrarMensaje("⚠️ No se pudo registrar la compra (cliente o producto no encontrado).");
            }
            break;
        }
        case 4:
            interfaz.mostrarTexto(mundo->mostrarClientes());
            break;
        case 5:
            interfaz.mostrarTexto(mundo->mostrarProductos());
            break;
        case 6:
            interfaz.mostrarTexto(mundo->mostrarCompras());
            break;
        case 7:
            mundo->guardarDatos();
            interfaz.mostrarMensaje("💾 Datos guardados correctamente.");
            break;
        case 8: {
            Fecha* f = interfaz.leerFecha();
            interfaz.mostrarTexto(mundo->mostrarProductosVencidos(f));
            delete f;
            break;
        }
        case 0:
            interfaz.mostrarMensaje("👋 Saliendo del programa...");
            ejecutando = false;
            break;
        default:
            interfaz.mostrarMensaje("❌ Opcion invalida. Intente nuevamente.");
    }
}

#include "Interfaz.h"

int Interfaz::menuPrincipal()
{
    cout << "-------------------------------------------" << endl;
    cout << "-------------- MENU PRINCIPAL--------------" << endl;
    cout << "1> Agregar una nueva mascota." << endl;
    cout << "2> Eliminar una mascota." << endl;
    cout << "3> Buscar una mascota." << endl;
    cout << "4> Mostrar todas las mascotas." << endl;
    cout << "5> Ordenar Mascotas." << endl;
    cout << "6> Salir." << endl;

    int opcion = ingresarInt(1, 6);

    return opcion;
}

int Interfaz::ingresarInt(int min, int max)
{
    bool correcto = false;
    int opcion;
    do {
        cout << "ingrese un valor entre " << min << " y " << max << endl;
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
        }
        else if (opcion < min) {
            cout << "El valor ingresado esta por debajo del minimo" << min <<endl;
        }
        else if (opcion > max) {
            cout << "El valor ingresado esta por encima del maximo" << max << endl;
        }
        else {
            correcto = true;
        }
    } while (!correcto);

    return opcion;
}

int Interfaz::ingresarIntPositivo()
{
    bool correcto = false;
    int opcion;
    do {
        cout << "ingrese un valor positivo" << endl;
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
        }
        else if (opcion < 0) {
            cout << "El valor ingresado es negativo, debe ser positivo" << endl;
        }
        else {
            correcto = true;
        }
    } while (!correcto);

    return opcion;
}

Mascota* Interfaz::crearMascota()
{
    int edad;
    string id;
    string nombre;
    string especie;

    cout << "-------------------------------------------" << endl;
    cout << "-----------CREANDO UNA MASCOTA-------------" << endl;

    cout << "ingrese la edad del animal" << endl;
    edad = ingresarIntPositivo();


    cout << "ingrese la identificacion del animal" << endl;
    cin >> id;

    cout << "ingrese el nombre del animal" << endl;
    cin >> nombre;

    cout << "ingrese la especie del animal" << endl;
    cin >> especie;

    return new Mascota(edad, id, nombre, especie);
}

void Interfaz::imprimirMensaje(string m)
{
    cout << endl;
    cout << m << endl;
}

#pragma once
#include "PequenioMundo.h"
#include "Interfaz.h"

class Controller {
private:
    PequenioMundo* mundo;
    Interfaz interfaz;
    bool ejecutando;

public:
    Controller();
    ~Controller();

    void iniciar();
    void procesarOpcion(int opcion);
};

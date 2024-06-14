#ifndef NODOLIST_H
#define NODOLIST_H
#include "CargaPasajeros.h"

class Nodo {
public:
    Pasajero dato;
    Nodo* siguiente;

    Nodo(Pasajero dato) {
        this->dato = dato;
        this->siguiente = nullptr;
    }
};

#endif // NODOLIST_H
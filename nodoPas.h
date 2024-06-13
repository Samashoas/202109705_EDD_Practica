//
// Created by jpsam on 13/06/2024.
//

#ifndef NODOPAS_H
#define NODOPAS_H
#include <iostream>
#include "CargaPasajeros.h"
using namespace std;

class NodoPas {
public:
    Pasajero dato;
    NodoPas* siguiente;

    NodoPas(Pasajero dato) : dato(dato), siguiente(nullptr) {}
};

#endif //NODOPAS_H

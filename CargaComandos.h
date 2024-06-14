//
// Created by jpsam on 13/06/2024.
//

#ifndef CARGACOMANDOS_H
#define CARGACOMANDOS_H
#include "CargaPasajeros.h"
#include "PilaEquipaje.h"
#include "ListaED.h"

class CargaComandos {
public:
    Pila<Pasajero> pilaPasajeros;
    CargaComandos(CargaPasajeros& cargaPasajeros);
    void LeerComandos();

private:
    ListaDoble<Pasajero> listaPasajeros;
    CargaPasajeros& cargaPasajeros;
};



#endif //CARGACOMANDOS_H

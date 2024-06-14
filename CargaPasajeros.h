//
// Created by jpsam on 13/06/2024.
//

#ifndef CARGAPASAJEROS_H
#define CARGAPASAJEROS_H
#include <string>
#include <nlohmann/json.hpp>
#include "MiVector.h"


struct Pasajero {
    std::string nombre;
    std::string nacionalidad;
    std::string numero_de_pasaporte;
    std::string vuelo;
    int asiento;
    std::string destino;
    std::string origen;
    int equipaje_facturado;
};

std::ostream& operator<<(std::ostream& os, const Pasajero& pasajero);

class CargaPasajeros {
public:
    CargaPasajeros();
    ~CargaPasajeros();
    void cargarDesdeArchivo(std::string nombre_archivo);
    static void OpcionesPasajeros();
    void addPasajero(const Pasajero& pasajero);
    Pasajero deletePasajero();
    void reportesVis();
    static void reportesVueloNormal();
    static void reportesVueloAsiento();
    static void reportesVueloNum();
    bool estaVacia();
private:
    MiVector<Pasajero> pasajeros;
};



#endif //CARGAPASAJEROS_H

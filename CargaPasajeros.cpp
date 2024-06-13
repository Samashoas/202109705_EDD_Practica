//
// Created by jpsam on 13/06/2024.
//

#include "CargaPasajeros.h"
#include <fstream>
#include <iostream>

using nlohmann::json;

CargaPasajeros::CargaPasajeros() {
    // Constructor implementation
}

CargaPasajeros::~CargaPasajeros() {
    // Destructor implementation
}

void CargaPasajeros::cargarDesdeArchivo(std::string nombre_archivo) {
    std::ifstream archivo(nombre_archivo);
    if(!archivo.is_open()){
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return;
    }

    json j;
    archivo >> j;

    for (const auto& item : j) {
        Pasajero pasajero;
        pasajero.nombre = item["nombre"];
        pasajero.nacionalidad = item["nacionalidad"];
        pasajero.numero_de_pasaporte = item["numero_de_pasaporte"];
        pasajero.vuelo = item["vuelo"];
        pasajero.asiento = item["asiento"];
        pasajero.destino = item["destino"];
        pasajero.origen = item["origen"];
        pasajero.equipaje_facturado = item["equipaje_facturado"];

        addPasajero(pasajero);
    }
}

void CargaPasajeros::OpcionesPasajeros() {
    std::string nombre_archivo;
    std::cout << "Ingrese el nombre del archivo: ";
    std::cin >> nombre_archivo;

    CargaPasajeros instancia;
    instancia.cargarDesdeArchivo(nombre_archivo);

    for (size_t i = 0; i < instancia.pasajeros.get_size(); i++) {
        Pasajero& pasajero = instancia.pasajeros[i];
        std::cout << "--------------------------------" << std::endl;
        std::cout << "nombre: " << pasajero.nombre << std::endl;
        std::cout << "nacionalidad: " << pasajero.nacionalidad << std::endl;
        std::cout << "Num. de pasaporte: " << pasajero.numero_de_pasaporte << std::endl;
        std::cout << "vuelo: " << pasajero.vuelo << std::endl;
        std::cout << "Asiento: " << pasajero.asiento << std::endl;
        std::cout << "destino: " << pasajero.destino << std::endl;
        std::cout << "Origen: " << pasajero.origen << std::endl;
        std::cout << "Equipaje Fac.: " << pasajero.equipaje_facturado << std::endl;
        std::cout << "--------------------------------" << std::endl;
    }
}

void CargaPasajeros::addPasajero(const Pasajero& pasajero) {
    pasajeros.push_back(pasajero);
}
//
// Created by jpsam on 13/06/2024.
//

#include "CargaComandos.h"
#include <fstream>
#include <iostream>

CargaComandos::CargaComandos(CargaPasajeros& cargaPasajeros) : cargaPasajeros(cargaPasajeros) {}

void CargaComandos::LeerComandos() {
    std::string nombre_archivo;
    std::cout << "Ingrese el nombre del archivo: ";
    std::cin >> nombre_archivo;

    std::ifstream archivo(nombre_archivo);
    if(!archivo.is_open()){
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::cout << linea << std::endl;
        if(linea == "IngresoEquipajes;") {
                Pasajero pasajero = cargaPasajeros.deletePasajero();
                std::cout << "Salio de la cola: "<< pasajero.nombre << std::endl;
                std::cout << " " << std::endl;
        }
    }
    cargaPasajeros.reportesVis();
    std::cout << " " << std::endl;
}
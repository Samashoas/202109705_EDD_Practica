//
// Created by jpsam on 13/06/2024.
//

#include "CargaComandos.h"
#include <fstream>
#include <iostream>
#include "PilaEquipaje.h"

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
            listaPasajeros.insertarFinal(pasajero);
            std::cout << "Entro en la lista: "<< pasajero.nombre << std::endl;
            if(pasajero.equipaje_facturado !=0) {
                pilaPasajeros.push(pasajero);
                std::cout << "Entro a la pila: "<< pasajero.equipaje_facturado << std::endl;
                std::cout << " " << std::endl;
            }
        }
    }
    std::cout << "Reporte normal: " << std::endl;
    listaPasajeros.ReporteLD(); //reporte normal
    std::cout << "Reporte ordenado: " << std::endl;
    listaPasajeros.ordenarPorVuelo(); // ordenar la lista
    listaPasajeros.ReporteLD(); // reporte ordenado
    pilaPasajeros.toGraphviz();
    cargaPasajeros.reportesVis();
    std::cout << " " << std::endl;
}
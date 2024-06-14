//
// Created by jpsam on 13/06/2024.
//

#include "CargaPasajeros.h"
#include <fstream>
#include <iostream>
#include "ColaPas.h"
#include "ListaPas.h"

using nlohmann::json;

CargaPasajeros::CargaPasajeros() {
    // Constructor implementation
}

CargaPasajeros::~CargaPasajeros() {
    // Destructor implementation
}

Cola colapas;
ListaSimple list;

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


        list.insertarInicio(pasajero);
        list.visualizarLista();

        colapas.enqueue(pasajero);
        colapas.visualizarPasajero(pasajero);
        std::cout << "Pasajero ingresado a la cola" << std::endl;
        addPasajero(pasajero);
    }

    //list.ordenarPorAsiento();
    //list.ordenarPorVuelo();
    list.ReporteList();


    colapas.reporte();
    std::cout << " " << std::endl;
    std::cout << "*********************************" << std::endl;
}

void CargaPasajeros::OpcionesPasajeros() {
    std::string nombre_archivo;
    std::cout << "Ingrese el nombre del archivo: ";
    std::cin >> nombre_archivo;

    CargaPasajeros instancia;
    instancia.cargarDesdeArchivo(nombre_archivo);

    for (size_t i = 0; i < instancia.pasajeros.get_size(); i++) {
        Pasajero& pasajero = instancia.pasajeros[i];
        std::cout << " " << std::endl;
        std::cout << "------Pasajeros registrados------" << std::endl;
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


Pasajero CargaPasajeros::deletePasajero() {
    if (!colapas.estaVacia()) {
        Pasajero pasajero = colapas.obtenerFrente();
        colapas.deque();
        return pasajero;
    } else {
        std::cout << "No hay pasajeros en la cola." << std::endl;
        return Pasajero(); // Devuelve un pasajero vacío si la cola está vacía
    }
}

bool CargaPasajeros::estaVacia() {
    return colapas.estaVacia();
}

void CargaPasajeros::reportesVis() {
    colapas.reporte();
}

void CargaPasajeros::reportesVueloNormal() {
    list.ReporteList();
}

void CargaPasajeros::reportesVueloAsiento() {
    list.ordenarPorAsiento();
    list.ReporteList();
}

void CargaPasajeros::reportesVueloNum() {
    list.ordenarPorVuelo();
    list.ReporteList();
}

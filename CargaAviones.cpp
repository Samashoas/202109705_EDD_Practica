#include "CargaAviones.h"
#include <fstream>
#include <iostream>

using nlohmann::json;

CargaAviones::CargaAviones() {
    // Constructor implementation
}

CargaAviones::~CargaAviones() {
    // Destructor implementation
}

void CargaAviones::cargarDesdeArchivo(std::string nombre_archivo) {
    std::ifstream archivo(nombre_archivo);
    if(!archivo.is_open()){
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return;
    }

    json j;
    archivo >> j;

    for (const auto& item : j) {
        Avion avion;
        avion.vuelo = item["vuelo"];
        avion.numero_de_registro = item["numero_de_registro"];
        avion.modelo = item["modelo"];
        avion.fabricante = item["fabricante"];
        avion.ano_fabricacion = item["ano_fabricacion"];
        avion.capacidad = item["capacidad"];
        avion.peso_max_despegue = item["peso_max_despegue"];
        avion.aerolinea = item["aerolinea"];
        avion.estado = item["estado"];

        addAvion(avion);
    }
}

void CargaAviones::OpcionesAviones() {
    std::string nombre_archivo;
    std::cout << "Ingrese el nombre del archivo: ";
    std::cin >> nombre_archivo;

    CargaAviones instancia;
    instancia.cargarDesdeArchivo(nombre_archivo);

    for (size_t i = 0; i < instancia.aviones.get_size(); i++) {
        Avion& avion = instancia.aviones[i];
        std::cout << "--------------------------------" << std::endl;
        std::cout << "Vuelo: " << avion.vuelo << std::endl;
        std::cout << "Numero de registro: " << avion.numero_de_registro << std::endl;
        std::cout << "Modelo: " << avion.modelo << std::endl;
        std::cout << "Fabricante: " << avion.fabricante << std::endl;
        std::cout << "Ano de fabricacion: " << avion.ano_fabricacion << std::endl;
        std::cout << "Capacidad: " << avion.capacidad << std::endl;
        std::cout << "Peso maximo de despegue: " << avion.peso_max_despegue << std::endl;
        std::cout << "Aerolinea: " << avion.aerolinea << std::endl;
        std::cout << "Estado: " << avion.estado << std::endl;
        std::cout << "--------------------------------" << std::endl;
    }
}

void CargaAviones::addAvion(const Avion& avion) {
    aviones.push_back(avion);
}
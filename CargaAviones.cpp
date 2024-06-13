//
// Created by jpsam on 12/06/2024.
//

#include "CargaAviones.h"
#include <fstream>
#include <iostream>

std::vector<Avion> CargaAviones::cargarDesdeArchivo(std::string nombre_archivo) {
    std::ifstream archivo(nombre_archivo);
    if(!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo " << nombre_archivo << std::endl;
        return {};
    }

    nlohmann::json j;
    archivo >> j;

    std::vector<Avion> aviones;
    for(const auto& item : j) {
        Avion avion;
        if (item.contains("vuelo")) avion.vuelo = item["vuelo"].get<std::string>();
        if (item.contains("numero_de_registro")) avion.numero_de_registro = item["numero_de_registro"].get<std::string>();
        if (item.contains("modelo")) avion.modelo = item["modelo"].get<std::string>();
        if (item.contains("fabricante")) avion.fabricante = item["fabricante"].get<std::string>();
        if (item.contains("ano_fabricacion")) avion.ano_fabricacion = item["ano_fabricacion"].get<int>();
        if (item.contains("capacidad")) avion.capacidad = item["capacidad"].get<int>();
        if (item.contains("peso_max_despegue")) avion.peso_max_despegue = item["peso_max_despegue"].get<int>();
        if (item.contains("aerolinea")) avion.aerolinea = item["aerolinea"].get<std::string>();
        if (item.contains("estado")) avion.estado = item["estado"].get<std::string>();

        aviones.push_back(avion);
    }

    return aviones;
}

void CargaAviones::OpcionesAviones() {
    std::string nombre_archivo;
    std::cout << "Ingrese el nombre del archivo: ";
    std::cin >> nombre_archivo;

    std::vector<Avion> aviones = cargarDesdeArchivo(nombre_archivo);

    if(aviones.empty()) {
        std::cout << "No se cargaron aviones" << std::endl;
    }else {
        for(const auto& avion : aviones) {
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
}


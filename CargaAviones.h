//
// Created by jpsam on 12/06/2024.
//

#ifndef CARGAAVIONES_H
#define CARGAAVIONES_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

struct Avion {
    std::string vuelo;
    std::string numero_de_registro;
    std::string modelo;
    std::string fabricante;
    int ano_fabricacion;
    int capacidad;
    int peso_max_despegue;
    std::string aerolinea;
    std::string estado;
};

class CargaAviones {
public:
    static std::vector<Avion> cargarDesdeArchivo(std::string nombre_archivo);
    static void OpcionesAviones();
};

#endif //CARGAAVIONES_H

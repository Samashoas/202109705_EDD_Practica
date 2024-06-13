//
// Created by jpsam on 13/06/2024.
//

#ifndef COLAPAS_H
#define COLAPAS_H
#include "nodoPas.h"

class Cola {
private:
    NodoPas * frente;
    NodoPas* final;

public:
    Cola() : frente(nullptr), final(nullptr) {}

    void enqueue(Pasajero dato) {
        NodoPas* nuevoNodo = new NodoPas(dato);

        if(frente == nullptr){
            frente = nuevoNodo;
            final = nuevoNodo;
        } else {
            final->siguiente = nuevoNodo;
            final = nuevoNodo;
        }
    }

    void deque() {
        if(frente != nullptr){
            NodoPas* temp = frente;
            frente = frente->siguiente;
            delete temp;

            if(frente == nullptr) {
                final = nullptr;
            }
        }
    }

    Pasajero obtenerFrente() {
        if(frente != nullptr){
            return frente->dato;
        } else {
            std::cout << "La cola esta vacia" << std::endl;
        }
    }

    void visualizarPasajero(const Pasajero& pasajero) {
        std::cout << " " << std::endl;
        std::cout << "------Pasajero de cola-----------" << std::endl;
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

    bool estaVacia() {
        return frente == nullptr;
    }
};
#endif //COLAPAS_H

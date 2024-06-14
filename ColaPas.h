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
            return Pasajero(); // Devuelve un pasajero vacío si la cola está vacía
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

    void reporte() {
        std::ofstream file("ColaPasajeros.dot");
        if (!file.is_open()) {
            std::cout << "No se pudo abrir el archivo de reporte" << std::endl;
            return;
        }

        file << "digraph G {\n";
        file << "rankdir=LR;\n";
        file << "node [shape = none];\n";

        NodoPas* temp = frente;
        int i = 0;
        while (temp != nullptr) {
            file << "node" << i << " [label = <<table border=\"0\" cellborder=\"1\" cellspacing=\"0\">\n";
            file << "<tr><td>Nombre:</td><td>" << temp->dato.nombre << "</td></tr>\n";
            file << "<tr><td>Nacionalidad:</td><td>" << temp->dato.nacionalidad << "</td></tr>\n";
            file << "<tr><td>Num. de pasaporte:</td><td>" << temp->dato.numero_de_pasaporte << "</td></tr>\n";
            file << "<tr><td>Vuelo:</td><td>" << temp->dato.vuelo << "</td></tr>\n";
            file << "<tr><td>Asiento:</td><td>" << temp->dato.asiento << "</td></tr>\n";
            file << "<tr><td>Destino:</td><td>" << temp->dato.destino << "</td></tr>\n";
            file << "<tr><td>Origen:</td><td>" << temp->dato.origen << "</td></tr>\n";
            file << "<tr><td>Equipaje Fac.:</td><td>" << temp->dato.equipaje_facturado << "</td></tr>\n";
            file << "</table>>];\n";
            if (temp->siguiente != nullptr) {
                file << "\"node" << i+1 << "\" -> \"node" << i << "\";\n";
            }
            temp = temp->siguiente;
            i++;
        }

        file << "}";
        file.close();

        // Call Graphviz to generate the image
        int result = system("dot -Tpng ColaPasajeros.dot -o ColaPasajeros.png");
        if (result == -1) {
            std::cerr << "Failed to execute command: dot -Tpng ColaPasajeros.dot -o ColaPasajeros.png" << std::endl;
            return;
        }

        result = system("start ColaPasajeros.png");
        if (result == -1) {
            std::cerr << "Failed to execute command: start ColaPasajeros.png" << std::endl;
            return;
        }
    }

    bool estaVacia() {
        return frente == nullptr;
    }
};
#endif //COLAPAS_H

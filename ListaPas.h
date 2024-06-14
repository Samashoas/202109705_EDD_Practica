//
// Created by jpsam on 13/06/2024.
//

#ifndef LISTAPAS_H
#define LISTAPAS_H
#include <iostream>
using namespace std;
#include "NodoList.h"

class ListaSimple {
public:
    Nodo* primero;

    ListaSimple() {
        primero = nullptr;
    }

    void insertarInicio(Pasajero dato) {
        Nodo* nuevo = new Nodo(dato);
        nuevo->siguiente = primero;
        primero = nuevo;
    }

    void eliminarInicio() {
        if (primero != nullptr) {
            Nodo* temp = primero;
            primero = primero->siguiente;
            delete temp;
        }
    }

    void visualizarLista() {
        Nodo* temp = primero;
        while (temp != nullptr) {
            std::cout << "-------Ingreso Lista--------" << std::endl;
            std::cout << "Nombre: " << temp->dato.nombre << std::endl;
            std::cout << "Nacionalidad: " << temp->dato.nacionalidad << std::endl;
            std::cout << "Número de Pasaporte: " << temp->dato.numero_de_pasaporte << std::endl;
            std::cout << "Vuelo: " << temp->dato.vuelo << std::endl;
            std::cout << "Asiento: " << temp->dato.asiento << std::endl;
            std::cout << "Destino: " << temp->dato.destino << std::endl;
            std::cout << "Origen: " << temp->dato.origen << std::endl;
            std::cout << "Equipaje Facturado: " << temp->dato.equipaje_facturado << std::endl;
            std::cout << "-----Registrado en Lista------" << std::endl;
            std::cout << " " << std::endl;
            temp = temp->siguiente;
        }
    }

    void ordenarPorVuelo() {
        if (primero == nullptr || primero->siguiente == nullptr) {
            return;
        }

        Nodo* sorted = nullptr;
        Nodo* current = primero;

        while (current != nullptr) {
            Nodo* next = current->siguiente;
            if (sorted == nullptr || current->dato.vuelo < sorted->dato.vuelo) {
                current->siguiente = sorted;
                sorted = current;
            } else {
                Nodo* temp = sorted;
                while (temp->siguiente != nullptr && temp->siguiente->dato.vuelo < current->dato.vuelo) {
                    temp = temp->siguiente;
                }
                current->siguiente = temp->siguiente;
                temp->siguiente = current;
            }
            current = next;
        }
        primero = sorted;
    }

    void ordenarPorAsiento() {
        if (primero == nullptr || primero->siguiente == nullptr) {
            return;
        }

        Nodo* sorted = nullptr;
        Nodo* current = primero;

        while (current != nullptr) {
            Nodo* next = current->siguiente;
            if (sorted == nullptr || current->dato.asiento < sorted->dato.asiento) {
                current->siguiente = sorted;
                sorted = current;
            } else {
                Nodo* temp = sorted;
                while (temp->siguiente != nullptr && temp->siguiente->dato.asiento < current->dato.asiento) {
                    temp = temp->siguiente;
                }
                current->siguiente = temp->siguiente;
                temp->siguiente = current;
            }
            current = next;
        }
        primero = sorted;
    }

    void ReporteList() {
        std::ofstream archivo("lista.dot");
        if (!archivo.is_open()) {
            std::cout << "No se pudo abrir el archivo" << std::endl;
            return;
        }

        archivo << "digraph G {\n";
        archivo << "rankdir=LR;\n";
        archivo << "node [shape=record];\n";

        Nodo* temp = primero;
        int i = 0;
        while (temp != nullptr) {
            archivo << "node" << i << " [label=\"{<data> " << temp->dato.nombre << " | <next> }\"];\n";
            if (temp->siguiente != nullptr) {
                archivo << "node" << i << ":next:c -> node" << i+1 << ":data;\n";
            }
            temp = temp->siguiente;
            i++;
        }

        archivo <<  "}";
        archivo.close();

        // Ahora puedes generar la imagen con el comando: dot -Tpng lista.dot -o lista.png
        int result = system("dot -Tpng lista.dot -o lista.png");
        if (result == -1) {
            std::cerr << "Failed to execute command: dot -Tpng lista.dot -o lista.png" << std::endl;
            return;
        }

        result = system("start lista.png");
        if (result == -1) {
            std::cerr << "Failed to execute command: start lista.png" << std::endl;
            return;
        }
    }
};
#endif //LISTAPAS_H

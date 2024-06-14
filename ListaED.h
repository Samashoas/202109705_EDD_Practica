#ifndef LISTAED_H
#define LISTAED_H

#include <fstream>
#include <sstream>
#include <stdexcept>

template<typename T>
class Nodo {
public:
    T dato;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(T dato) : dato(dato), siguiente(nullptr), anterior(nullptr) {}
};

template<typename T>
class ListaDoble {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;

public:
    ListaDoble() : cabeza(nullptr), cola(nullptr) {}

    void insertarInicio(T dato) {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        if (cabeza == nullptr) {
            cabeza = cola = nuevo;
        } else {
            nuevo->siguiente = cabeza;
            cabeza->anterior = nuevo;
            cabeza = nuevo;
        }
    }

    void insertarFinal(T dato) {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        if (cabeza == nullptr) {
            cabeza = cola = nuevo;
        } else {
            nuevo->anterior = cola;
            cola->siguiente = nuevo;
            cola = nuevo;
        }
    }

    void ordenarPorVuelo() {
        if (cabeza == nullptr || cabeza->siguiente == nullptr) {
            return;  // La lista está vacía o solo tiene un elemento, por lo que ya está ordenada
        }

        Nodo<T>* i = cabeza->siguiente;
        while (i != nullptr) {
            T dato = i->dato;
            Nodo<T>* j = i->anterior;

            // Mover los elementos de la lista que son mayores que 'dato' una posición adelante
            while (j != nullptr && j->dato.vuelo > dato.vuelo) {
                j->siguiente->dato = j->dato;
                j = j->anterior;
            }

            // Insertar 'dato' en la posición correcta
            if (j == nullptr) {
                cabeza->dato = dato;
            } else {
                j->siguiente->dato = dato;
            }

            i = i->siguiente;
        }
    }

    void eliminarInicio() {
        if (cabeza != nullptr) {
            Nodo<T>* nodoEliminado = cabeza;
            cabeza = cabeza->siguiente;
            if (cabeza != nullptr) {
                cabeza->anterior = nullptr;
            } else {
                cola = nullptr;
            }
            delete nodoEliminado;
        }
    }

    void eliminarFinal() {
        if (cola != nullptr) {
            Nodo<T>* nodoEliminado = cola;
            cola = cola->anterior;
            if (cola != nullptr) {
                cola->siguiente = nullptr;
            } else {
                cabeza = nullptr;
            }
            delete nodoEliminado;
        }
    }

    bool estaVacia() {
        return cabeza == nullptr;
    }

    void ReporteLD() {
        std::ofstream file("ListaDoble.dot");
        if (!file.is_open()) {
            throw std::runtime_error("No se puede abrir el archivo");
        }

        file << "digraph G {\n";
        file << "  rankdir=LR;\n";  // Para que los nodos estén en una línea horizontal

        Nodo<T>* actual = cabeza;
        int nodeId = 0;
        std::ostringstream nodes;
        std::ostringstream edges;

        while (actual != nullptr) {
            nodes << "  node" << nodeId << " [label=\"" << actual->dato << "\"];\n";
            if (actual->siguiente != nullptr) {
                edges << "  node" << nodeId << " -> node" << (nodeId + 1) << ";\n";
                edges << "  node" << (nodeId + 1) << " -> node" << nodeId << ";\n";
            }
            actual = actual->siguiente;
            ++nodeId;
        }

        file << nodes.str();
        file << edges.str();
        file << "}\n";
        file.close();

        // Generar la imagen utilizando Graphviz
        system("dot -Tpng ListaDoble.dot -o ListaDoble.png");
        system("start ListaDoble.png");
    }

    ~ListaDoble() {
        while (cabeza != nullptr) {
            eliminarInicio();
        }
    }
};

#endif //LISTAED_H
#ifndef PILAEQUIPAJE_H
#define PILAEQUIPAJE_H
#include <iostream>
#include <fstream>
#include <sstream>

template<typename T>
std::string toString(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

template<typename T>
class NodoPila {
public:
    T dato;
    NodoPila* siguiente;

    NodoPila(T dato) : dato(dato), siguiente(nullptr) {}
};

template<typename T>
class Pila {
private:
    NodoPila<T>* tope;

public:
    Pila() : tope(nullptr) {}

    void push(T dato) {
        NodoPila<T>* nuevo = new NodoPila<T>(dato);
        nuevo->siguiente = tope;
        tope = nuevo;
    }

    void pop() {
        if (tope != nullptr) {
            NodoPila<T>* nodoEliminado = tope;
            tope = tope->siguiente;
            delete nodoEliminado;
        }
    }

    T peek() {
        if (tope != nullptr) {
            return tope->dato;
        } else {
            throw std::out_of_range("La pila está vacía");
        }
    }

    bool estaVacia() {
        return tope == nullptr;
    }

    ~Pila() {
        while (tope != nullptr) {
            pop();
        }
    }

    void toGraphviz() {
        std::ofstream file("PilaE.dot");
        if (!file.is_open()) {
            throw std::runtime_error("No se puede abrir el archivo");
        }

        file << "digraph G {\n";
        file << "  rankdir=TB;\n";  // Para que los nodos estén en una línea horizontal

        NodoPila<T>* actual = tope;
        int nodeId = 0;
        std::ostringstream nodes;
        std::ostringstream edges;

        while (actual != nullptr) {
            nodes << "  node" << nodeId << " [label=\"" << toString(actual->dato) << "\"];\n";
            if (actual->siguiente != nullptr) {
                edges << "  node" << nodeId << " -> node" << (nodeId + 1) << ";\n";
            }
            actual = actual->siguiente;
            ++nodeId;
        }

        file << nodes.str();
        file << edges.str();
        file << "}\n";
        file.close();

        // Generar la imagen utilizando Graphviz
        system("dot -Tpng PilaE.dot -o PilaE.png");
        system("start PilaE.png");
    }
};

#endif //PILAEQUIPAJE_H
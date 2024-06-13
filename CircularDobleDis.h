//
// Created by jpsam on 13/06/2024.
//

#ifndef CIRCULARDOBLEDIS_H
#define CIRCULARDOBLEDIS_H
class ListaCircular
{
private:
    Nodo* primero;
    Nodo* ultimo;
public:
    ListaCircular();
    bool estaVacia();
    void insertarInicio(int dato);
    void insertarFinal(int dato);
    void eliminarInicio();
    void eliminarFinal();
    void visualizarLista();
    void generarReporte();
    ~ListaCircular();
};

ListaCircular::ListaCircular()
{
    primero = nullptr;
    ultimo = nullptr;
}

bool ListaCircular::estaVacia()
{
    return (primero == nullptr) && (ultimo == nullptr);
}

void ListaCircular::insertarInicio(int dato)
{
    Nodo *nuevo = new Nodo(dato);
    if (estaVacia())
    {
        nuevo->setSiguiente(nuevo);
        nuevo->setAnterior(nuevo);
        primero = ultimo = nuevo;
    }
    else
    {
        nuevo->setSiguiente(primero);
        nuevo->setAnterior(ultimo);
        primero->setAnterior(nuevo);
        ultimo->setSiguiente(nuevo);
        primero = nuevo;
    }
}

void ListaCircular::insertarFinal(int dato)
{
    Nodo *nuevo = new Nodo(dato);
    if (estaVacia())
    {
        nuevo->setSiguiente(nuevo);
        nuevo->setAnterior(nuevo);
        primero = ultimo = nuevo;
    }
    else
    {
        nuevo->setSiguiente(primero);
        nuevo->setAnterior(ultimo);
        primero->setAnterior(nuevo);
        ultimo->setSiguiente(nuevo);
        ultimo = nuevo;
    }
}

void ListaCircular::eliminarInicio()
{
    if (estaVacia())
    {
        cout << "La lista está vacía" << endl;
    }
    else
    {
        if (primero == ultimo)
        {
            delete primero;
            primero = ultimo = nullptr;
        }
        else
        {
            Nodo *segundo = primero->getSiguiente();
            segundo->setAnterior(ultimo);
            ultimo->setSiguiente(segundo);
            delete primero;
            primero = segundo;
        }
    }
}

void ListaCircular::eliminarFinal()
{
    if (estaVacia())
    {
        cout << "La lista está vacía" << endl;
    }
    else
    {
        if (primero == ultimo)
        {
            delete primero;
            primero = ultimo = nullptr;
        }
        else
        {
            Nodo *temporal = primero;
            while (temporal->getSiguiente() != ultimo)
            {
                temporal = temporal->getSiguiente();
            }
            temporal->setSiguiente(primero);
            primero->setAnterior(temporal);
            delete ultimo;
            ultimo = temporal;
        }
    }
}

void ListaCircular::visualizarLista()
{
    if (estaVacia())
    {
        cout << "La lista está vacía\n" << endl;
    }
    else
    {
        int nodoDato;
        Nodo *actual = primero;
        do
        {
            nodoDato = actual->getDato();
            cout << nodoDato << endl;
            actual = actual->getSiguiente();
        } while (actual != primero);
    }
}
void ListaCircular::generarReporte(){
    if (estaVacia()){
        cout << "La lista está vacía\n" << endl;
    }
    else
    {
        ofstream archivo;
        archivo.open("grafica_LC.dot", ios::out);
        archivo << "digraph G { rankdir = LR; " << endl;

        int nodoDato;
        Nodo *actual = primero;
        do
        {
            nodoDato = actual->getDato();
            archivo << nodoDato;
            archivo << " -> ";
            actual = actual->getSiguiente();
            if (actual == primero)
            {
                archivo << actual->getDato();
            }

        } while (actual != primero);

        archivo << "; }";
        archivo.close();
        system("dot -Tpng grafica_LC.dot -o grafica_LC.png");
        system("start grafica_LC.png");
    }
}

ListaCircular::~ListaCircular()
{
    while (!estaVacia()) {
        eliminarInicio();
    }
}

// ... Resto de los métodos ...
#endif //CIRCULARDOBLEDIS_H

#include <iostream>
#include "CargaAviones.h"
#include "CargaPasajeros.h"
#include "CargaComandos.h"
using  namespace std;


void opcion1() {
    CargaAviones::OpcionesAviones();
}

void opcion2() {
    CargaPasajeros::OpcionesPasajeros();
}

void opcion3() {
    CargaPasajeros cargaPasajeros;
    CargaComandos cargaComandos(cargaPasajeros);
    cargaComandos.LeerComandos();
}

void opcion4() {
    std::cout << "Opcion 4" << std::endl;
}

void opcion5() {
    int subOpcion;
    bool regresar = false;

    while(!regresar){
        std::cout << "*------Submenu de reportes-----*" << std::endl;
        std::cout << "| 1. Reporte de vuelo normal   |" << std::endl;
        std::cout << "* 2. Reporte de vuelo por asiento *" << std::endl;
        std::cout << "| 3. Reporte de vuelo por numero  |" << std::endl;
        std::cout << "*-------- 4. Regresar --------*" << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> subOpcion;

        switch (subOpcion){
            case 1:
                CargaPasajeros::reportesVueloNormal();
            break;
            case 2:
                CargaPasajeros::reportesVueloAsiento();
            break;
            case 3:
                CargaPasajeros::reportesVueloNum();
            break;
            case 4:
                std::cout << "Regresando al menu principal..." << std::endl;
            regresar = true;
            break;
            default:
                std::cout << "Opcion no valida" << std::endl;
            break;
        }
        if(!regresar){
            std::cout << "Presione Enter para continuar...";
            std::cin.ignore();
            std::cin.get();
        }
    }
}

int main() {
    int opcion;
    bool salir = false;

    while(!salir){

        cout << "*------Menu principal-----*" << endl;
        cout << "| 1. Carga de aviones     |" << endl;
        cout << "* 2. Carga de pasajeros   *" << endl;
        cout << "| 3. Carga de movimientos |" << endl;
        cout << "* 4. Consultar pasajeros  *" << endl;
        cout << "| 5. Visualizar pasajeros |" << endl;
        cout << "*-------- 6.Salir --------*" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion){
            case 1:
                opcion1();
            break;
            case 2:
                opcion2();
            break;
            case 3:
                opcion3();
            break;
            case 4:
                opcion4();
            break;
            case 5:
                opcion5();
            break;
            case 6:
                cout << "Adios!" << endl;
                salir = true;
            break;
            default:
                cout << "Opcion no valida" << endl;
            break;
        }

        if(!salir){
            cout << "Presione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    }
    return 0;
}
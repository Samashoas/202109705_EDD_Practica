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
                cout << "Opcion 5" << endl;
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
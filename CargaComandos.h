//
// Created by jpsam on 13/06/2024.
//

#ifndef CARGACOMANDOS_H
#define CARGACOMANDOS_H
#include "CargaPasajeros.h"

class CargaComandos {
public:
    CargaComandos(CargaPasajeros& cargaPasajeros);
    void LeerComandos();

private:
    CargaPasajeros& cargaPasajeros;
};



#endif //CARGACOMANDOS_H

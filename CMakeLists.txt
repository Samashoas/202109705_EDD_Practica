cmake_minimum_required(VERSION 3.28)
project(202109705_EDD_Practica)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
fetchcontent_declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.10.5
)
fetchcontent_makeavailable(json)

add_executable(202109705_EDD_Practica main.cpp
        CargaAviones.cpp
        CargaAviones.h
        MiVector.h
        MyArrasy.h
        CargaPasajeros.cpp
        CargaPasajeros.h
        nodoAv.h
        CircularDobleDis.h
        CircularDobleMan.h
        nodoPas.h
        ColaPas.h
        CargaComandos.cpp
        CargaComandos.h
        ListaPas.h
        nodoList.h
        PilaEquipaje.h
        ListaED.h
)
target_link_libraries(202109705_EDD_Practica PRIVATE nlohmann_json::nlohmann_json)
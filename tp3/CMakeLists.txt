cmake_minimum_required(VERSION 3.19)
project(tp3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(tp3
        ABB.h
        agua.cpp
        agua.h
        balas.cpp
        balas.h
        casillero.cpp
        casillero.h
        cazavampiro.cpp
        cazavampiro.h
        constantes.h
        cruz.cpp
        cruz.h
        elemento.cpp
        elemento.h
        escopeta.cpp
        escopeta.h
        estaca.cpp
        estaca.h
        estado.cpp
        estado.h
        humano.cpp
        humano.h
        identificador.cpp
        identificador.h
        interacciones.cpp
        interacciones.h
        main.cpp
        mapa.cpp
        mapa.h
        Menu.cpp
        Menu.h
        monstruo.h
        NodoABB.h
        nosferatu.cpp
        nosferatu.h
        objeto.cpp
        objeto.h
        ser.cpp
        ser.h
        tablero.cpp
        tablero.h
        vampirella.cpp
        vampirella.h
        vampiro.cpp
        vampiro.h
        vanesa.cpp
        vanesa.h
        zombi.cpp
        zombi.h)

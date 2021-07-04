cmake_minimum_required(VERSION 3.19)
project(Nosferatu)

set(CMAKE_CXX_STANDARD 14)

include_directories(ABB)
include_directories(tp2NosferatuRobin/src)

add_executable(Nosferatu
        ABB/ABB.h
        ABB/main.cpp
        ABB/NodoABB.h
        tp2NosferatuRobin/src/CargadorDatos.cpp
        tp2NosferatuRobin/src/CargadorDatos.h
        tp2NosferatuRobin/src/constantes.h
        tp2NosferatuRobin/src/Contadores.cpp
        tp2NosferatuRobin/src/Contadores.h
        tp2NosferatuRobin/src/ItemAgua.cpp
        tp2NosferatuRobin/src/ItemAgua.h
        tp2NosferatuRobin/src/ItemBala.cpp
        tp2NosferatuRobin/src/ItemBala.h
        tp2NosferatuRobin/src/ItemCruz.cpp
        tp2NosferatuRobin/src/ItemCruz.h
        tp2NosferatuRobin/src/ItemEscopeta.cpp
        tp2NosferatuRobin/src/ItemEscopeta.h
        tp2NosferatuRobin/src/ItemEstaca.cpp
        tp2NosferatuRobin/src/ItemEstaca.h
        tp2NosferatuRobin/src/ItemHumano.cpp
        tp2NosferatuRobin/src/ItemHumano.h
        tp2NosferatuRobin/src/ItemHumanoCV.cpp
        tp2NosferatuRobin/src/ItemHumanoCV.h
        tp2NosferatuRobin/src/ItemNosferatu.cpp
        tp2NosferatuRobin/src/ItemNosferatu.h
        tp2NosferatuRobin/src/Items.cpp
        tp2NosferatuRobin/src/Items.h
        tp2NosferatuRobin/src/ItemVampirella.cpp
        tp2NosferatuRobin/src/ItemVampirella.h
        tp2NosferatuRobin/src/ItemVampiro.cpp
        tp2NosferatuRobin/src/ItemVampiro.h
        tp2NosferatuRobin/src/ItemVanesa.cpp
        tp2NosferatuRobin/src/ItemVanesa.h
        tp2NosferatuRobin/src/ItemZombi.cpp
        tp2NosferatuRobin/src/ItemZombi.h
        tp2NosferatuRobin/src/main.cpp
        tp2NosferatuRobin/src/MatrizItems.cpp
        tp2NosferatuRobin/src/MatrizItems.h
        tp2NosferatuRobin/src/Menu.cpp
        tp2NosferatuRobin/src/Menu.h)

#ifndef INTENTO_UTILIDADES_H
#define INTENTO_UTILIDADES_H

#include <fstream>
#include "objeto.h"
#include "ser.h"
#include "humano.h"
#include "vampiro.h"
#include "elemento.h"
#include "agua.h"
#include "cruz.h"
#include "estaca.h"
#include "escopeta.h"
#include "balas.h"
#include "vanesa.h"
#include "nosferatu.h"
#include "vampirella.h"
#include "zombi.h"

const std::string NUMEROS = "0123456789";
const std::string PATH = "estado.txt";
const std::string c_humano = "h";
const std::string c_zombi = "z";
const std::string c_vampiro = "v";
const std::string c_agua = "a";
const std::string c_cruz = "c";
const std::string c_estaca = "e";
const std::string c_escopeta = "E";
const std::string c_balas = "b";
const std::string c_Vanesa = "W";
const std::string c_Vampirella = "V";
const std::string c_Nosferatu = "N";
const std::string c_Cazador = "H";
const std::string c_salir = "x";

enum OPCIONES_MENU_PRINCIPAL{
	AGREGAR_PERSONAJE_U_OBJETO = 1,
	ELIMINAR_PERSONAJE_U_OBJETO,
	MOSTRAR_TABLERO,
	BUSCAR_POR_CUADRANTE,
	BUSCAR_POR_ID,
	COMENZAR_SIMULACION,
	SALIR_MENU_PRINCIPAL,
};

enum OPCIONES_MENU_SIMULACION{
	BUSCAR_POR_ID_SIMULACION = 1,
	MOSTRAR_TABLERO_SIMULACION,
	MOSTRAR_CANTIDAD_DE_INTEGRANTES_DE_UN_BANDO_SIMULACION,
	SELECCIONAR_BANDO_SIMULACION,
	SALIR_SIMULACION,
};


#endif //INTENTO_UTILIDADES_H

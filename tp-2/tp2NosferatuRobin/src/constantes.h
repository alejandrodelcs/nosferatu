
#ifndef CONSTANTES_H_
#define CONSTANTES_H_

#include <string>

enum OPCIONES_MENU{
	MOSTRAR_TABLERO = 1,
	MOSTRAR_CUADRO_RESUMEN,
	BUSCAR_POR_CUADRANTE,
	DAR_ALTA,
	DAR_BAJA,
	INFORMAR_ELEMENTO,
	SALIR
};

const char _VACIO = '*';
const char _HUMANO_SIMPLE = 'h';
const char _HUMANO_CAZA_VAMPIROS_ZOMBIES = 'H';
const char _VANESA = 'W';
const char _ZOMBI = 'z';
const char _VAMPIRO = 'v';
const char _VAMPIRELLA = 'V';
const char _NOSFERATU = 'N';
const char _CRUZ = 'c';
const char _AGUA_BENDITA = 'a';
const char _ESTACA = 'e';
const char _ESCOPETA = 'E';
const char _BALAS = 'b';

const int UNO = 1;
const int CANTIDAD_DE_ELEMENTO = 2;
const int CANTIDAD_MINIMA = 1;
const int CANTIDAD_MAXIMA = 50;

const int MIN_FIL = 1;
const int MAX_FIL = 6;
const int MIN_COL = 1;
const int MAX_COL = 14;

const int LONGITUD_HUMANO_CV_STR = 9;

const int MITAD_LARGO_TABLERO = 8;
const int MITAD_ANCHO_TABLERO = 3;
const int LIMITE_LARGO = 14;
const int LIMITE_ANCHO = 6;

const float CIEN = 100.00;

const std::string AGUA_STR = "agua";
const std::string BALA_STR = "bala";
const std::string CRUZ_STR = "cruz";
const std::string ESCOPETA_STR = "escopeta";
const std::string ESTACA_STR = "estaca";
const std::string HUMANO_STR = "humano";
const std::string HUMANO_CV_STR = "humano CV";
const std::string VAMPIRO_STR = "vampiro";
const std::string ZOMBI_STR = "zombi";
const std::string NOSFERATU_STR = "Nosferatu";
const std::string VAMPIRELLA_STR = "Vampirella";
const std::string VANESA_STR = "Vanesa";

enum TIPO_ELEMENTO{
	ELEMENTO_AGUA = 1,
	ELEMENTO_BALA,
	ELEMENTO_CRUZ,
	ELEMENTO_ESCOPETA,
	ELEMENTO_ESTACA,
	ELEMENTO_HUMANO,
	ELEMENTO_HUMANO_CV,
	ELEMENTO_VAMPIRO,
	ELEMENTO_ZOMBI,
	ELEMENTO_VAMPIRELLA,
	ELEMENTO_NOSFERATU,
	ELEMENTO_VANESA
};

enum TIPO_CUADRANTE{
	NO = 1,
	NE,
	SO,
	SE
};

#endif /* CONSTANTES_H_ */

#ifndef CONTADORES_H_
#define CONTADORES_H_

#include "constantes.h"

class Contadores {

private:

	int contador_humanos;
	int contador_zombis;
	int contador_vampiros;
	int contador_agua;
	int contador_cruces;
	int contador_estacas;
	int contador_escopetas;
	int contador_balas;

public:

	Contadores();

	float obtener_porcentaje_escopetas();

	float obtener_porcentaje_balas();

	float obtener_porcentaje_humanos();

	float obtener_porcentaje_vampiros();

	float obtener_porcentaje_zombis();

	float obtener_porcentaje_agua();

	float obtener_porcentaje_estaca();

	float obtener_porcentaje_cruz();

	void reiniciar_contadores();

	void asignar_cantidad_humanos(int cantidad_humanos);

	void asignar_cantidad_zombis(int cantidad_zombis);

	void asignar_cantidad_vampiros(int cantidad_vampiros);

	void asignar_cantidad_agua(int cantidad_agua);

	void asignar_cantidad_cruces(int cantidad_cruces);

	void asignar_cantidad_estacas(int cantidad_estacas);

	void asignar_cantidad_escopetas(int cantidad_escopetas);

	void asignar_cantidad_balas(int cantidad_balas);

	int obtener_cantidad_humanos();

	int obtener_cantidad_zombis();

	int obtener_cantidad_vampiros();

	int obtener_cantidad_agua();

	int obtener_cantidad_cruces();

	int obtener_cantidad_estacas();

	int obtener_cantidad_escopetas();

	int obtener_cantidad_balas();

	void mostrar_estadisticas();

	virtual ~Contadores();
};

#endif /* CONTADORES_H_ */

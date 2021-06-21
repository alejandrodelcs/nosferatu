#ifndef MATRIZITEMS_H_
#define MATRIZITEMS_H_

#include "Items.h"
#include "constantes.h"
#include "Contadores.h"
#include "CargadorDatos.h"

class MatrizItems {

private:

	Items*** items;
	int fil;
	int col;

public:

	MatrizItems();

	MatrizItems(int fil, int col);

	MatrizItems* cargar_matriz();

	bool esta_ocupada(int fil, int col);

	bool esta_libre(int fil, int col);

	void asignar_dimensiones(int fil, int col);

	void agregar_item_a_matriz(Items* item, int posX, int posY);

	int obtener_dimension_filas();

	int obtener_dimension_columnas();

	void mostrar_contenido_matriz();

	void dibujar_estado_tablero();

	char obtener_char_caracteristico(std::string nombre_objeto);

	void dar_alta_elemento_en_matriz(Items* item, int posX, int posY);

	void dar_baja_elemento_en_matriz(int posX, int posY);

	void mensaje_ingreso_posicion();

	void interfaz_tablero();

	void informar_sobre_un_elemento_en_particular(int posX, int posY);

	void mostrar_cuadro_estadistico(Contadores* & c);

	int contar_humanos(Contadores* & contador);

	int contar_zombis(Contadores* & contador);

	int contar_vampiros(Contadores* & contador);

	int contar_agua(Contadores* & contador);

	int contar_cruces(Contadores* & contador);

	int contar_estacas(Contadores* & contador);

	int contar_escopetas(Contadores* & contador);

	int contar_balas(Contadores* & contador);

	void buscar_por_cuadrante(int cuadrante, int item_buscado);

	bool confirmar_existencia_item(int cuadrante, int item);

	bool buscar_item_NO(int opcion_item);

	bool buscar_item_NE(int opcion_item);

	bool buscar_item_SO(int opcion_item);

	bool buscar_item_SE(int opcion_item);

	void liberar_personajes();

	bool buscar_agua_NO();

	bool buscar_bala_NO();

	virtual ~MatrizItems();
};

#endif /* MATRIZITEMS_H_ */

#ifndef CARGADORDATOS_H_
#define CARGADORDATOS_H_

#include "Items.h"
#include "ItemAgua.h"
#include "ItemBala.h"
#include "ItemCruz.h"
#include "ItemEscopeta.h"
#include "ItemEstaca.h"
#include "ItemHumano.h"
#include "ItemHumanoCV.h"
#include "ItemVampiro.h"
#include "ItemZombi.h"
#include "ItemVampirella.h"
#include "ItemNosferatu.h"
#include "ItemVanesa.h"

#include <fstream>
#include <string>

class CargadorDatos {

public:

	CargadorDatos();

	int obtener_tipo_elemento_int(std::string nombre);

	char obtener_tipo_elemento_char(int tipo_elemento_int);

	int es_agua_int(std::string nombre);

	int es_bala_int(std::string nombre);

	int es_cruz_int(std::string nombre);

	int es_estaca_int(std::string nombre);

	int es_escopeta_int(std::string nombre);

	int es_Vampirella_int(std::string nombre);

	int es_Nosferatu_int(std::string nombre);

	int es_vampiro_int(std::string nombre);

	int es_humano_int(std::string nombre);

	int es_humano_cv_int(std::string nombre);

	int es_zombi_int(std::string nombre);

	int es_Vanesa_int(std::string nombre);

	Items* cargar_registro_item(std::string nombreItem, int coordXInt, int coordYInt, int cantidad);

	Items* cargar_registro_item_para_alta(int coordXInt, int coordYInt, int & cantidad);

	int obtener_cantidad_elemento_del_string(std::string nombre);

	bool es_agua(std::string nombre);

	bool es_bala(std::string nombre);

	bool es_cruz(std::string nombre);

	bool es_estaca(std::string nombre);

	bool es_escopeta(std::string nombre);

	bool es_Vampirella(std::string nombre);

	bool es_Nosferatu(std::string nombre);

	bool es_vampiro(std::string nombre);

	bool es_humano(std::string nombre);

	bool es_humano_cv(std::string nombre);

	bool es_zombi(std::string nombre);

	bool es_Vanesa(std::string nombre);

	void mostrar_opciones_item();

	void validar_opcion_elemento(int & opcion);

	void validar_cantidad_elemento(int & cantidad);

	void validar_posicion_X(int & posX);

	void validar_posicion_Y(int & posY);

	void validar_opcion_elemento_a_buscar(int & opcion);

	void mostrar_opciones_item_a_buscar();

	void validar_opcion_cuadrante(int & opcion_cuadrante);

	void mostrar_opcion_cuadrante();

	virtual ~CargadorDatos();
};

#endif /* CARGADORDATOS_H_ */

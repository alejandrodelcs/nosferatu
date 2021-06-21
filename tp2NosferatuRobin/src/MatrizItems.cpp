#include "MatrizItems.h"
#include <iostream>


MatrizItems::MatrizItems() {
	// TODO Auto-generated constructor stub
	this->items = 0;
	this->fil = 0;
	this->col = 0;
}


MatrizItems::MatrizItems(int fil, int col){
	this->fil = fil;
	this->col = col;

	items = new Items**[fil];
	for (int i = 0; i < fil; i++){
		items[i] = new Items*[col];
	}

	for (int i = 0; i < fil; i++){
		for (int j = 0; j < col; j++){
			items[i][j] = 0;
		}
	}
}

void MatrizItems::agregar_item_a_matriz(Items* item, int posX, int posY){
	if(esta_libre(posX-1, posY-1)){
		items[posX-1][posY-1] = item;
	}
	else{
		std::cout << "La posicion ingresada esta ocupada!" << std::endl;
	}
}

int MatrizItems::obtener_dimension_filas(){
	return this->fil;
}

int MatrizItems::obtener_dimension_columnas(){
	return this->col;
}

void MatrizItems::asignar_dimensiones(int dim_fil, int dim_col){
	this->fil = dim_fil;
	this->col = dim_col;
}

void MatrizItems::mostrar_contenido_matriz(){
	for (int i = 0; i < fil; i++){
		for (int j = 0; j < col; j++){
			if (!esta_ocupada(i, j)){
				std::cout << std::endl;std::cout << "[" << i << "][" << j << "] direccion: " << items[i][j] << ": libre!" <<  std::endl;
			}
			else{
				std::cout << "[" << i << "][" << j << "] direccion: " << items[i][j] << ": ocupada!" <<  std::endl;
				items[i][j]->mostrar_contenido();
			}
		}
	}
}

void MatrizItems::interfaz_tablero(){
	std::cout << "-----------------------------------------" << std::endl;
	for (int i = 0; i < col; i++){
		if(i <= MITAD_LARGO_TABLERO){
			std::cout << i+1 << "  ";
		}
		else{
			std::cout << i+1 << " ";
		}
	}
	std::cout << std::endl;
	std::cout << "-----------------------------------------" << std::endl;

}

void MatrizItems::dibujar_estado_tablero(){
char char_a_dibujar;
std::string nombre_elemento;
std::cout << "================*Tablero*================" << std::endl;
interfaz_tablero();
	for (int i = 0; i < fil; i++){
		for (int j = 0; j < col; j++){
			if(esta_ocupada(i, j)){
				nombre_elemento = items[i][j]->obtener_nombre();
				char_a_dibujar = obtener_char_caracteristico(nombre_elemento);
				std::cout << char_a_dibujar << "  ";
			}
			else{
				char_a_dibujar = _VACIO;
				std::cout << char_a_dibujar << "  ";
			}
		}
		std::cout << "|" << i+1 << std::endl;
	}
interfaz_tablero();
}

char MatrizItems::obtener_char_caracteristico(std::string nombre_objeto){
	char elemento_char;
	int elemento_int;
	CargadorDatos cargador;
	elemento_int = cargador.obtener_tipo_elemento_int(nombre_objeto);
	elemento_char = cargador.obtener_tipo_elemento_char(elemento_int);
	return elemento_char;
}

bool MatrizItems::esta_ocupada(int posX, int posY){
	return (items[posX][posY] != 0);
}

bool MatrizItems::esta_libre(int posX, int posY){
	return(items[posX][posY] == 0);
}

void MatrizItems::mensaje_ingreso_posicion(){
	std::cout << std::endl;
	std::cout << "======================================================" << std::endl;
	std::cout << "Ingrese posicion (x,y)" << std::endl;
	std::cout << "Primero se le pedira el ingreso de la coordenada X" << std::endl;
	std::cout << "Segundo se le pedira el ingreso de la coordenada Y" << std::endl;
	std::cout << "======================================================" << std::endl;
}

void MatrizItems::dar_alta_elemento_en_matriz(Items* item, int posX, int posY){
	CargadorDatos cargador_datos;

	mensaje_ingreso_posicion();
	cargador_datos.validar_posicion_X(posX);
	cargador_datos.validar_posicion_Y(posY);
	while(esta_ocupada(posX-1, posY-1)){
		std::cout << "Posicion ocupada!, reingrese posicion (x,y)" << std::endl;
		posX = 0; posY = 0;
		mensaje_ingreso_posicion();
		cargador_datos.validar_posicion_X(posX);
		cargador_datos.validar_posicion_Y(posY);
	}
	int cantidad_item_seleccionado = 0;
	item = cargador_datos.cargar_registro_item_para_alta(posX, posY, cantidad_item_seleccionado);
	agregar_item_a_matriz(item, posX, posY);
}

void MatrizItems::dar_baja_elemento_en_matriz(int posX, int posY){
	CargadorDatos c;
	mensaje_ingreso_posicion();
	c.validar_posicion_X(posX);
	c.validar_posicion_Y(posY);
	if(esta_libre(posX-1, posY-1)){
		std::cout << "La posicion esta LIBRE!, no hay nada que dar de BAJA!" << std::endl;
	}
	else{
		items[posX-1][posY-1]->mostrar_contenido();
		//delete items[posX-1][posY-1];
		items[posX-1][posY-1] = 0;
	}
}

void MatrizItems::informar_sobre_un_elemento_en_particular(int posX, int posY){
	CargadorDatos c;
	mensaje_ingreso_posicion();
	c.validar_posicion_X(posX);
	c.validar_posicion_Y(posY);
	if(esta_libre(posX-1, posY-1)){
		std::cout << "La posicion ingresada esta LIBRE!, no hay nada que mostrar!" << std::endl;
	}
	else{
		items[posX-1][posY-1]->mostrar_contenido();
	}
}

void MatrizItems::mostrar_cuadro_estadistico(Contadores* & contador){

	contador = new Contadores;
	std::cout << "-----Cuadro estadistico-----" << std::endl;

	contar_humanos(contador);
	contar_zombis(contador);
	contar_vampiros(contador);
	contar_balas(contador);
	contar_escopetas(contador);
	contar_agua(contador);
	contar_cruces(contador);
	contar_estacas(contador);

	contador->mostrar_estadisticas();

	delete contador;
}

int MatrizItems::contar_humanos(Contadores* & contador_obj){
	std::string nombre_item;
	CargadorDatos c;
	int cantidad_humanos = 0;

	for (int i = 0; i<fil; i++){
		for (int j = 0; j<col; j++){
			if(esta_ocupada(i, j)){
				nombre_item = items[i][j]->obtener_nombre();
					if (c.es_humano(nombre_item)){
						cantidad_humanos++;
						contador_obj->asignar_cantidad_humanos(cantidad_humanos);
					}
			}
		}
	}
	return contador_obj->obtener_cantidad_humanos();
}

int MatrizItems::contar_zombis(Contadores* & contador_obj){
	std::string nombre_item;
	CargadorDatos c;
	int cantidad_zombis = 0;

	for (int i = 0; i<fil; i++){
		for (int j = 0; j < col; j++){
			if(esta_ocupada(i, j)){
				nombre_item = items[i][j]->obtener_nombre();
					if(c.es_zombi(nombre_item)){
						cantidad_zombis++;
						contador_obj->asignar_cantidad_zombis(cantidad_zombis);
					}
			}
		}
	}
	return contador_obj->obtener_cantidad_zombis();
}

int MatrizItems::contar_vampiros(Contadores* & contador_obj){
	std::string nombre_item;
	CargadorDatos c;
	int cantidad_vampiros = 0;

	for (int i = 0; i<fil; i++){
		for (int j = 0; j<col; j++){
			if(esta_ocupada(i, j)){
				nombre_item = items[i][j]->obtener_nombre();
					if (c.es_vampiro(nombre_item)){
						cantidad_vampiros++;
						contador_obj->asignar_cantidad_vampiros(cantidad_vampiros);
					}
			}
		}
	}
	return contador_obj->obtener_cantidad_vampiros();
}


int MatrizItems::contar_agua(Contadores* & contador_obj){
	std::string nombre_item;
	CargadorDatos c;
	int cantidad_agua = 0;

	for (int i = 0; i < fil; i++){
		for (int j = 0; j < col; j++){
			if (esta_ocupada(i, j)){
				nombre_item = items[i][j]->obtener_nombre();
					if(c.es_agua(nombre_item)){
						cantidad_agua = cantidad_agua + items[i][j]->obtener_cantidad_elemento();
						contador_obj->asignar_cantidad_agua(cantidad_agua);
					}
			}
		}
	}
	return contador_obj->obtener_cantidad_agua();
}

int MatrizItems::contar_cruces(Contadores* & contador_obj){
	std::string nombre_item;
	CargadorDatos c;
	int cantidad_cruces = 0;

	for (int i = 0; i < fil; i++){
		for (int j = 0; j < col; j++){
			if (esta_ocupada(i, j)){
				nombre_item = items[i][j]->obtener_nombre();
					if(c.es_cruz(nombre_item)){
						cantidad_cruces++;
						contador_obj->asignar_cantidad_cruces(cantidad_cruces);
					}
			}
		}
	}
	return contador_obj->obtener_cantidad_cruces();
}

int MatrizItems::contar_estacas(Contadores* & contador_obj){
	std::string nombre_item;
	CargadorDatos c;
	int cantidad_estacas = 0;

	for (int i = 0; i<fil; i++){
		for (int j = 0; j < col; j++){
			if(esta_ocupada(i, j)){
				nombre_item = items[i][j]->obtener_nombre();
					if(c.es_estaca(nombre_item)){
						cantidad_estacas++;
						contador_obj->asignar_cantidad_estacas(cantidad_estacas);
					}
			}
		}
	}
	return contador_obj->obtener_cantidad_estacas();
}

int MatrizItems::contar_escopetas(Contadores* & contador_obj){
	std::string nombre_item;
	CargadorDatos c;
	int cantidad_escopetas = 0;

	for (int i = 0; i < fil; i++){
		for (int j = 0; j < col; j++){
			if(esta_ocupada(i, j)){
				nombre_item = items[i][j]->obtener_nombre();
					if(c.es_escopeta(nombre_item)){
						cantidad_escopetas++;
						contador_obj->asignar_cantidad_escopetas(cantidad_escopetas);
					}
			}
		}
	}
	return contador_obj->obtener_cantidad_escopetas();
}

int MatrizItems::contar_balas(Contadores* & contador_obj){
	std::string nombre_item;
	CargadorDatos c;
	int cantidad_balas = 0;

	for (int i = 0; i < fil; i++){
		for (int j = 0; j < col; j++){
			if(esta_ocupada(i, j)){
				nombre_item = items[i][j]->obtener_nombre();
					if(c.es_bala(nombre_item)){
						cantidad_balas = cantidad_balas + items[i][j]->obtener_cantidad_elemento();
						contador_obj->asignar_cantidad_balas(cantidad_balas);
					}
			}
		}
	}
	return contador_obj->obtener_cantidad_balas();
}


bool MatrizItems::buscar_item_NO(int opcion_item){
	bool encontrado = false;
	CargadorDatos c;
	std::string nombre_item;
		for (int i = 0; i < fil; i++){
			for (int j = 0; j < col; j++){
				if(esta_ocupada(i, j)){
					nombre_item = items[i][j]->obtener_nombre();
						if (c.obtener_tipo_elemento_int(nombre_item) == opcion_item && items[i][j]->esta_en_NO()){
							encontrado = true;
						}
				}
			}
		}
	return encontrado;
}

bool MatrizItems::buscar_item_NE(int opcion_item){
	bool encontrado = false;
	CargadorDatos c;
	std::string nombre_item;
		for (int i = 0; i < fil; i++){
			for (int j = 0; j < col; j++){
				if(esta_ocupada(i, j)){
					nombre_item = items[i][j]->obtener_nombre();
						if(c.obtener_tipo_elemento_int(nombre_item) == opcion_item && items[i][j]->esta_en_NE()){
							encontrado = true;
						}
				}
			}
		}
	return encontrado;
}

bool MatrizItems::buscar_item_SO(int opcion_item){
	bool encontrado = false;
	CargadorDatos c;
	std::string nombre_item;
		for (int i = 0; i < fil; i++){
			for (int j = 0; j < col; j++){
				if (esta_ocupada(i, j)){
					nombre_item = items[i][j]->obtener_nombre();
						if(c.obtener_tipo_elemento_int(nombre_item) == opcion_item && items[i][j]->esta_en_SO()){
							encontrado = true;
						}
				}
			}
		}
	return encontrado;
}

bool MatrizItems::buscar_item_SE(int opcion_item){
	bool encontrado = false;
	CargadorDatos c;
	std::string nombre_item;
		for (int i = 0; i < fil; i++){
			for (int j = 0; j < col; j++){
				if(esta_ocupada(i, j)){
					nombre_item = items[i][j]->obtener_nombre();
					if(c.obtener_tipo_elemento_int(nombre_item) == opcion_item && items[i][j]->esta_en_SE()){
							encontrado = true;
						}
				}
			}
		}
	return encontrado;
}

void MatrizItems::buscar_por_cuadrante(int cuadrante, int opcion_item){
	CargadorDatos c;
	dibujar_estado_tablero();
	c.validar_opcion_cuadrante(cuadrante);
	c.validar_opcion_elemento_a_buscar(opcion_item);

	if(confirmar_existencia_item(cuadrante, opcion_item)){
		std::cout << "El elemento seleccionado SI existe en el cuadrante seleccionado" << std::endl;
	}
	else{
		std::cout << "El elemento seleccionado NO existe en el cuadrante seleccionado" << std::endl;
	}
}


bool MatrizItems::confirmar_existencia_item(int cuadrante, int opcion_item){
	bool existe = false;

		switch(cuadrante){
			 case NO: existe = buscar_item_NO(opcion_item); std::cout << std::endl; break;
			 case NE: existe = buscar_item_NE(opcion_item); std::cout << std::endl; break;
			 case SO: existe = buscar_item_SO(opcion_item); std::cout << std::endl; break;
			 case SE: existe = buscar_item_SE(opcion_item); std::cout << std::endl; break;
		}
	return existe;
}

void MatrizItems::liberar_personajes(){
	for (int i = 0; i < fil; i++){
		for (int j = 0; j < col; j++){
			if(esta_ocupada(i, j)){
				delete items[i][j];
			}
		}
	}
}
MatrizItems* MatrizItems::cargar_matriz(){
	std::ifstream archivo;
	archivo.open("estado.txt", std::ios::in);
	CargadorDatos cargador_datos;

	std::string nombreItem;
	std::string coordXStr, coordYStr;
	std::string dimensionTableroXStr, dimensionTableroYStr;

	int coordXInt, coordYInt;
	int dimensionFila, dimensionColumna;
	int cantidad_elemento;
	Items* item;
	MatrizItems* matriz;

	if(archivo.is_open()){
		getline(archivo, dimensionTableroXStr,' ');
		getline(archivo, dimensionTableroYStr);
		dimensionFila = stoi(dimensionTableroXStr);
		dimensionColumna = stoi(dimensionTableroYStr);

		matriz = new MatrizItems(dimensionFila, dimensionColumna);

		while (!archivo.eof()){
			getline(archivo, nombreItem,'(');
			getline(archivo, coordXStr,',');
			getline(archivo, coordYStr);

			coordXInt = stoi(coordXStr);
			coordYInt = stoi(coordYStr);

			if(cargador_datos.es_agua(nombreItem) || cargador_datos.es_bala(nombreItem)){
				cantidad_elemento = cargador_datos.obtener_cantidad_elemento_del_string(nombreItem);
			}
			else{
	 			cantidad_elemento = UNO;
			}
			item = cargador_datos.cargar_registro_item(nombreItem, coordXInt, coordYInt, cantidad_elemento);
			matriz->agregar_item_a_matriz(item, coordXInt, coordYInt);
		}
	}
	else
	{
		std::cout << "no se pudo abrir el archivo!" << std::endl;
	}
	archivo.close();
	return matriz;
}

MatrizItems::~MatrizItems() {
	// TODO Auto-generated destructor stub

	for(int i = 0; i < fil; i++){
		for(int j = 0; j < col; j++){
			if(esta_ocupada(i, j)){
				delete items[i][j];
				items[i][j] = 0;
			}
		}
	}

	for(int i = 0; i < fil; i++){
		delete[] items[i];
		items[i] = 0;
	}
	delete[] items;
	items = 0;
}


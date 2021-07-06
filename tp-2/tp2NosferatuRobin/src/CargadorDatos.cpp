#include "CargadorDatos.h"
#include <iostream>

CargadorDatos::CargadorDatos() {
	// TODO Auto-generated constructor stub
}


void CargadorDatos::mostrar_opciones_item(){
	std::cout << std::endl;
	std::cout << "-----Ingrese un tipo de objeto-----" << std::endl;
	std::cout << "1.Agua" << std::endl;
	std::cout << "2.Bala" << std::endl;
	std::cout << "3.Cruz" << std::endl;
	std::cout << "4.Escopeta" << std::endl;
	std::cout << "5.Estaca" << std::endl;
	std::cout << "6.Humano (simple)" << std::endl;
	std::cout << "7.Humano(CazaVampiros, Matazombies)" << std::endl;
	std::cout << "8.Vampiro" << std::endl;
	std::cout << "9.Zombi" << std::endl;
	//std::cout << "10.Vampirella -deshabilitado-" << std::endl;
	//std::cout << "11.Nosferatu -deshabilido-" << std::endl;
	//std::cout << "12.Vanesa -deshabilitado-" << std::endl;
}

void CargadorDatos::mostrar_opcion_cuadrante(){
	std::cout << "Opciones cuadrante" << std::endl;
	std::cout << "1.NO" << std::endl;
	std::cout << "2.NE" << std::endl;
	std::cout << "3.SO" << std::endl;
	std::cout << "4.SE" << std::endl;

}

void CargadorDatos::validar_opcion_cuadrante(int & opcion_cuadrante){
	mostrar_opcion_cuadrante();
	std::cout << "Ingrese una opcion: ";
	std::cin >> opcion_cuadrante;
	while (opcion_cuadrante < NO || opcion_cuadrante > SE){
		std::cout << "Opcion cuadrante invalida!" << std::endl;
		mostrar_opcion_cuadrante();
		std::cout << "Reingrese opcion: ";
		std::cin >> opcion_cuadrante;
	}
}

void CargadorDatos::validar_opcion_elemento(int & opcion_elemento){
	std::cout << "ingrese una opcion: ";
	std::cin >> opcion_elemento;
	while (opcion_elemento < ELEMENTO_AGUA || opcion_elemento > ELEMENTO_ZOMBI){
		std::cout << "Opcion objeto invalida!" << std::endl;
		mostrar_opciones_item();
		std::cout << "Reingrese opcion: ";
		std::cin >> opcion_elemento;
	}
}

void CargadorDatos::mostrar_opciones_item_a_buscar(){
	std::cout << std::endl;
	std::cout << "-----Ingrese un tipo de objeto-----" << std::endl;
	std::cout << "1.Agua" << std::endl;
	std::cout << "2.Bala" << std::endl;
	std::cout << "3.Cruz" << std::endl;
	std::cout << "4.Escopeta" << std::endl;
	std::cout << "5.Estaca" << std::endl;
	std::cout << "6.Humano (simple)" << std::endl;
	std::cout << "7.Humano(CazaVampiros, Matazombies)" << std::endl;
	std::cout << "8.Vampiro" << std::endl;
	std::cout << "9.Zombi" << std::endl;
	std::cout << "10.Vampirella" << std::endl;
	std::cout << "11.Nosferatu" << std::endl;
	std::cout << "12.Vanesa" << std::endl;
}

void CargadorDatos::validar_opcion_elemento_a_buscar(int & opcion_elegida){
	mostrar_opciones_item_a_buscar();
	std::cout << "Ingrese una opcion: ";
	std::cin >> opcion_elegida;
	while (opcion_elegida < ELEMENTO_AGUA || opcion_elegida > ELEMENTO_VANESA){
		std::cout << "Opcion invalida!" << std::endl;
		mostrar_opciones_item_a_buscar();
		std::cout << "Reingrese opcion: ";
		std::cin >> opcion_elegida;
	}
}

void CargadorDatos::validar_cantidad_elemento(int & cantidad){
	std::cout << "Ingrese cantidad de elemento: ";
	std::cin >> cantidad;
	while (cantidad < CANTIDAD_MINIMA || cantidad > CANTIDAD_MAXIMA){
		std::cout << "cantidad invalida, reingrese: ";
		std::cin >> cantidad;
	}
}

void CargadorDatos::validar_posicion_X(int & posX){
	std::cout << "X: ";
	std::cin >> posX;
	while (posX < MIN_FIL || posX > MAX_FIL){
		std::cout << "X invalida, reingrese: ";
		std::cin >> posX;
	}
}

void CargadorDatos::validar_posicion_Y(int & posY){
	std::cout << "Y: ";
	std::cin >> posY;
	while (posY < MIN_COL || posY > MAX_COL){
		std::cout << "Y invalida, reingrese: ";
		std::cin >> posY;
	}
}

Items* CargadorDatos::cargar_registro_item_para_alta(int posX, int posY, int & cantidad){
	Items* item;
	mostrar_opciones_item();
	int opcion_elemento;
	validar_opcion_elemento(opcion_elemento);

	if (opcion_elemento == ELEMENTO_AGUA || opcion_elemento == ELEMENTO_BALA){
		validar_cantidad_elemento(cantidad);
	}
	else{
		cantidad = UNO;
	}

	switch (opcion_elemento){
		case ELEMENTO_AGUA: item = new ItemAgua(posX, posY, cantidad); break;
		case ELEMENTO_BALA: item = new ItemBala(posX, posY, cantidad); break;
		case ELEMENTO_CRUZ: item = new ItemCruz(posX, posY); break;
		case ELEMENTO_ESCOPETA: item = new ItemEscopeta(posX, posY); break;
		case ELEMENTO_ESTACA: item = new ItemEstaca(posX, posY); break;
		case ELEMENTO_HUMANO: item = new ItemHumano(posX, posY); break;
		case ELEMENTO_HUMANO_CV: item = new ItemHumanoCV(posX, posY); break;
		case ELEMENTO_VAMPIRO: item = new ItemVampiro(posX, posY); break;
		case ELEMENTO_ZOMBI: item = new ItemZombi(posX, posY); break;
		//case ELEMENTO_VAMPIRELLA: item = new ItemVampirella(posX, posY); break;
		//case ELEMENTO_NOSFERATU: item = new ItemNosferatu(posX, posY); break;
		//case ELEMENTO_VANESA: item = new ItemVanesa(posX, posY); break;
	}

	return item;
}

int CargadorDatos::obtener_tipo_elemento_int(std::string nombre){
	int numero_elemento = 0;
		numero_elemento = es_agua_int(nombre);
		numero_elemento = es_bala_int(nombre);
		numero_elemento = es_cruz_int(nombre);
		numero_elemento = es_escopeta_int(nombre);
		numero_elemento = es_estaca_int(nombre);
		numero_elemento = es_humano_int(nombre);
		numero_elemento = es_humano_cv_int(nombre);
		numero_elemento = es_vampiro_int(nombre);
		numero_elemento = es_zombi_int(nombre);
		numero_elemento = es_Vampirella_int(nombre);
		numero_elemento = es_Nosferatu_int(nombre);
		numero_elemento = es_Vanesa_int(nombre);

		return numero_elemento;
}

Items* CargadorDatos::cargar_registro_item(std::string nombreItem, int coordXInt, int coordYInt, int cantidad){
	Items* item;
	int tipo_elemento = 0;
	tipo_elemento = obtener_tipo_elemento_int(nombreItem);

	switch (tipo_elemento){
		case ELEMENTO_AGUA: item = new ItemAgua(coordXInt, coordYInt, cantidad); break;
		case ELEMENTO_BALA: item = new ItemBala(coordXInt, coordYInt, cantidad); break;
		case ELEMENTO_CRUZ: item = new ItemCruz(coordXInt, coordYInt); break;
		case ELEMENTO_ESCOPETA: item = new ItemEscopeta(coordXInt, coordYInt); break;
		case ELEMENTO_ESTACA: item = new ItemEstaca(coordXInt, coordYInt); break;
		case ELEMENTO_HUMANO: item = new ItemHumano(coordXInt, coordYInt); break;
		case ELEMENTO_HUMANO_CV: item = new ItemHumanoCV(coordXInt, coordYInt); break;
		case ELEMENTO_VAMPIRO: item = new ItemVampiro(coordXInt, coordYInt); break;
		case ELEMENTO_ZOMBI: item = new ItemZombi(coordXInt, coordYInt); break;
		case ELEMENTO_VAMPIRELLA: item = new ItemVampirella(coordXInt, coordYInt); break;
		case ELEMENTO_NOSFERATU: item = new ItemNosferatu(coordXInt, coordYInt); break;
		case ELEMENTO_VANESA: item = new ItemVanesa(coordXInt, coordYInt); break;
	}
	return item;
}

char CargadorDatos::obtener_tipo_elemento_char(int tipo_elemento_int){
	char c;
	switch(tipo_elemento_int){
		case ELEMENTO_AGUA: c = _AGUA_BENDITA; break;
		case ELEMENTO_BALA: c = _BALAS; break;
		case ELEMENTO_CRUZ: c = _CRUZ; break;
		case ELEMENTO_ESCOPETA: c = _ESCOPETA; break;
		case ELEMENTO_ESTACA: c = _ESTACA; break;
		case ELEMENTO_HUMANO: c = _HUMANO_SIMPLE; break;
		case ELEMENTO_HUMANO_CV: c = _HUMANO_CAZA_VAMPIROS_ZOMBIES; break;
		case ELEMENTO_VAMPIRO: c = _VAMPIRO; break;
		case ELEMENTO_ZOMBI: c = _ZOMBI; break;
		case ELEMENTO_VAMPIRELLA: c = _VAMPIRELLA; break;
		case ELEMENTO_NOSFERATU: c = _NOSFERATU; break;
		case ELEMENTO_VANESA: c = _VANESA; break;
	}
	return c;
}


int CargadorDatos::es_agua_int(std::string nombre){
	int es_agua_int;
	if(es_agua(nombre))
		es_agua_int = ELEMENTO_AGUA;
	return es_agua_int;
}

int CargadorDatos::es_bala_int(std::string nombre){
	int es_bala_int;
	if(es_bala(nombre))
		es_bala_int = ELEMENTO_BALA;
	return es_bala_int;
}

int CargadorDatos::es_cruz_int(std::string nombre){
	int es_cruz_int;
	if(es_cruz(nombre))
		es_cruz_int = ELEMENTO_CRUZ;
	return es_cruz_int;
}

int CargadorDatos::es_estaca_int(std::string nombre){
	int es_estaca_int;
	if(es_estaca(nombre))
		es_estaca_int = ELEMENTO_ESTACA;
	return es_estaca_int;
}

int CargadorDatos::es_escopeta_int(std::string nombre){
	int es_escopeta_int;
	if(es_escopeta(nombre))
		es_escopeta_int = ELEMENTO_ESCOPETA;
	return es_escopeta_int;
}

int CargadorDatos::es_Vampirella_int(std::string nombre){
	int es_Vampirella_int;
	if(es_Vampirella(nombre))
		es_Vampirella_int = ELEMENTO_VAMPIRELLA;
	return es_Vampirella_int;
}

int CargadorDatos::es_Nosferatu_int(std::string nombre){
	int es_Nosferatu_int;
	if(es_Nosferatu(nombre))
		es_Nosferatu_int = ELEMENTO_NOSFERATU;
	return es_Nosferatu_int;
}

int CargadorDatos::es_vampiro_int(std::string nombre){
	int es_vampiro_int;
	if(es_vampiro(nombre))
		es_vampiro_int = ELEMENTO_VAMPIRO;
	return es_vampiro_int;
}

int CargadorDatos::es_humano_int(std::string nombre){
	int es_humano_int;
	if(es_humano(nombre))
		es_humano_int = ELEMENTO_HUMANO;
	return es_humano_int;
}

int CargadorDatos::es_humano_cv_int(std::string nombre){
	int es_humano_cv_int;
	if(es_humano_cv(nombre))
		es_humano_cv_int = ELEMENTO_HUMANO_CV;
	return es_humano_cv_int;
}

int CargadorDatos::es_zombi_int(std::string nombre){
	int es_zombi_int;
	if(es_zombi(nombre))
		es_zombi_int = ELEMENTO_ZOMBI;
	return es_zombi_int;
}

int CargadorDatos::es_Vanesa_int(std::string nombre){
	int es_Vanesa_int;
	if(es_Vanesa(nombre))
		es_Vanesa_int = ELEMENTO_VANESA;
	return es_Vanesa_int;
}

bool CargadorDatos::es_agua(std::string nombre){
	return (nombre[0] == 'a' && nombre[3] == 'a');
}

bool CargadorDatos::es_bala(std::string nombre){
	return (nombre[0] == 'b' && nombre[3] == 'a');
}

bool CargadorDatos::es_cruz(std::string nombre){
	return (nombre[0] == 'c' && nombre[3] == 'z');
}

bool CargadorDatos::es_estaca(std::string nombre){
	return (nombre[0] == 'e' && nombre[5] == 'a');
}

bool CargadorDatos::es_escopeta(std::string nombre){
	return (nombre[0] == 'e' && nombre[7] == 'a');
}

bool CargadorDatos::es_Vampirella(std::string nombre){
	return (nombre[0] == 'V' && nombre[2] == 'm');
}

bool CargadorDatos::es_Nosferatu(std::string nombre){
	return (nombre[0] == 'N' && nombre[8] == 'u');
}

bool CargadorDatos::es_vampiro(std::string nombre){
	return ((nombre[0] == 'v' && nombre[6] == 'o') || es_Vampirella(nombre) || es_Nosferatu(nombre));
}

bool CargadorDatos::es_humano(std::string nombre){
	return ((nombre[0] == 'h' && nombre[5] == 'o') || es_Vanesa(nombre));
}

bool CargadorDatos::es_humano_cv(std::string nombre){
	int longitud_cadena = nombre.size();
	return(longitud_cadena == LONGITUD_HUMANO_CV_STR && es_humano(nombre));
}

bool CargadorDatos::es_zombi(std::string nombre){
	return (nombre[0] == 'z' && nombre[4] == 'i');
}

bool CargadorDatos::es_Vanesa(std::string nombre){
	return (nombre[0] == 'V' && nombre[5] =='a');
}

int CargadorDatos::obtener_cantidad_elemento_del_string(std::string nombre){
	int cantidad_elemento;

		 char cantidadDeUnidadesDeElemento[CANTIDAD_DE_ELEMENTO];
		 std::string stringElemento = nombre;
		 std::size_t lenght = stringElemento.copy(cantidadDeUnidadesDeElemento,2,5);
		 cantidadDeUnidadesDeElemento[lenght] = '\0';
		 std::string cantidadUnidadesElemento = cantidadDeUnidadesDeElemento;
		 cantidad_elemento = stoi(cantidadUnidadesElemento);

	return cantidad_elemento;
}

CargadorDatos::~CargadorDatos() {
	// TODO Auto-generated destructor stub
}


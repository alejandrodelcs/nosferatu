#include <string>


#ifndef CASILLERO_H_
#define CASILLERO_H_

class Casillero{
private:
	std::string terreno;

public:

	//Crea un casillero vacío
	Casillero();

	//PRE:
	//POS: Asigna el tipo de terreno que tiene el casillero
	void asignarTerreno(std::string terreno);

	//PRE:
	//POS: Devuelve el tipo de terreno que tiene el casillero
	std::string obtenerTerreno();



};



#endif /* CASILLERO_H_ */

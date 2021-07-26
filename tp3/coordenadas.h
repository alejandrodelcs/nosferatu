

#ifndef COORDENADAS_H_
#define COORDENADAS_H_

class Coordenadas{
private:
	int coordenadaX;
	int coordenadaY;
public:

	Coordenadas(int coordenadaX, int coordenadaY);

	//PRE:
	//POS: Devuelve la coordenada X
	int obtenerCoordenadaX();

	//PRE:
	//POS: Devuelve la coordenada Y
	int obtenerCoordenadaY();
};



#endif /* COORDENADAS_H_ */

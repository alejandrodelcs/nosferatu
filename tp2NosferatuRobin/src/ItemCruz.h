#ifndef ITEMCRUZ_H_
#define ITEMCRUZ_H_

#include "Items.h"
#include "constantes.h"

class ItemCruz : public Items{

public:

	ItemCruz(int posX, int posY);

	void mostrar_contenido();

	virtual ~ItemCruz();
};

#endif /* ITEMCRUZ_H_ */

#ifndef ITEMBALA_H_
#define ITEMBALA_H_

#include "Items.h"
#include "constantes.h"

class ItemBala : public Items{

public:

	ItemBala(int posX, int posY, int cantidad);

	void mostrar_contenido();

	virtual ~ItemBala();
};

#endif /* ITEMBALA_H_ */

#ifndef ITEMESCOPETA_H_
#define ITEMESCOPETA_H_

#include "Items.h"
#include "constantes.h"

class ItemEscopeta : public Items{

public:

	ItemEscopeta(int posX, int posY);

	void mostrar_contenido();

	virtual ~ItemEscopeta();
};

#endif /* ITEMESCOPETA_H_ */

#ifndef ITEMZOMBI_H_
#define ITEMZOMBI_H_

#include "Items.h"
#include "constantes.h"

class ItemZombi : public Items{

public:

	ItemZombi(int posX, int posY);

	void mostrar_contenido();

	virtual ~ItemZombi();
};

#endif /* ITEMZOMBI_H_ */

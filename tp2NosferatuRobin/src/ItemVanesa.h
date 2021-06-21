#ifndef ITEMVANESA_H_
#define ITEMVANESA_H_

#include "Items.h"
#include "constantes.h"

class ItemVanesa : public Items{

public:

	ItemVanesa(int posX, int posY);

	void mostrar_contenido();

	virtual ~ItemVanesa();
};

#endif /* ITEMVANESA_H_ */

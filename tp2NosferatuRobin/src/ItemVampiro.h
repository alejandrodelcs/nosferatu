#ifndef ITEMVAMPIRO_H_
#define ITEMVAMPIRO_H_

#include "Items.h"
#include "constantes.h"

class ItemVampiro : public Items{

public:

	ItemVampiro(int posX, int posY);

	void mostrar_contenido();

	virtual ~ItemVampiro();
};

#endif /* ITEMVAMPIRO_H_ */

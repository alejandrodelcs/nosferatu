#ifndef ITEMHUMANO_H_
#define ITEMHUMANO_H_

#include "Items.h"
#include "constantes.h"

class ItemHumano : public Items{

public:

	ItemHumano(int posX, int posY);

	void mostrar_contenido();

	virtual ~ItemHumano();
};

#endif /* ITEMHUMANO_H_ */

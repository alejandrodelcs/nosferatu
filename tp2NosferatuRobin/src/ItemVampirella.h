#ifndef ITEMVAMPIRELLA_H_
#define ITEMVAMPIRELLA_H_

#include "Items.h"
#include "constantes.h"

class ItemVampirella : public Items{

public:

	ItemVampirella(int posX, int posY);

	void mostrar_contenido();

	virtual ~ItemVampirella();
};

#endif /* ITEMVAMPIRELLA_H_ */

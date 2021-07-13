#ifndef ITEMHUMANOCV_H_
#define ITEMHUMANOCV_H_

#include "Items.h"
#include "constantes.h"

class ItemHumanoCV : public Items{

public:

	ItemHumanoCV(int posX, int posY);

	void mostrar_contenido();

	virtual ~ItemHumanoCV();
};

#endif /* ITEMHUMANOCV_H_ */

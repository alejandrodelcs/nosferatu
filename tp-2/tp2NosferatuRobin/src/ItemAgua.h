#ifndef ITEMAGUA_H_
#define ITEMAGUA_H_

#include "Items.h"
#include "constantes.h"

class ItemAgua : public Items {

public:

	ItemAgua (int posX, int posY, int cantidad);

	void mostrar_contenido();

	virtual ~ItemAgua();
};

#endif /* ITEMAGUA_H_ */

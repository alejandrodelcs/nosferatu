#ifndef ITEMESTACA_H_
#define ITEMESTACA_H_

#include "Items.h"
#include "constantes.h"

class ItemEstaca : public Items{

public:

	ItemEstaca(int posX, int posY);

	void mostrar_contenido();

	virtual ~ItemEstaca();
};

#endif /* ITEMESTACA_H_ */

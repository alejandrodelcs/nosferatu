#ifndef ITEMNOSFERATU_H_
#define ITEMNOSFERATU_H_

#include "Items.h"
#include "constantes.h"

class ItemNosferatu : public Items {

public:

	ItemNosferatu(int posX, int posY);

	void mostrar_contenido();

	virtual ~ItemNosferatu();
};

#endif /* ITEMNOSFERATU_H_ */

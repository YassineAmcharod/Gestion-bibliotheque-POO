/*
 * ListeLivres.h
 *
 *  Created on: 25 déc. 2020
 *      Author: hp
 */

#ifndef LISTELIVRES_H_
#define LISTELIVRES_H_

#include "Livre.h"

class ListeLivres {
public:
	Livre* livre;
	ListeLivres* suivant;
	ListeLivres();
	ListeLivres(Livre* l);
	virtual ~ListeLivres();
};

#endif /* LISTELIVRES_H_ */

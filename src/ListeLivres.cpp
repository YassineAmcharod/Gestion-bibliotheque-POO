/*
 * ListeLivres.cpp
 *
 *  Created on: 25 d�c. 2020
 *      Author: hp
 */

#include "ListeLivres.h"

ListeLivres::ListeLivres() {
	// TODO Auto-generated constructor stub
	this->livre = NULL;
	this->suivant = NULL;

}
ListeLivres::ListeLivres(Livre* l){
	this->livre = l;
	this->suivant = NULL;
}
ListeLivres::~ListeLivres() {
	// TODO Auto-generated destructor stub
}


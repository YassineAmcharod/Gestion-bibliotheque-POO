/*
 * recueilPoesie.h
 *
 *  Created on: 25 déc. 2020
 *      Author: hp
 */

#ifndef RECUEILPOESIE_H_
#define RECUEILPOESIE_H_

#include "Livre.h"
#include <string>

using namespace std;

class RecueilPoesie: public Livre {
private:
	string indicateur;
public:
	RecueilPoesie(int c ,string a , string t , string e , int i , string p, string indic);
	virtual void afficher();
	virtual ~RecueilPoesie();
};

#endif /* RECUEILPOESIE_H_ */

/*
 * PieceTheatre.h
 *
 *  Created on: 25 déc. 2020
 *      Author: hp
 */

#ifndef PIECETHEATRE_H_
#define PIECETHEATRE_H_

#include "Livre.h"
#include <string>

using namespace std;

class PieceTheatre: public Livre {
private:
	int siecle;
public:
	PieceTheatre(int c ,string a , string t , string e , int i , string p, int s);
	virtual void afficher();
	virtual ~PieceTheatre();
};

#endif /* PIECETHEATRE_H_ */

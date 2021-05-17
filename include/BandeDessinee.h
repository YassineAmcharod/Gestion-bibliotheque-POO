/*
 * BandeDessinee.h
 *
 *  Created on: 25 déc. 2020
 *      Author: hp
 */

#ifndef BANDEDESSINEE_H_
#define BANDEDESSINEE_H_

#include <string>
#include "Livre.h"

using namespace std;

class BandeDessinee: public Livre {
private:
	string dessinateur;
public:
	BandeDessinee(int c ,string a , string t , string e , int i , string p ,string d);
	virtual void afficher();
	virtual ~BandeDessinee();
};

#endif /* BANDEDESSINEE_H_ */

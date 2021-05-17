/*
 * Roman.h
 *
 *  Created on: 25 déc. 2020
 *      Author: hp
 */

#ifndef ROMAN_H_
#define ROMAN_H_

#include "Livre.h"
#include <string>

using namespace std;

class Roman: public Livre {
private:
	string genre;
public:
	Roman(int c ,string a , string t , string e , int i , string p, string type);
	virtual void afficher();
	virtual ~Roman();
};

#endif /* ROMAN_H_ */

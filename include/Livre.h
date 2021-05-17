/*
 * Livre.h
 *
 *  Created on: 25 déc. 2020
 *      Author: hp
 */

#ifndef LIVRE_H_
#define LIVRE_H_

#include <string>

using namespace std;

class Livre {
private:
	int code;
	string auteur;
	string titre;
	string editeur;
	int isbn;
	string sonPublic;
	int etat; // etat = 0 : libre, etat = 1: emprunté, etat = 2 : preté

public:
	Livre(int c, string a, string t, string e, int i, string pub);
	virtual void afficher();
	int getIsbn();
	int getEtat();
	void setEtat(int newEtat);
	virtual ~Livre();
};

#endif /* LIVRE_H_ */

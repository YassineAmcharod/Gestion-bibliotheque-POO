/*
 * Adherent.h
 *
 *  Created on: 26 déc. 2020
 *      Author: hp
 */

#ifndef ADHERENT_H_
#define ADHERENT_H_

#include <string>
#include "Bibliotheque.h"
#include "ListeLivres.h"
#include "Livre.h"

using namespace std;

class Adherent {
private:
	string nom;
	string prenom;
	string adresse;
	int numero;
	Bibliotheque*  b;
	ListeLivres* livresEmpruntes;
	int nombreAutorise;
	int nombreEmprunte;
public:
	Adherent(string n, string p, string a, int num, Bibliotheque* bib, int nbrMax);
	void emprunterLivre(Livre* l);
	void rendreLivre(Livre* l);
	void afficherAdherent();
	void afficherLivres();
	virtual ~Adherent();
};

#endif /* ADHERENT_H_ */

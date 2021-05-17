/*
 * Bibliotheque.h
 *
 *  Created on: 25 déc. 2020
 *      Author: hp
 */

#ifndef BIBLIOTHEQUE_H_
#define BIBLIOTHEQUE_H_

#include "ListeLivres.h"
#include "Livre.h"
#include <string>

using namespace std;

class Bibliotheque {
private:
	string nom;
	string adresse;
	int code;
	ListeLivres* livres;
	ListeLivres* livresPretes;
	ListeLivres* livresEmpruntes;

public:
	Bibliotheque(string n, string a, int c);
	void afficherBiblio();
	void afficherLivres();
	void emprunterLivre(int isbn, Bibliotheque* b);
	void rendreLivre(Livre* l, Bibliotheque* b);
	Livre* chercherLivre(int isbn);
	Livre* chercherLivreEmprunte(int isbn);
	Livre* chercherLivrePrete(int isbn);
	void ajouterLivre(Livre* l);
	void ajouterLivrePrete(Livre* l);
	void ajouterLivreEmprunte(Livre* l);
	void supprimerLivre(Livre* l);
	void supprimerLivrePrete(Livre* l);
	void supprimerLivreEmprunte(Livre* l);

	virtual ~Bibliotheque();
};

#endif /* BIBLIOTHEQUE_H_ */

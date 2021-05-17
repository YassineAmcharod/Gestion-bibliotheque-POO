/*
 * Adherent.cpp
 *
 *  Created on: 26 déc. 2020
 *      Author: hp
 */

#include "Adherent.h"
#include <iostream>

using namespace std;

Adherent::Adherent(string n, string p, string a, int num, Bibliotheque* bib, int nbrMax) {
	// TODO Auto-generated constructor stub
	this->nom = n;
	this->prenom = p;
	this->adresse = a;
	this->numero = num;
	this->b = bib;
	this->nombreAutorise = nbrMax;
	this->nombreEmprunte = 0;
	this->livresEmpruntes = new ListeLivres();

}

void Adherent::emprunterLivre(Livre* l){
	if((this->nombreAutorise > this->nombreEmprunte) && (l->getEtat() != 1) && (this->b->chercherLivre(l->getIsbn()) != NULL) ){
		ListeLivres* temp;
		temp = new ListeLivres(l);
		temp->suivant = this->livresEmpruntes;
		this->livresEmpruntes = temp;
		this->nombreEmprunte +=1;
		l->setEtat(1); // emprunté
	}
	else if(this->nombreAutorise <= this->nombreEmprunte){
		cout<<"\nVous avez dépacé le nombre de Livres autorisés ( "<<this->nombreAutorise<<" ).";
	}
	else if(l->getEtat() == 1){
		cout<<"\nLe livre n'est pas disponible pour l'instant";
	}
	else if(this->b->chercherLivre(l->getIsbn()) == NULL){
		cout<<"\nLe livre n'est pas disponible dans votre bibliothèque";
	}


}
void Adherent::rendreLivre(Livre* l){
    ListeLivres* temp;
    temp = this->livresEmpruntes;
    if(this->livresEmpruntes->livre == l){
        this->livresEmpruntes = this->livresEmpruntes->suivant;
        l->setEtat(0); // rendu
        this->nombreEmprunte -=1;
    }
    else if(this->livresEmpruntes->suivant->livre == l){
        this->livresEmpruntes->suivant = this->livresEmpruntes->suivant->suivant;
        l->setEtat(0); // rendu
        this->nombreEmprunte -=1;
    }
    else{
        while(temp->suivant->suivant->suivant != NULL){
            if(temp->suivant->livre == l){
                temp->suivant = temp->suivant->suivant;
                break;
            }
            else
                temp = temp->suivant;
        }
        if(temp->suivant->livre == l){
                temp->suivant = temp->suivant->suivant;
                l->setEtat(0); // rendu
                this->nombreEmprunte -=1;
        }
    }


}
void Adherent::afficherAdherent(){
    cout<<"\nNom : "<<this->nom<<"\nPrenom : "<<this->prenom<<"\nAdresse : "<<this->adresse<<"\nNuméro adherent : "<<this->numero;
    cout<<"\nBibliotheque : ";
    this->b->afficherBiblio();
    cout<<"\nListe des livres empruntes : ";
    this->afficherLivres();
    cout<<"\n#########################";
}
void Adherent::afficherLivres(){
    ListeLivres* temp;
    temp = this->livresEmpruntes;
    while(temp->suivant != NULL){
        temp->livre->afficher();
        temp = temp->suivant;
    }
}

Adherent::~Adherent() {
	// TODO Auto-generated destructor stub
}


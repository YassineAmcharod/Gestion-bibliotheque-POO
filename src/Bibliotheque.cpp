/*
 * Bibliotheque.cpp
 *
 *  Created on: 25 déc. 2020
 *      Author: hp
 */

#include "Bibliotheque.h"
#include <iostream>

using namespace std;

Bibliotheque::Bibliotheque(string n, string a, int c) {
	// TODO Auto-generated constructor stub
	this->nom = n;
	this->adresse = a;
	this->code = c;
	this->livres = new ListeLivres();
	this->livresEmpruntes = new ListeLivres();
	this->livresPretes = new ListeLivres();

}
void Bibliotheque::afficherBiblio(){
	cout<<"\nnom Bibliothèque : "<<this->nom<<"\nAdresse : "<<this->adresse<<"\nCode  : "<<this->code;
}
void Bibliotheque::afficherLivres(){
	ListeLivres* temp;
	temp = this->livres;
	while(temp->suivant != NULL){
	    temp->livre->afficher();
	    temp = temp->suivant;
	}
}

void Bibliotheque::emprunterLivre(int isbn, Bibliotheque* b){
    Livre* temp;
    if(this != b){
        temp = b->chercherLivre(isbn);
        //temp->afficher();
        if(temp->getIsbn() == isbn){
            this->ajouterLivreEmprunte(temp);
            b->ajouterLivrePrete(temp);
            b->supprimerLivre(temp);
            this->ajouterLivre(temp);
        }
    }
}
void Bibliotheque::rendreLivre(Livre* l, Bibliotheque* b){
    if(this != b){
    	if((l->getEtat() == 0) && (this->chercherLivreEmprunte(l->getIsbn()) != NULL) && (b->chercherLivrePrete(l->getIsbn()) != NULL)){
			this->supprimerLivre(l);
			this->supprimerLivreEmprunte(l);
			b->ajouterLivre(l);
			b->supprimerLivrePrete(l);
    	}

        else if(l->getEtat() != 0){
            cout<<"\nLe livre est deja emprunté par adherent de votre bibliotheque";
        }
        else if(this->chercherLivreEmprunte(l->getIsbn()) == NULL){
            cout<<"\nVotre bibliotheque n'a pas emprunte le livre";
        }
        else if(b->chercherLivrePrete(l->getIsbn()) == NULL){
            cout<<"\nLe livre n'appartient pas a la bibliotheque que vous avez entré";
        }

    }
}

Livre* Bibliotheque::chercherLivre(int isbn){
	ListeLivres* temp;
	temp = this->livres;
	while(temp->suivant != NULL){
		if(temp->livre->getIsbn() == isbn){
			return temp->livre; // existe
		}
		temp = temp->suivant;
	}
	return NULL; // n'existe pas null

}
Livre* Bibliotheque::chercherLivreEmprunte(int isbn){
	ListeLivres* temp;
	temp = this->livresEmpruntes;
	while(temp->suivant != NULL){
		if(temp->livre->getIsbn() == isbn){
			 return temp->livre; // existe
		}
		temp = temp->suivant;
	}
	return NULL; // n'existe pas
}
Livre* Bibliotheque::chercherLivrePrete(int isbn){
	ListeLivres* temp;
	temp = this->livresPretes;
	while(temp->suivant != NULL){
		if(temp->livre->getIsbn() == isbn){
			 return temp->livre; // existe
		}
		temp = temp->suivant;
	}
	return NULL; // n'existe pas
}
void Bibliotheque::ajouterLivre(Livre* l){
	ListeLivres* temp;
	temp = new ListeLivres(l);
	temp->suivant = this->livres;
	this->livres = temp;

}
void Bibliotheque::ajouterLivrePrete(Livre* l){
	ListeLivres* temp;
	temp = new ListeLivres(l);
	temp->suivant = this->livresPretes;
	this->livresPretes = temp;
}
void Bibliotheque::ajouterLivreEmprunte(Livre* l){
	ListeLivres* temp;
	temp = new ListeLivres(l);
	temp->suivant = this->livresEmpruntes;
	this->livresEmpruntes = temp;
}
void Bibliotheque::supprimerLivre(Livre* l){
    ListeLivres* temp;
    temp = this->livres;
    if(this->livres->livre == l){
        this->livres = this->livres->suivant;
    }
    else if(this->livres->suivant->livre == l){
        this->livres->suivant = this->livres->suivant->suivant;
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
        }
    }
}
void Bibliotheque::supprimerLivrePrete(Livre* l){
    ListeLivres* temp;
    temp = this->livresPretes;
    if(this->livresPretes->livre == l){
        this->livresPretes = this->livresPretes->suivant;
    }
    else if(this->livresPretes->suivant->livre == l){
        this->livresPretes->suivant = this->livresPretes->suivant->suivant;
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
        }
    }
}
void Bibliotheque::supprimerLivreEmprunte(Livre* l){
    ListeLivres* temp;
    temp = this->livresEmpruntes;
    if(this->livresEmpruntes->livre == l){
        this->livresEmpruntes = this->livresEmpruntes->suivant;
    }
    else if(this->livresEmpruntes->suivant->livre == l){
        this->livresEmpruntes->suivant = this->livresEmpruntes->suivant->suivant;
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
        }
    }
}

Bibliotheque::~Bibliotheque() {
	// TODO Auto-generated destructor stub
}


/*
 * Livre.cpp
 *
 *  Created on: 25 déc. 2020
 *      Author: hp
 */

#include <iostream>
#include "Livre.h"

using namespace std;

Livre::Livre(int c, string a, string t, string e, int i, string pub){
	this->code = c;
	this->auteur = a;
	this->titre = t;
	this->editeur = e;
	this->isbn = i;
	this->sonPublic = pub;
	this->etat = 0;
}
void Livre::afficher(){
	cout<<"\ncode : "<<this->code<<"\nauteur : "<<this->auteur<<"\ntitre : "<<this->titre<<"\nediteur : "<<this->editeur<<"\nisbn : "<<this->isbn;
	cout<<"\npublic : "<<this->sonPublic<<"\nétat : "<<this->etat;
}
int Livre::getIsbn(){
	return this->isbn;
}
int Livre::getEtat(){
	return this->etat;
}
void Livre::setEtat(int newEtat){
	this->etat = newEtat;
}
Livre::~Livre(){

}

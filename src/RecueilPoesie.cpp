/*
 * recueilPoesie.cpp
 *
 *  Created on: 25 déc. 2020
 *      Author: hp
 */

#include "RecueilPoesie.h"
#include <iostream>

using namespace std;

RecueilPoesie::RecueilPoesie(int c ,string a , string t , string e , int i , string p, string indic):Livre(c ,a ,t ,e ,i ,p) {
	// TODO Auto-generated constructor stub
	this->indicateur = indic;
}

void RecueilPoesie::afficher(){
    cout<<"\n###Recueil de Poésie : ";
	Livre::afficher();
	cout << "\nindicateur : " << this->indicateur;
}

RecueilPoesie::~RecueilPoesie() {
	// TODO Auto-generated destructor stub
}


/*
 * BandeDessinee.cpp
 *
 *  Created on: 25 déc. 2020
 *      Author: hp
 */

#include "BandeDessinee.h"
#include <iostream>

using namespace std;


BandeDessinee::BandeDessinee(int c ,string a , string t , string e , int i , string p ,string d):Livre(c ,a ,t ,e ,i ,p) {
	// TODO Auto-generated constructor stub
	this->dessinateur = d;

}

void BandeDessinee::afficher(){
    cout<<"\n###Bande Dessinée : ";
	Livre::afficher();
	cout << "\ndessinateur : " << this->dessinateur;
}

BandeDessinee::~BandeDessinee() {
	// TODO Auto-generated destructor stub
}


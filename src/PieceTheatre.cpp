/*
 * PieceTheatre.cpp
 *
 *  Created on: 25 déc. 2020
 *      Author: hp
 */

#include "PieceTheatre.h"
#include <iostream>

using namespace std;

PieceTheatre::PieceTheatre(int c ,string a , string t , string e , int i , string p, int s):Livre(c ,a ,t ,e ,i ,p) {
	// TODO Auto-generated constructor stub
	this->siecle = s;

}
void PieceTheatre::afficher(){
	cout<<"\n### Piéce de théâtre";
	Livre::afficher();
	cout<<"\n siècle : "<< this->siecle;
}
PieceTheatre::~PieceTheatre() {
	// TODO Auto-generated destructor stub
}


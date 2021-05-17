/*
 * Album.cpp
 *
 *  Created on: 25 déc. 2020
 *      Author: hp
 */

#include "Album.h"
#include <iostream>

using namespace std;

Album::Album(int c ,string a , string t , string e , int i , string p, string illus):Livre(c ,a ,t ,e ,i ,p) {
	// TODO Auto-generated constructor stub
	this->illustrations = illus;

}
void Album::afficher(){
	cout<<"\n### Album : ";
	Livre::afficher();
	cout<<"\nillustrations :"<<this->illustrations;
}

Album::~Album() {
	// TODO Auto-generated destructor stub
}


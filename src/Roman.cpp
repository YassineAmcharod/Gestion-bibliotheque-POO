/*
 * Roman.cpp
 *
 *  Created on: 25 déc. 2020
 *      Author: hp
 */

#include "Roman.h"
#include<iostream>

using namespace std;

Roman::Roman(int c ,string a , string t , string e , int i , string p, string type):Livre(c ,a ,t ,e ,i ,p) {
	// TODO Auto-generated constructor stub
	this->genre = type;

}
void Roman::afficher(){
	cout<<"\n### Roman :";
	Livre::afficher();
	cout<<"\ngenre : "<<this->genre;
}

Roman::~Roman() {
	// TODO Auto-generated destructor stub
}


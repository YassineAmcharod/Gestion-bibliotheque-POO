/*
 * Album.h
 *
 *  Created on: 25 déc. 2020
 *      Author: hp
 */

#ifndef ALBUM_H_
#define ALBUM_H_

#include "Livre.h"
#include <string>

using namespace std;
class Album: public Livre {
private:
	string illustrations;
public:
	Album(int c ,string a , string t , string e , int i , string p, string illus);
	void afficher();
	virtual ~Album();
};

#endif /* ALBUM_H_ */

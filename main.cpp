//============================================================================
// Name        : projetCpp.cpp
// Author      : yassine et hind
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include "Livre.h"
#include "BandeDessinee.h"
#include "Roman.h"
#include "Album.h"
#include "PieceTheatre.h"
#include "RecueilPoesie.h"
#include "Bibliotheque.h"
#include "Adherent.h"

#include <sstream>
#include <algorithm>
#include <vector>


using namespace std;

Livre* entrerLivre();
Bibliotheque* entrerBibio();
Adherent* entrerAdherent(Bibliotheque** b);
vector<string> &splitFunction(const string &s, char delim, vector<string> &elems);
vector<string> split(const string &s, char delim);

int main() {
    cout<<"###### Projet Bibliotheque (Amcharod et Choukri) ######\n"<<endl;

    cout << "===== Menu =====" << endl;
    cout << "1) Programmation sans interface utilisateur" << endl;
    cout << "2) Programmation avec interface" << endl;
    cout << "3) Programmation avec stockage dans des fichiers" << endl;

    int choix=0;
    while(choix!=1 && choix!=2 && choix!=3)
    {
       cout<<"entrez Votre choix (1 ou 2 ou 3 ) :";
       cin>>choix;
    }
    switch(choix){

        case 1:
        {
            cout << "===== Tests =====" << endl;
            Livre* a = new Livre(1,"romain","java","nada",11,"adulte");
            //a->afficher();
            BandeDessinee* b = new BandeDessinee(2,"yassine","jee","baka",22,"adulte","jack");
            //b->afficher();
            Roman* r = new Roman(3,"taha","html","simi",33,"adulte","drama");
            //r->afficher();
            Album* d = new Album(4,"arthur","css","doha",44,"adulte","photo");
            //d->afficher();
            PieceTheatre* p = new PieceTheatre(5,"salah","javascript","rajib",55,"adulte",19);
            //p->afficher();
            RecueilPoesie* z = new RecueilPoesie(6,"ali","php","tawfik",66,"adulte","vers");
            //z->afficher();

            Bibliotheque* marseille = new Bibliotheque("saint charles", "marseille centre ville", 1);
            Bibliotheque* ecm = new Bibliotheque("centrale marseille", "chateaux gombert", 2);

            Adherent* a1 = new Adherent("yassine", "amcharod", "alice chatenoud", 1, marseille, 2);
            Adherent* a11 = new Adherent("sarah", "tabi", "prado", 11, marseille, 2);
            Adherent* a2 = new Adherent("hind", "choukri", "saint charles", 2, ecm, 3);

            marseille->ajouterLivre(a);
            marseille->ajouterLivre(b);
            marseille->ajouterLivre(r);
            ecm->ajouterLivre(d);
            ecm->ajouterLivre(p);
            ecm->ajouterLivre(z);

            cout<<"\n>>>> test Affichage d'une bibliotheque et de ses livres : \n";
            marseille->afficherBiblio();
            cout<<"\n>>livres : ";
            marseille->afficherLivres();


            cout<<"\n>>>> test des opérations par les adherents : \n";
            a1->afficherLivres(); // aucun livres pour l'instant
            a1->emprunterLivre(a); // le livre est libre donc il sera preter à l'aherent
            a1->emprunterLivre(d); // n'est pas disponible dans sa bibliotheque
            a1->emprunterLivre(b); // le livre est libre donc il sera preter à l'aherent
            a1->emprunterLivre(r); // l'aderent à depasser son nombre autorisé de livre
            a11->emprunterLivre(a); // déja emprunté par a1 donc n'est pas libre
            a1->afficherLivres(); // les livres empruntés : a et b

            cout<<"\n>>>> test supprimer livre :\n";
            marseille->supprimerLivre(r); // on supprime le livre r
            marseille->afficherLivres(); // que les livres a et b restent dans la biblio

            cout<<"\n>>>> test des empruntes réalisés entre les biblios : \n";
            marseille->emprunterLivre(44, ecm);
            a11->emprunterLivre(d);
            marseille->rendreLivre(d, ecm); // déja emprunté par un adherent, on peut pas le rendre
            a11->rendreLivre(d);
            marseille->rendreLivre(d, ecm); // le livre est rendu la sa biblio de base
            ecm->afficherLivres(); // contient à nouveau le livre d
            cout<<"\n########\n";
            marseille->afficherLivres(); // le livre d est rendu donc il n'est plus disponoble pour les adherent de cette biblio
            cout<<"\n########\n";
            a2->emprunterLivre(d);  // a2 va avoir accès au livre rendu à sa biblio
            a2->afficherLivres();
            break;
        }
        case 2:
        {
            cout << "===== Version 2 =====" << endl;
            cout << "===== Entrer les livres =====" << endl;
            cout<<"\ndans cette version vous devez entrer 5 livres :";
            Livre* NomsLivres[5];
            for(int i=0; i<5 ; i++){
                cout<<"\n>>>Entrer le Livre numero "<<i+1<<endl;
                NomsLivres[i] = entrerLivre();
            }
            cout << "===== Entrer les bibliotheques =====" << endl;
            cout<<"\ndans cette version vous devez entrer 2 bibliotheques :";
            Bibliotheque* NomsBiblio[2];
            for(int i=0; i<2 ; i++){
                cout<<"\n>>>Entrer la bibliotheque numero "<<i+1<<endl;
                NomsBiblio[i] = entrerBibio();
            }
            cout << "===== Entrer les Adherents =====" << endl;
            cout<<"\ndans cette version vous devez entrer 3 adherents :";
            Adherent* NomsAdherents[3];
            for(int i=0; i<3 ; i++){
                cout<<"\n>>>Entrer l'adherent numero "<<i+1<<endl;
                NomsAdherents[i] = entrerAdherent(NomsBiblio);
            }

            NomsBiblio[0]->ajouterLivre(NomsLivres[0]);
            NomsBiblio[0]->ajouterLivre(NomsLivres[1]);
            NomsBiblio[0]->ajouterLivre(NomsLivres[2]);
            NomsBiblio[1]->ajouterLivre(NomsLivres[3]);
            NomsBiblio[1]->ajouterLivre(NomsLivres[4]);

            cout<<"\n>>>> test Affichage d'une bibliotheque et de ses livres : \n";
            cout<<"\n>>>> on affiche la 1 ere bibliotheque\n";
            NomsBiblio[0]->afficherBiblio();
            cout<<"\n>>livres : ";
            NomsBiblio[0]->afficherLivres();

            /*
            // dans ce cas il faut que NomsAdherents[0] et NomsAdherents[2] soient des adherents de NomsBiblio[0]
            // et NomsAdherents[1] un adherent de NomsBiblio[1]
            // et isbn de NomsLivres[4] soit égale à 44
            cout<<"\n>>>> test des opérations par les adherents : \n";
            NomsAdherents[0]->afficherLivres(); // aucun livres pour l'instant
            NomsAdherents[0]->emprunterLivre(NomsLivres[0]); // le livre est libre donc il sera preter à l'aherent
            NomsAdherents[0]->emprunterLivre(NomsLivres[4]); // n'est pas disponible dans sa bibliotheque
            NomsAdherents[0]->emprunterLivre(NomsLivres[1]); // le livre est libre donc il sera preter à l'aherent
            NomsAdherents[0]->emprunterLivre(NomsLivres[2]); // l'aderent à depasser son nombre autorisé de livre
            NomsAdherents[2]->emprunterLivre(NomsLivres[0]); // déja emprunté par a1 donc n'est pas libre
            NomsAdherents[0]->afficherLivres(); // les livres empruntés

            cout<<"\n>>>> test supprimer livre :\n";
            NomsBiblio[0]->supprimerLivre(NomsLivres[0]); // on supprime le livre r
            NomsBiblio[0]->afficherLivres(); // que les livres a et b restent dans la biblio

            cout<<"\n>>>> test des empruntes réalisés entre les biblios : \n";
            NomsBiblio[0]->emprunterLivre(44, NomsBiblio[1]);
            NomsAdherents[2]->emprunterLivre(NomsLivres[4]);
            NomsBiblio[0]->rendreLivre(NomsLivres[4], NomsBiblio[1]); // déja emprunté par un adherent, on peut pas le rendre
            NomsAdherents[2]->rendreLivre(NomsLivres[4]);
            NomsBiblio[0]->rendreLivre(NomsLivres[4], NomsBiblio[1]); // le livre est rendu la sa biblio de base
            NomsBiblio[1]->afficherLivres(); // contient à nouveau le livre d
            cout<<"\n########\n";
            NomsBiblio[0]->afficherLivres(); // le livre d est rendu donc il n'est plus disponoble pour les adherent de cette biblio
            cout<<"\n########\n";
            NomsAdherents[1]->emprunterLivre(NomsLivres[4]);  // a2 va avoir accès au livre rendu à sa biblio
            NomsAdherents[1]->afficherLivres();*/

            break;
        }
        case 3:
        {
            cout << "===== Version 3 =====" << endl;
            cout << "===== les informations sont stockés dans des fichiers ( livres, bibliotheque et adherents )  =====" << endl;
            cout<<"\ndans cette version on dispose de 6 livres dans le fichier livres.txt :"; // bien evidament on peut rendre la taille dynamique
            Livre* NomsLivres[6]; // on peut aussi ameleorer la version à fin que l'utilisateur peut écrire dans les fichiers
            ifstream fichier("fichiers/livres.txt", ios::in);  // on ouvre en lecture

            if(fichier)  // si l'ouverture a fonctionné
            {
                    string ligne;
                    int i=0;
                    while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
                    {
                           //cout << ligne << endl;  // on l'affiche
                           string chaine(ligne);
                           char delime(',');
                           vector<string> chaineFinal(split(chaine, delime));
                           if(chaineFinal[0]=="Livre"){
                               NomsLivres[i] = new Livre(stoi(chaineFinal[1]),chaineFinal[2],chaineFinal[3],chaineFinal[4],stoi(chaineFinal[5]),chaineFinal[6]);}
                           else if(chaineFinal[0]=="BandeDessinee"){
                               NomsLivres[i] = new BandeDessinee(stoi(chaineFinal[1]),chaineFinal[2],chaineFinal[3],chaineFinal[4],stoi(chaineFinal[5]),chaineFinal[6],chaineFinal[7]);}
                           else if(chaineFinal[0]=="Roman"){
                               NomsLivres[i] = new Roman(stoi(chaineFinal[1]),chaineFinal[2],chaineFinal[3],chaineFinal[4],stoi(chaineFinal[5]),chaineFinal[6],chaineFinal[7]);}
                           else if(chaineFinal[0]=="Album"){
                               NomsLivres[i] = new Album(stoi(chaineFinal[1]),chaineFinal[2],chaineFinal[3],chaineFinal[4],stoi(chaineFinal[5]),chaineFinal[6],chaineFinal[7]);}
                           else if(chaineFinal[0]=="PieceTheatre"){
                               NomsLivres[i] = new PieceTheatre(stoi(chaineFinal[1]),chaineFinal[2],chaineFinal[3],chaineFinal[4],stoi(chaineFinal[5]),chaineFinal[6],stoi(chaineFinal[7]));}
                           else if(chaineFinal[0]=="RecueilPoesie"){
                               NomsLivres[i] = new RecueilPoesie(stoi(chaineFinal[1]),chaineFinal[2],chaineFinal[3],chaineFinal[4],stoi(chaineFinal[5]),chaineFinal[6],chaineFinal[7]);}
                           i++;
                    }
                    fichier.close();
            }
            else
                cout << "Impossible d'ouvrir le fichier livres!" << endl;


            cout<<"\ndans cette version on dispose de 2 bibliotheques dans le fichier bibiotheques.txt :\n"; // bien evidament on peut rendre la taille dynamique
            Bibliotheque* NomsBiblio[2]; // on peut aussi ameleorer la version à fin que l'utilisateur peut écrire dans les fichiers
            ifstream fichier2("fichiers/bibliotheques.txt", ios::in);  // on ouvre en lecture

            if(fichier2)  // si l'ouverture a fonctionné
            {
                    string ligne;
                    int i=0;
                    while(getline(fichier2, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
                    {
                           //cout << ligne << endl;  // on l'affiche
                           string chaine(ligne);
                           char delime(',');
                           vector<string> chaineFinal(split(chaine, delime));
                           NomsBiblio[i] = new Bibliotheque(chaineFinal[0], chaineFinal[1], stoi(chaineFinal[2]));
                           i++;
                    }
                    fichier2.close();
            }
            else
                cout << "Impossible d'ouvrir le fichier Bibliotheques !" << endl;

            cout<<"\ndans cette version on dispose de 3 adherents dans le fichier adherents.txt :\n"; // bien evidament on peut rendre la taille dynamique
            Adherent* NomsAdherents[3]; // on peut aussi ameleorer la version à fin que l'utilisateur peut écrire dans les fichiers
            ifstream fichier3("fichiers/adherents.txt", ios::in);  // on ouvre en lecture

            if(fichier3)  // si l'ouverture a fonctionné
            {
                    string ligne;
                    int i=0;
                    Bibliotheque* bib;
                    while(getline(fichier3, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
                    {
                           //cout << ligne << endl;  // on l'affiche
                           string chaine(ligne);
                           char delime(',');
                           vector<string> chaineFinal(split(chaine, delime));
                           bib = NomsBiblio[stoi(chaineFinal[4])-1];
                           NomsAdherents[i] = new Adherent(chaineFinal[0],chaineFinal[1],chaineFinal[2],stoi(chaineFinal[3]), bib,stoi(chaineFinal[5]));
                           i++;
                    }
                    fichier3.close();
            }
            else
                cout << "Impossible d'ouvrir le fichier adherents !" << endl;


            NomsBiblio[0]->ajouterLivre(NomsLivres[0]);
            NomsBiblio[0]->ajouterLivre(NomsLivres[1]);
            NomsBiblio[0]->ajouterLivre(NomsLivres[2]);
            NomsBiblio[1]->ajouterLivre(NomsLivres[3]);
            NomsBiblio[1]->ajouterLivre(NomsLivres[4]);
            NomsBiblio[1]->ajouterLivre(NomsLivres[5]);

            cout<<"\n>>>> test Affichage d'une bibliotheque et de ses livres : \n";
            cout<<"\n>>>> on affiche la 1 ere bibliotheque\n";
            NomsBiblio[0]->afficherBiblio();
            cout<<"\n>>livres : ";
            NomsBiblio[0]->afficherLivres();


            cout<<"\n>>>> test des opérations par les adherents : \n";
            NomsAdherents[0]->afficherLivres(); // aucun livres pour l'instant
            NomsAdherents[0]->emprunterLivre(NomsLivres[0]); // le livre est libre donc il sera preter à l'aherent
            NomsAdherents[0]->emprunterLivre(NomsLivres[4]); // n'est pas disponible dans sa bibliotheque
            NomsAdherents[0]->emprunterLivre(NomsLivres[1]); // le livre est libre donc il sera preter à l'aherent
            NomsAdherents[0]->emprunterLivre(NomsLivres[2]); // l'aderent à depasser son nombre autorisé de livre
            NomsAdherents[2]->emprunterLivre(NomsLivres[0]); // déja emprunté par a1 donc n'est pas libre
            NomsAdherents[0]->afficherLivres(); // les livres empruntés

            cout<<"\n>>>> test supprimer livre :\n";
            NomsBiblio[0]->supprimerLivre(NomsLivres[2]); // on supprime le livre
            NomsBiblio[0]->afficherLivres(); // que deux livres restent dans la biblio

            cout<<"\n>>>> test des empruntes réalisés entre les biblios : \n";
            NomsBiblio[0]->emprunterLivre(44, NomsBiblio[1]);
            NomsAdherents[2]->emprunterLivre(NomsLivres[3]);
            NomsBiblio[0]->rendreLivre(NomsLivres[3], NomsBiblio[1]); // déja emprunté par un adherent, on peut pas le rendre
            NomsAdherents[2]->rendreLivre(NomsLivres[3]);
            NomsBiblio[0]->rendreLivre(NomsLivres[3], NomsBiblio[1]); // le livre est rendu la sa biblio de base
            NomsBiblio[1]->afficherLivres(); // contient à nouveau le livre
            cout<<"\n########\n";
            NomsBiblio[0]->afficherLivres(); // le livre est rendu donc il n'est plus disponoble pour les adherent de cette biblio
            cout<<"\n########\n";
            NomsAdherents[1]->emprunterLivre(NomsLivres[3]);  // il va avoir accès au livre rendu à sa biblio
            NomsAdherents[1]->afficherLivres();

            break;

        }

	}


	return 0;

}

Livre* entrerLivre()
{
    int choix2 =0;
    Livre* p;
    cout<<"quel est Votre choix :\n";
    cout << "1) Bande Dessinee" << endl;
    cout << "2) Roman" << endl;
    cout << "3) Album " << endl;
    cout << "4) Piece de Theatre" <<endl;
    cout << "5) Recueil de Poesie" <<endl;
    cin>>choix2;
    int code;
    string auteur;
    string titre;
    string edition;
    int isbn;
    string publique;
    cout << "Entrer code :" <<endl;
    cin>>code;
    cout << "Entrer auteur :" <<endl;
    cin>>auteur;
    cout << "Entrer titre :" <<endl;
    cin>>titre;
    cout << "Entrer edition :" <<endl;
    cin>>edition;
    cout << "Entrer isbn :" <<endl;
    cin>>isbn;
    cout << "Entrer publique :" <<endl;
    cin>>publique;
    switch(choix2){
        case 1:{
            string dessinateur;
            cout << "Entrer dessinateur :" <<endl;
            cin>>dessinateur;
            p = new BandeDessinee(code,auteur,titre,edition,isbn,publique,dessinateur);
            break;
        }
        case 2:{
            string genre;
            cout << "Entrer genre :" <<endl;
            cin>>genre;
            p = new Roman(code,auteur,titre,edition,isbn,publique,genre);
            break;
        }
        case 3:{
            string illustrations;
            cout << "Entrer illustrations :" <<endl;
            cin>>illustrations;
            p = new Album(code,auteur,titre,edition,isbn,publique,illustrations);
            break;
        }
        case 4:{
            int siecle;
            cout << "Entrer siecle :" <<endl;
            cin>>siecle;
            p = new PieceTheatre(code,auteur,titre,edition,isbn,publique,siecle);
            break;
        }
        case 5:{
            string indicateur;
            cout << "Entrer indicateur :" <<endl;
            cin>>indicateur;
            p = new RecueilPoesie(code,auteur,titre,edition,isbn,publique,indicateur);
            break;
        }

    }
    return p;

}

Bibliotheque* entrerBibio(){
   string nom;
   string adresse;
   int code;
   cout << "Entrer nom :" <<endl;
   cin>>nom;
   cout << "Entrer code :" <<endl;
   cin>>code;
   cout << "Entrer adresse :" <<endl;
   cin>>adresse;
   Bibliotheque* p = new Bibliotheque(nom, adresse, code);
   return p;

}

Adherent* entrerAdherent(Bibliotheque** b){
    string nom;
    string prenom;
    string adresse;
    int numero;
    int nbrMax;
    int numBib;
    cout << "Entrer nom :" <<endl;
    cin>>nom;
    cout << "Entrer prenom :" <<endl;
    cin>>prenom;
    cout << "Entrer adresse :" <<endl;
    cin>>adresse;
    cout << "Entrer son numero :" <<endl;
    cin>>numero;
    cout << "Choisir la Bibliotheque dont il est adherent enter (1 , 2)  :" <<endl;
    cin>>numBib;
    Bibliotheque* bib = b[numBib-1];
    cout << "Entrer nombre max autorisé :" <<endl;
    cin>>nbrMax;
    Adherent* p = new Adherent(nom,prenom, adresse, numero, bib, nbrMax);
    return p;

}

vector<string> &splitFunction(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


vector<string> split(const string &s, char delim) {
    vector<string> elems;
    splitFunction(s, delim, elems);
    return elems;
}

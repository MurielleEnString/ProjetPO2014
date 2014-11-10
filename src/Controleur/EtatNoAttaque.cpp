/**
*Fichier EtatNoAttaque.cpp
* @author Pierre Gaultier & Theo Dolez
*/


#include <iostream>
#include <sstream> // pour les conversions en chaine
#include <typeinfo>

using namespace std; // seulement dans le .cpp !

/////////////////////////////////////////////////////////////////////////
/**
* Constructeur.
* @param j le jeu 
*/
EtatNoAttaque::EtatNoAttaque(Jeu* j)
{
	this->jeu = j;
}

/////////////////////////////////////////////////////////////////////////
/**
* Destructeur
*/
EtatNoAttaque::~EtatNoAttaque()
{
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui renvoie le jeu
*@return jeu le jeu
*/
Jeu* EtatNoAttaque::getJeu()
{
  return this->jeu;  
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui termine le tour en cours, et lance le suivant
*/
void EtatNoAttaque::finTour()
{
  jeu->setEtat(jeu->getEtatDebutTour());
  jeu->echangeJoueur();
  jeu->jouer();
}

/////////////////////////////////////////////////////////////////////////
int EtatNoAttaque::afficherChoixEtat()
{
	int choix = -1;
	int choixcarte;
	int choixcarte1, choixcarte2;
	bool malinvoc;
	int pdmn = jeu->getJoueurCourant()->getPersonnage().getPdm();
	
	cout << "\nETAT NO ATTAQUE\n" << endl;
	
	jeu->getVue().afficherChoixNoAttaque();
	choix = jeu->getVue().getChoixJoueur();
		switch (choix)
		{
		    case 1: {
					jeu->getVue().afficherMain(jeu->getJoueurCourant());
					break;
		    }
		    case 2:  {
		   		jeu->getVue().afficherJouerCarte();
		   		choixcarte = jeu->getVue().getChoixJoueur();
		   		if ( jeu->getJoueurCourant()->getMain()->at(choixcarte-1).getCoutmana() <= pdmn)
		   		{
		   			jeu->getJoueurCourant()->ajouterBoard(jeu->getJoueurCourant()->getMain()->at(choixcarte-1));
		   			pdmn = pdmn - jeu->getJoueurCourant()->getMain()->at(choixcarte-1).getCoutmana();
		   			malinvoc = jeu->getJoueurCourant()->getMain()->at(choixcarte-1).getMalinvoc();
		   			jeu->getVue().afficherPdmnRestant(pdmn);
		   		 	jeu->getJoueurCourant()->supprimerMain(choixcarte);
		   		 	
		   		 	
		   		 	
		   		 	if (jeu->testNoMana() == true )
		   		 	{
		   		 		if (malinvoc == false) 
		   		 		{
		   		 			jeu->setEtat(jeu->getEtatNoMana());
		   		 		} else {
			   		 		jeu->setEtat(jeu->getEtatDoubleNo());
			   		 	}
		   		 	} else {
		   		 		
		   		 		if (malinvoc == false) 	 
		   		 		{
		   		 			jeu->setEtat(jeu->getEtatDebutTour());
		   		 		}
		   		 	}
		   		 	
		   		}else{
		   			
		   			jeu->getVue().afficherPasAssezDeMana();
		      	}
		      break;
		    }
		    case 3: {	
				  jeu->getVue().afficherBoard(jeu->getJoueurCourant());
				  break;
    		}
    		case 4:
    		{
					jeu->getVue().afficher2Board(jeu->getJoueurCourant(),jeu->getJoueurAutre());
    				break;
    		}
    		case 5:
    		{
					jeu->getVue().afficherPersonnage(jeu->getJoueurCourant());
					jeu->getVue().afficherPersonnageAutre(jeu->getJoueurAutre());
					
    				break;
    		}
    		case 6:
    		{
    			cout << "POUVOIR" << endl;
    		}
    		
		}
	
	return choix;



}


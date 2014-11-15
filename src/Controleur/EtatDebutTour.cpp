/**
*Fichier EtatDebutTour.cpp
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
EtatDebutTour::EtatDebutTour(Jeu* j)
{
	this->jeu = j;
}

/////////////////////////////////////////////////////////////////////////
/**
* Destructeur
*/
EtatDebutTour::~EtatDebutTour()
{
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui renvoie le jeu
*@return jeu le jeu
*/
Jeu* EtatDebutTour::getJeu()
{
  return this->jeu;  
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui termine le tour en cours, et lance le suivant
*/
void EtatDebutTour::finTour()
{
  jeu->setEtat(jeu->getEtatDebutTour());
  jeu->echangeJoueur();
  jeu->jouer();
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui termine le tour en cours, et lance le suivant
*/
int EtatDebutTour::afficherChoixEtat()
{
	int choix = -1;
	int choixcarte;
	int choixcarte1, choixcarte2;
	int pdmn = jeu->getJoueurCourant()->getPdm();
	
	cout << "\nETAT DEBUT TOUR\n" << endl;
	
	jeu->getVue().afficherChoixDebutTour();
	choix = jeu->getVue().getChoixJoueur();
		switch (choix)
		{
		    case 1: {
					jeu->getVue().afficherMain(jeu->getJoueurCourant());
					break;
		    }
		    case 2:  {
		   		jeu->getVue().afficherJouerCarte();
		   		
		   		bool bonnecarte0 = false;
    			int choixcarte0 = jeu->getVue().getChoixJoueur();	
    			int size0 = jeu->getJoueurCourant()->getMain()->size();  
		   		
		   		while ( bonnecarte0 == false )
    			{
    				if ( choixcarte0 > 0 && choixcarte0 <= size0)
    				{
    					bonnecarte0 = true;
    				}
    				else
   					{	
   						jeu->getVue().afficherJouerCarte();
   						choixcarte0 = jeu->getVue().getChoixJoueur();
   					}   				
    			}    			
		   		
		   		if ( jeu->getJoueurCourant()->getMain()->at(choixcarte0-1).getCoutmana() <= pdmn)
		   		{
		   			jeu->getJoueurCourant()->ajouterBoard(jeu->getJoueurCourant()->getMain()->at(choixcarte0-1));
		   			pdmn = pdmn - jeu->getJoueurCourant()->getMain()->at(choixcarte0-1).getCoutmana();
		   			jeu->getVue().afficherPdmnRestant(pdmn);
		   		 	jeu->getJoueurCourant()->supprimerMain(choixcarte0);
		   		 	
		   		 	if (jeu->testNoMana() == true )
		   		 	{
		   		 		jeu->setEtat(jeu->getEtatNoMana());
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
    				jeu->getVue().afficherChoixCvC();
    				bool bonnecarte1 = false;
    				bool bonnecarte2 = false;
    				choixcarte1 = jeu->getVue().getChoixJoueur();
    				choixcarte2 = jeu->getVue().getChoixJoueur();
    				int size1 = jeu->getJoueurCourant()->getBoard()->size();
    				int size2 = jeu->getJoueurAutre()->getBoard()->size();
    				
    				while ( bonnecarte1 == false &&  bonnecarte2 == false )
    				{
    					if ( choixcarte1 > 0 && choixcarte1 <= size1 && choixcarte2 > 0 && choixcarte2 <= size2 )
    					{
    						bonnecarte1 = true;
    						bonnecarte2 = true;
    					}
    					else
    					{	
    						jeu->getVue().afficherChoixCvC();
    						choixcarte1 = jeu->getVue().getChoixJoueur();
    						choixcarte2 = jeu->getVue().getChoixJoueur();
      					}   				
    				}    	
    				
    				jeu->attaqueCvC(choixcarte1, choixcarte2);
    				
    				if (jeu->testNoAttaque() == true )
    				{
    					jeu->setEtat(jeu->getEtatNoAttaque());
		   		 	}		   		 
    				break;	
    		}
    		case 7:
    		{
    				jeu->getJoueurCourant()->utiliserPouvoir();
    				
    				break;
    		}
    		
    		case 8:
    		{		
    				jeu->getVue().afficherChoixCvJ();
    				bool bonnecarte = false;
    				choixcarte1 = jeu->getVue().getChoixJoueur();	
    				int size = jeu->getJoueurCourant()->getBoard()->size();  
    				
    				while ( bonnecarte == false )
    				{
    					if ( choixcarte1 > 0 && choixcarte1 <= size)
    					{
    						bonnecarte = true;
    					}
    					else
    					{	
    						jeu->getVue().afficherChoixCvJ();
    						choixcarte1 = jeu->getVue().getChoixJoueur();
      					}   				
    				}    				
    				jeu->attaqueCvJ(choixcarte1);
    				if (jeu->testNoAttaque() == true )
    				{
    					jeu->setEtat(jeu->getEtatNoAttaque());
		   		 	}		   		 
    				break;	
    		}
		}
	
	return choix;



}


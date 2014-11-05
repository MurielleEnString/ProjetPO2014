/*
   Fichier Jeu.cpp

   Définition des méthodes de Jeu
*/


#include <iostream>
#include <sstream> // pour les conversions en chaine
#include <typeinfo>

using namespace std; // seulement dans le .cpp !

/////////////////////////////////////////////////////////////////////////

Jeu::Jeu(Joueur* j1, Joueur* j2)
{
   this->joueurCourant = j1;
   this->joueurAutre = j2;
   this->tourJoueur1 = new TourJoueur1(this);
   this->tourJoueur2 = new TourJoueur2(this);
   this->tourCourant = this->tourJoueur1;
}

/////////////////////////////////////////////////////////////////////////

Jeu::~Jeu()
{
}

/////////////////////////////////////////////////////////////////////////
Joueur* Jeu::getJoueurCourant()
{
  return this->joueurCourant;  
}

/////////////////////////////////////////////////////////////////////////
Joueur* Jeu::getJoueurAutre()
{
  return this->joueurAutre;  
}

/////////////////////////////////////////////////////////////////////////
void Jeu::echangeJoueur()
{
  Joueur* tmp = this->joueurCourant;
  joueurCourant = this->joueurAutre; 
  joueurAutre = tmp;
}

/////////////////////////////////////////////////////////////////////////
Tour* Jeu::getTourCourant()
{
  return this->tourCourant;  
}

/////////////////////////////////////////////////////////////////////////
Tour* Jeu::getTourJoueur1()
{
  return this->tourJoueur1;  
}

/////////////////////////////////////////////////////////////////////////
Tour* Jeu::getTourJoueur2()
{
  return this->tourJoueur2;  
}	

/////////////////////////////////////////////////////////////////////////
void Jeu::setTour(Tour* t)
{
	this->tourCourant = t;
}

/////////////////////////////////////////////////////////////////////////
void Jeu::finTour()
{
	this->tourCourant->finTour();
}
/////////////////////////////////////////////////////////////////////////

void Jeu::jouer()
{
	
	int pdmn = this->joueurCourant->getPersonnage().getPdm();
	if (this->joueurCourant->getPersonnage().getPdm() < 10)
	{
		this->joueurCourant->setPDM(this->joueurCourant->getPersonnage().getPdm()+1);	
	}
 	this->joueurCourant->ajouterMain(this->joueurCourant->getDeck()->tirerCarte());
  
  	
	enleverMalinvoc();
	
	vue.afficherDebutTour(joueurCourant);
	
	
	int choix = -1;
	int choixcarte;
	int choixcarte1, choixcarte2;
	
	
	

	while (choix != 0) {	
	vue.afficherChoix();
	choix = vue.getChoixActionTour();
		switch (choix)
		{
		    case 1: {
					vue.afficherMain(joueurCourant);
					break;
		    }
		    case 2:  {
		   		vue.afficherJouerCarte();
		   		choixcarte = vue.getChoixCarteAJouer();
		   		if ( this->joueurCourant->getMain()->at(choixcarte-1).getCoutmana() <= pdmn)
		   		{
		   			this->joueurCourant->ajouterBoard(this->joueurCourant->getMain()->at(choixcarte-1));
		   			pdmn = pdmn - this->joueurCourant->getMain()->at(choixcarte-1).getCoutmana();
		   			vue.afficherPdmnRestant(pdmn);
		   		 	this->joueurCourant->supprimerMain(choixcarte);
		   		 	
		   		}else{
		   			
		   			vue.afficherPasAssezDeMana();
		      }
		      break;
		    }
		    case 3: {	
				  vue.afficherBoard(joueurCourant);
				  break;
    		}
    		case 4:
    		{
					vue.afficher2Board(joueurCourant,joueurAutre);
    				break;
    		}
    		case 5:
    		{
					vue.afficherPersonnage(joueurCourant);
    				break;
    		}
    		case 6:
    		{
    				choixcarte1 = vue.getChoixCarteAJouer();
    				choixcarte2 = vue.getChoixCarteAJouer();
    				attaqueCvC(choixcarte1, choixcarte2);
    		}
		}
	}
	
	
	vue.afficherFinTour();
	this->finTour();

}
/////////////////////////////////////////////////////////////////////////
void Jeu::attaqueCvC(int index1, int index2)
{
	int pdv1,pdv2,attac1,attac2;
	
	if ( joueurCourant->getBoard()->at(index1-1).getMalinvoc() == true )
	{
		cout << "Cette carte vient d'être invoquée ! Impossible d'attaquer !" << endl;
	} else {
		
		pdv1 = joueurCourant->getBoard()->at(index1-1).getPdv();
		pdv2 = joueurAutre->getBoard()->at(index1-1).getPdv();
		attac1 = joueurCourant->getBoard()->at(index1-1).getPa();
		attac2 = joueurAutre->getBoard()->at(index1-1).getPa();
		
		joueurCourant->getBoard()->at(index1-1).setPdv(pdv1-attac2);
		joueurAutre->getBoard()->at(index1-1).setPdv(pdv2-attac1);
		
		if ( joueurCourant->getBoard()->at(index1-1).getPdv() <= 0 )
		{	
			joueurCourant->supprimerBoard(index1);
			cout << "Votre carte est tombée au combat !" << endl;
		}
		
		if ( joueurAutre->getBoard()->at(index1-1).getPdv() <= 0 )
		{	
			joueurAutre->supprimerBoard(index2);
			cout << "Vous avez triomphé de votre adversaire !" << endl;
		}
	}
	
	cout << "attaque terminée"<< endl;

}
/////////////////////////////////////////////////////////////////////////
void Jeu::enleverMalinvoc()
{
	int i,j;
	for ( i = 0; i < joueurCourant->getBoard()->size() ; i++ )
	{
		if ( joueurCourant->getBoard()->at(i).getMalinvoc() == true )
		{
			joueurCourant->getBoard()->at(i).setMalinvoc(false);
		}
	}
		
	for (j = 0; j < joueurAutre->getBoard()->size() ; j++ )
	{
		if ( joueurAutre->getBoard()->at(i).getMalinvoc() == true )
		{
			joueurAutre->getBoard()->at(i).setMalinvoc(false);
		}
	}
}
		
		
		
		
		
		



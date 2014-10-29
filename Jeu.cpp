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
   this->tourJoueur1 = new TourJoueur1(&this);
   this->tourJoueur2 = new TourJoueur2(&this);
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




/**
*Fichier Personnage.cpp
* @author Pierre Gaultier & Theo Dolez
*/


#include <iostream>
#include <sstream> // pour les conversions en chaine
#include <typeinfo>

using namespace std; // seulement dans le .cpp !

/////////////////////////////////////////////////////////////////////////
/**
* Constructeur.
* @param pdv points de vie du personnage
* @param armure armure du personnage
* @param pdm points de mana du personnage
* @param CP comportement du pouvoir heroique du personnage
*/
Personnage::Personnage()
{
	this->pdv = 30;
	this->armure = 0;
	this->pdm = 0;
	this->CP = new ComportementPouvoirGuerrier();
}

/////////////////////////////////////////////////////////////////////////
/**
* Destructeur.
*/
Personnage::~Personnage()
{
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui renvoie le nombre de points de vie du personnage
* @return pdv les points de vie du personnage
*/
int Personnage::getPdv()
{
   return this->pdv;
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui remplace les points de vie du personnage par npdv
* @param npdv les nouveaux points de vie
*/
void Personnage::setPdv(int npdv)
{
   this->pdv = npdv;
}


/////////////////////////////////////////////////////////////////////////
/**
* Methode qui renvoie le nombre de points d''armure du personnage
* @return armure les points d'armure du personnage
*/
int Personnage::getArmure()
{
   return this->armure;
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui remplace les points d'armure du personnage par narmure
* @param narmure les nouveaux points d'armure
*/
void Personnage::setArmure(int narmure)
{
   this->armure = narmure;
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui renvoie le nombre de points de mana du personnage
* @return mana les points de mana du personnage
*/
int Personnage::getPdm()
{
   return this->pdm;
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui remplace les points de mana du personnage par npdv
* @param npdm les nouveaux points de mana
*/
void Personnage::setPdm(int npdm)
{
   this->pdm = npdm;
}

/////////////////////////////////////////////////////////////////////////
/*** Methode qui renvoie une chaine de caracteres qui decrit le personnage
*@return String definition du personnage
*/
string  Personnage::toString()
{
   string Spdv = static_cast<ostringstream*>( &(ostringstream() << this->pdv) )-> str();
   string Sarmure = static_cast<ostringstream*>( &(ostringstream() << this->armure) )-> str();
   string Spdm = static_cast<ostringstream*>( &(ostringstream() << this->pdm) )-> str();
   
   return "pdv: " +Spdv+ " armure: " +Sarmure+ " pdm: " +Spdm;
}


/////////////////////////////////////////////////////////////////////////
/**
* Methode qui renvoie le comportement du pouvoir du personnage
* @return CP le comportement du pouvoir du personnage
*/
ComportementPouvoir* Personnage::getCP()
{
   return this->CP;
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui remplace le comportement du pouvoir par CP
* @param CP le nouveau comportement
*/
void Personnage::setCP(ComportementPouvoir* CP)
{
   this->CP = CP;
}

/////////////////////////////////////////////////////////////////////////
/**
* Methode qui applique le pouvoir du personnage
* @return //a changer
*/
std::string Personnage::utiliserPouvoir()
{
   return this->CP->pouvoir();
}



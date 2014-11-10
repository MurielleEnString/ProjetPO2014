/**
* Fichier FinDeJeu.hpp
* @author Pierre Gaultier & Theo Dolez
*/

#ifndef FinDeJeu_HPP
#define FinDeJeu_HPP
#include <string> // pour le type std::string
#include "Observer.hpp"
#include "Sujet.hpp"



/******************************************************************************/

class FinDeJeu : public Observer
{

	private:
		Jeu* suj;
		
		
	
	public:
		FinDeJeu(Jeu* j);
		~FinDeJeu();
		void actualiser();
		
		
		
		
};

#include "../../src/Controleur/FinDeJeu.cpp"
#endif // Observer_HPP		
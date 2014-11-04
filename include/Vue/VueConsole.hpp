/*
   Fichier VueConsole.hpp

*/

#ifndef VueConsole_HPP
#define VueConsole_HPP
#include <string> // pour le type std::string
#include "../Modele/Joueur/Joueur.hpp"




/******************************************************************************/

class VueConsole
{


	private:

 
	
	public:
		VueConsole();
		~VueConsole();
		
		int getChoixActionTour();
		int getChoixCarteAJouer();

		void afficherMain(Joueur* j);
		void afficherChoix();
		void afficherBoard(Joueur* j);
		void afficherPersonnage(Joueur* j);
		void afficherDebutTour(Joueur* j);
		void afficherFinTour();
		void afficherJouerCarte();
		void afficherPdmnRestant(int i);
		void afficherPasAssezDeMana();
};
#include "../../src/Vue/VueConsole.cpp"
#endif // JEU_HPP		
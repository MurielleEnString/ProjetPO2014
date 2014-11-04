#include <string> // pour les chaines de caracteres
#include <iostream> // pour les entrées/sorties
#include <fstream> // pour la gestion des flux de fichier
#include <sstream> // pour la gestion des flux de string
using namespace std;
#include "../Modele/Joueur/Joueur.hpp"
#include "Jeu.hpp"
int main()
{


	Personnage guerrier;
	Personnage guerriera;
	
	Joueur* Pierre = new Joueur("Pierre", guerrier,"DeckGuerrier.txt");
	Joueur* Theo = new Joueur("Théo", guerriera,"DeckGuerrier.txt");
	
	Jeu* game = new Jeu(Pierre, Theo);
	

	
	game->jouer();
	
	
	/*
	game->finTour();
	
	cout << game->getJoueurCourant()->getNom() << endl;
	cout << game->getJoueurAutre()->getNom() << endl;*/
	
	
	
	
	
	
	
	





  return 0;
}
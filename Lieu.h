#ifndef LIEU_H
#define LIEU_H

#include <string>
#include <vector>


class Lieu {

	private:

        //variables
		std::string _nom;
		std::string _description;
		int _difficulte;
		std::vector<int> _mouvementsPossibles;
		bool _campement;





	public:
		
        //constructeurs		
		Lieu();

		Lieu(std::string name, std::string description, int difficult, std::vector<int> mouvements);
		
		//constructeur supplémentaire pour les lieux avec campements naturels
		Lieu(std::string name, std::string description, int difficult, std::vector<int> mouvements, bool camp);
		
		
		//méthodes
		std::string getNom();
		
		
		std::string getDescription();
		
		std::vector<int> getMouvementsPossibles();
		
		int getDifficulte();
		
		bool getCampement();	

		void poserCampement();
		
		void reduireDiff();



		
		
};





#endif




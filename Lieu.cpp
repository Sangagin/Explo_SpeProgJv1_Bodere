#ifndef LIEU_CPP
#define LIEU_CPP

#include "Lieu.h"

#include <iostream>


Lieu::Lieu() : _nom("Petaouchnok"), _description("un trou paumé"), _difficulte(1) {
    _mouvementsPossibles = std::vector<int>(3, 1);


}


Lieu::Lieu(std::string name, std::string description, int difficult, std::vector<int> mouvements) : _nom(name), _description(description), _difficulte(difficult) {
    _mouvementsPossibles = mouvements;
    _campement=false;
    }


Lieu::Lieu(std::string name, std::string description, int difficult, std::vector<int> mouvements, bool camp) : _nom(name), _description(description), _difficulte(difficult) {
    _mouvementsPossibles = mouvements;
    _campement=true;
    }
    
    

std::string Lieu::getNom(){
    return _nom;
}

std::string Lieu::getDescription(){
    return _description;
}

std::vector<int> Lieu::getMouvementsPossibles(){
    return _mouvementsPossibles;
}

int Lieu::getDifficulte(){
    return _difficulte;
}

bool Lieu::getCampement(){
    return _campement;
}

void Lieu::poserCampement(){
    _campement=true;
    _description += " Il y a un campement dans cette zone.";
    
}

void Lieu::reduireDiff(){
    _difficulte=_difficulte/2;
}











#endif // !"LIEU_CPP"

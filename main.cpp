

#include "Lieu.h"
#include <string>
#include <iostream>



//exo 1
/*
int main()
{

    std::string choix;


    std::cout << "Vous avez le choix entre deux destinations :\n";
    std::cout << "(1) - Berlin\n";
    std::cout << "(2) - Tokyo\n";
    std::cout << "Entrez le chiffre de la destination choisie\n";

    std::cin >> choix;


    while (choix != "1" && choix != "2") {
        std::cout << "Vous avez entre un chiffre non valide.\n";
        std::cout << "Veuillez entrer un chiffre valide.\n";
        std::cin >> choix;



    }


    std::cout << "Vous avez choisi la destination " + (choix) + "\n";

    if (choix == "1") {
        std::cout << "Il s'agit de Berlin. \n";
    }
    else {
        std::cout << "Il s'agit de Tokyo. \n";
    }

}



*/

//exo 2 

/*
int main()
{

    std::string choix;
    std::string nomDestinations[2] = {"Berlin","Tokyo"};

    std::cout << "Vous avez le choix entre deux destinations :\n";
    for (int i = 0; i < 2; i++) {
        std::cout << "Il s'agit de " + nomDestinations[i] + "\n";
    }



    std::cout << "Entrez le nom de la destination choisie\n";

    std::cin >> choix;


    while (choix != nomDestinations[0] && choix != nomDestinations[1] ) {
        std::cout << "Vous avez entre un nom non valide.\n";
        std::cout << "Veuillez entrer un nom valide. Attention aux majuscules !\n";
        std::cin >> choix;



    }

    std::cout << "Vous avez choisi la destination " + (choix)+"\n";


}

*/



//exo 3 à 7



int main(){



//déclaration des variables
    Lieu lieu1 = Lieu("debut du jeu", "Zone des debutants, tout est facile ici. Il y a un campement naturel ici.", 2, {2,3},true);
    Lieu lieu2 = Lieu("les terre du niveau du milieu", "Les choses se corsent ici !", 10, {1,3});
    Lieu lieu3 = Lieu("fin du monde", "C'est la fin du monde !", 18, {1,2});

    Lieu listLieu[3]={lieu1,lieu2,lieu3};
    int lieuActuel=0;
    std::string choix;
    bool fin =false;

    int energie =100;
    int coutEnergie=0;


    std::cout << "Vous commencez votre aventure dans la zone de départ.\n";
    std::cout << "Le niveau de danger de cette zone est de 2.\n";
    std::cout << "Cette zone possède un campement naturel, donc n'hésitez pas à revenir lors de votre quête si vous êtes fatigué !\n\n";
    
    
    
    
    while(fin!=true && energie>0){
        
        //afficher les choix d'actions
        std::cout << "Il vous reste " + std::__cxx11::to_string(energie) + " d'energie\n\n";
        std::cout << "Que souhaitez vous faire maintenant ?\n";
        std::cout << "(1) - Mettre fin à mon voyage\n" ;
        std::cout << "(2) - Me déplacer\n" ;
        
        //choix du campement, s'il n'y en a pas déjà un
        if(!listLieu[lieuActuel].getCampement()){
            std::cout << "(3) - Poser un campement\n";
        }
        else{
            //si il n'y a pas de campement on peut en poser un, sinon on peut se reposer   
            std::cout << "(4) - Se reposer\n";
            
            
        }
        
        
        std::cout << "\n";
        std::cin >> choix;
        
        //vérification du choix, si valide ou non, en fonction du campement ou non
        if(!listLieu[lieuActuel].getCampement()){

            while (choix != "1" && choix != "2" && choix != "3") {
                std::cout << "Vous avez entre un chiffre non valide.\n";
                std::cout << "Veuillez entrer un chiffre valide.\n";
                std::cin >> choix;
        
            }
        }
        else{
            while (choix != "1" && choix != "2" && choix != "4" ) {
                std::cout << "Vous avez entre un chiffre non valide.\n";
                std::cout << "Veuillez entrer un chiffre valide.\n";
                std::cin >> choix;
        
            }
        }
        
        //fin du jeu
        if(choix=="1"){
            std::cout << "Au revoir !\n";
            fin=true;
            break;
        } 
        
        
        //action se déplacer
        else if(choix=="2"){
            std::cout << "Vous avez le choix de vous déplacer les destinations suivantes :\n\n";

            //récupération des déplacements possibles
            std::vector<int> listPossible = listLieu[lieuActuel].getMouvementsPossibles();

            //affichage des choix
            //dans le cadre du dernier exo, le "2" ci dessous est à modifier par la longueur totale de listPossible
            for (int i = 0; i < 2; i++) {
                std::cout << "(";
                std::cout <<  listPossible[i] ;
                std::cout << ") - " +listLieu[listPossible[i]-1].getNom() + " (niveau de danger de " + std::__cxx11::to_string(listLieu[listPossible[i]-1].getDifficulte()) + ")\n";
                //aucune idée de pourquoi, mais ça plante si je mets ça en une seul ligne
            
            }

            std::cout << "Entrez le numéro de la destination choisie\n";
    
            std::cin >> choix;
    
            //test de validité de présence du choix dans la liste
            //dans le cadre du dernier exo, le test ci dessous est à modifier par un parcours de listPossible avec la fonction find()

            while (stoi(choix) != listPossible[0] && stoi(choix) != listPossible[1] ) {
            
                std::cout << "Vous avez entre une destination non valide.\n";
                std::cout << "Veuillez entrer une destination valide.\n";
                std::cin >> choix;
                
                
            }
            
            //vérification de l'energie restante, si la zone visée n'est pas au dessus de l'energie restante
            if ( energie < listLieu[stoi(choix)-1].getDifficulte()) {
                //si pas assez d'energie, retour aux choix d'action
                std::cout << "Vous n'avez pas assez d'energie pour ça !\n";
                std::cout << "Vous décidez donc de rester sur la place pour réfléchir à la suite de vos actions.\n\n";
            }
            else{

        
                //sinon le déplacement à lieu. Si le joueur à mal calculé, et que le déplacement le fait passer sous 0, c'est Game Over
                energie=energie-(listLieu[stoi(choix)-1].getDifficulte())-listLieu[lieuActuel].getDifficulte();
                if(energie<=0){
                    std::cout << "C'était le voyage de trop. Vous n'avez plus d'energie, et vous êtes mort.";
                }
                else{
                    std::cout << "Vous avez choisi la destination " + (choix)+"\n\n";
                    std::cout << listLieu[stoi(choix)-1].getDescription();
                    std::cout << "\n\n";
                }
                
                lieuActuel=stoi(choix)-1;
                
                

            }
        }
        
        else if(choix=="3"){
            
            //action de rajouter un campement
            listLieu[lieuActuel].poserCampement();
            std::cout << "Vous posez un campement dans cette zone. Vous pourrez maintenant y choisir l'option se reposer, et le niveau de difficulté de la zone est réduite de moité\n\n";
            listLieu[lieuActuel].reduireDiff();
            
            
        }
        else{
            
            //action de se reposer
            energie+=50;
            if(energie>100){
                energie=100;
            }
            
        }
        
        
        
        
        
        
        
        
        
    
    
        
        
        
        
    }
    


}




//exo 5 




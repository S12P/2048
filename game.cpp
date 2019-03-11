#include "game.h"

Game::Game(){
    /*******************************************************************************
     *
     *  Fonction qui permet de jouer
     *
     *
     * *****************************************************************************/
    load();
    win = true;
    // TODO

}

Game::~Game(){
    /*******************************************************************************
     *
     *  Destructeur, on sauvegarde
     *
     *
     * *****************************************************************************/
    save();
    // TODO
}


int Game::random(){
    /*******************************************************************************
     *
     *  permet de générer un nombre aléatoire entre 0 inclus et 4 exclus
     *
     * *****************************************************************************/
    int nb = 0;
    nb = rand()%4;
    return nb;
}

void Game::newgame(){
    /*******************************************************************************
     *
     *  newgame lance une nouvelle partie
     *
     *
     * *****************************************************************************/
    int score = 0;
    Game();
}

void Game::save(){
    /*******************************************************************************
     *
     *  save permet de charger les résultats et la partie en cours.
     *
     * *****************************************************************************/
    string esp = " ";
    ofstream fichier2("data/.data.txt", ios::out | ios::trunc);

    if (end) {score = 0;}

    if(!fichier2) {EXIT_FAILURE;}
    fichier2 << score << esp << best << endl;
    for (int i = 0; i < 15; i++){
        fichier2 << list[i] << esp;
    }
    fichier2 << list[15] << endl;
    fichier2.close();
}

void Game::load(){
    /*******************************************************************************
     *
     *  load permet de charger les anciens résultats et l'ancienne partie
     *
     *  si il y en avait une en cours. Si le fichier .data n'existe pas on le crée
     *
     * *****************************************************************************/


    string esp = " ";
    ifstream fichier("data/.data.txt", ios::in);  // fichier cacher

    if(fichier) { // si l'ouverture a réussi
        string ligne;
        while(getline(fichier, ligne))  {

            fichier >> score >> best;
            for (int i = 0; i< 16; i++){
                fichier >> list[i];
            }
        }

        fichier.close();
    }
    else {
        ofstream fichier2("data/.data.txt", ios::out | ios::trunc);

        if(!fichier2) {EXIT_FAILURE;}
        string init = "0 0\n";
        string init2 = "0 0 0 0 0 0 0 0 0 0 0 0\n";
        fichier2 << init << init2;
        fichier2.close();

    }
}

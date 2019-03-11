#include "game.h"

Game::Game(){
    score = 0;
    best = 0;
    for (int i = 0; i < 16; i++){
        list[i] = 0;
    }
    win = true;

}



int Game::random(){
    //TODO
    return 0;
}

void Game::newgame(){
    int score = 0;
            // TODO
}

void Game::save(){
    string esp = " ";
    ofstream fichier2("data/.data.txt", ios::out | ios::trunc);

    if(!fichier2) {EXIT_FAILURE;}
    fichier2 << score << esp << best << endl;
    for (int i = 0; i < 15; i++){
        fichier2 << list[i] << esp;
    }
    fichier2 << list[15] << endl;
    fichier2.close();
}

void Game::load(){
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

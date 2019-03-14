#include "game.h"

void Game::declareQML() {
    qmlRegisterType<Game>("MyControls", 3, 14, "Game");
}



qint64 Game::give_score(){
    qint64 n = score;
    return n;
}

qint64 Game::give_best(){
    qint64 n = best;
    return n;
}

void Game::actualize(){
    give_best();
    give_score();
}


Game::Game() : QObject () {
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


int Game::random(vector<int> v){
    /*******************************************************************************
     *
     *  permet de générer un nombre aléatoire entre 0 inclus et 16 exclus
     *
     * *****************************************************************************/
    int len = v.size();
    int nb = rand()%len;
    return v[nb];
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
    ofstream fichier2(path, ios::out | ios::trunc);

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
    ifstream fichier(path, ios::in);  // fichier cacher
    if(fichier) { // si l'ouverture a réussi
        fichier >> score >> best;
        for (int i = 0; i< 16; i++){
            fichier >> list[i];
        }

        fichier.close();
    }
    else {


        ofstream fichier2(path, ios::out | ios::trunc);

        if(!fichier2) {EXIT_FAILURE;}
        string init = "0 0\n";
        string init2 = "0 0 0 0 0 0 0 0 0 0 0 0\n";
        fichier2 << init << init2;
        fichier2.close();

    }
    actualize();

}

void Game::add_score(int a){
    score += a;
}

int Game::power(int n){
    return 2 << (n-1);
}

int Game::empty_case(){
    vector<int> v;
    for (int i = 0; i < 16; i++){
        if (list[i] == 0){
            v.push_back(i);
        }
    }
    return random(v);
}

int Game::afficher_score(){
    cout << score << endl;
}

void Game::afficher_data(){
    cout << score << " " << best << endl;
    for (int i = 0; i < 16; i++){
        cout << list[i] << endl;
    }
}

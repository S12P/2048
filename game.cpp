#include "game.h"

//void Game::declareQML() {
//    qmlRegisterType<Game>("MyControls", 3, 14, "Game");
//}



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
    int x1 = random_init();
    int x2 = random_init();
    list[x1] = 2;
    list[x2] = 2;
    update();

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

int Game::random_init(){
    /*******************************************************************************
     *
     *  permet de générer un nombre aléatoire entre 0 inclus et 16 exclus
     *
     * *****************************************************************************/
    int nb = rand()%16;
    return nb;
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
    score = 0;
    update();
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

void Game::afficher_score(){
    cout << score << endl;
}

void Game::afficher_data(){
    cout << score << " " << best << endl;
    for (int i = 0; i < 16; i++){
        cout << list[i] << endl;
    }
}



void Game::verify_right_mvt(){
    /**************************************
     * On verifie si il y a des 0 pour pouvoir deplacer sur la droite
     *  ou si deux cases sont les memes
     * **************************************/
    int n;
    for (int i = 0; i < 4; i++){
        bool first = true;
        for (int j = 0; j < 4; j++){
            n = j + 4 * i;
            if (first){
                if (list[n] == 0){
                    first = false;
                }
            }
            else{
                if (list[n] == 0){
                    l_right[i] = true;
                }
            }
            if (j != 3){
                if (list[n] == list[n+1]){
                    l_right2[i] = true;
                }
            }
        }
    }
}

void Game::verify_left_mvt(){
    int n;
    for (int i = 3; i >= 0; i--){
        bool first = true;
        for (int j = 3; j >= 0; j--){
            n = j + 4 * i;
            if (first){
                if (list[n] == 0){
                    first = false;
                }
            }
            else{
                if (list[n] == 0){
                    l_left[i] = true;
                }
            }
            if (j != 0){
                if (list[n] == list[n-1]){
                    l_left2[i] = true;
                }
            }
        }
    }
}

void Game::verify_low_mvt(){
    int n;
    for (int i = 0; i < 4; i--){
        bool first = true;
        for (int j = 0; j < 4; j--){
            n = i + 4 * j;
            if (first){
                if (list[n] == 0){
                    first = false;
                }
            }
            else{
                if (list[n] == 0){
                    l_low[i] = true;
                }
            }
            if (list[i] != 0){
                if (list[n] == list[i + 4 * (j - 1)]){
                    l_low2[i] = true;
                }
            }
        }
    }
}

void Game::verify_top_mvt(){
    int n;
    for (int i = 3; i >= 0; i--){
        bool first = true;
        for (int j = 3; j >= 0; j--){
            n = i + 4 * j;
            if (first){
                if (list[n] == 0){
                    first = false;
                }
            }
            else{
                if (list[n] == 0){
                    l_top[i] = true;
                }
            }
            if (list[i] != 3){
                if (list[n] == list[i + 4 * (j + 1)]){
                    l_top2[i] = true;
                }
            }
        }
    }
}

void Game::shift_right(int a){
    int b = a + 3;
    for (int i = b; i >= a; i--){
        if (list[i] != 0){
            int k = i;
            while(k < b){
                if (list[k+1] == 0){
                    list[k+1] = list[k];
                    list[k] = 0;
                    k += 1;
                }
                else{
                    //k+=1; // a changer
                    break;
                }
            }
        }
    }
    for (int i = b; i > a; i--){
        if (list[i] == list[i-1]){
            list[i] *= 2;
            list[i-1] = 0;
        }
    }
    for (int i = b; i >= a; i--){
        if (list[i] != 0){
            int k = i;
            while(k < b){
                if (list[k+1] == 0){
                    list[k+1] = list[k];
                    list[k] = 0;
                    k += 1;
                }
                else{
                    //k+=1; // a changer
                    break;
                }
            }
        }
    }
}


// on decale les 0 et apres on verifie si 2 cases sont pareilles
void Game::right_mvt(){
    cout << "wesh" << endl;
    verify_right_mvt();
    bool l1p = l_right[0];
    bool l2p = l_right[1];
    bool l3p = l_right[2];
    bool l4p = l_right[3];
    bool l1n = l_right2[0];
    bool l2n = l_right2[1];
    bool l3n = l_right2[2];
    bool l4n = l_right2[3];
    if (l1p || l2p || l3p || l4p || l1n || l2n || l3n || l4n){
        if (l1p || l1n){
            shift_right(0);
        }
        if (l2p || l2n){
            shift_right(4);
        }
        if (l3p || l3n){
            shift_right(8);
        }
        if (l4p || l4n){
            shift_right(12);
        }
    }
    update();
}

void Game::left_mvt(){
    verify_left_mvt();
    bool l1p = l_left[0];
    bool l2p = l_left[1];
    bool l3p = l_left[2];
    bool l4p = l_left[3];
    bool l1n = l_left2[0];
    bool l2n = l_left2[1];
    bool l3n = l_left2[2];
    bool l4n = l_left2[3];
    if (l1p || l2p || l3p || l4p || l1n || l2n || l3n || l4n){
        //TODO
    }
}

void Game::top_mvt(){
    verify_top_mvt();
    bool l1 = l_top[0];
    bool l2 = l_top[1];
    bool l3 = l_top[2];
    bool l4 = l_top[3];
    if (l1 || l2 || l3 || l4){
        //TODO
    }
}

void Game::low_mvt(){
    verify_low_mvt();
    bool l1 = l_low[0];
    bool l2 = l_low[1];
    bool l3 = l_low[2];
    bool l4 = l_low[3];
    if (l1 || l2 || l3 || l4){
        //TODO
    }
}

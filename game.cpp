#include "game.h"


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

bool Game::give_end(){
    return end;
}


Game::Game(QObject *parent) : QObject (parent) {
    /*******************************************************************************
     *
     *  Fonction qui permet de jouer
     *
     *
     * *****************************************************************************/
    load();
    change_color();
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
    unsigned long len = v.size();
    unsigned long nb = rand()%len;
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
    end = false;
    win_end = false;
    list = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    list[empty_case()] = 2;
    list[empty_case()] = 2;
    change_color();
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
        newgame();

    }
}

void Game::add_score(int a){
    /*******************************************************************************
     *
     *  On ajoute a au score
     *
     *
     * *****************************************************************************/
    score += a;
    if (best < score){
        best = score;
    }
}

int Game::power(int n){
    return 2 << (n-1);
}

int Game::empty_case(){
    /*******************************************************************************
     *
     *  On prend l'indice des cases vides du jeu (ie == 0) et on choisit
     *
     *  aléatoirement un indice pour y mettre le nouveau 2 par la suite
     *
     * *****************************************************************************/
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
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cout << list[j + i * 4] << " ";
        }
        cout << endl;
    }
}



void Game::verify_right_mvt(){
    /**************************************
     *
     * l_right[i] permet de savoir si on peut deplacer a droite sur la ligne i car il y a des 0
     *
     * l_right2[i] permet de savoir si on peut deplacer a droite sur la ligne i car il y a des cases qui peuvent fusionner
     *
     *
     * Pour faire un mouvement a droite on part de la gauche tant qu'il y a des 0 on continue a parcourir la liste
     * des que l'on a une valuer != de 0 le first devient false et cela permet de voir si il y a des 0 par la suite
     * si il y a un ou plusieurs 0 entre deux valeurs non nulles alors on peut se deplacer a droite sur la ligne i
     * l_right[i] permet de savoir si on peut deplacer a droite sur la ligne i car il y a des 0
     *
     * Ensuite on regarde si il y a des valeurs non nulles egale ainsi on pourra fusionner les deux cases et donc se deplacer
     *
     * **************************************/
    for (int i = 0; i < 4; i++){
        l_right[i] = false;
        l_right2[i] = false;
    }
    int n;
    for (int i = 0; i < 4; i++){
        bool first = true;
        for (int j = 0; j < 4; j++){
            n = j + 4 * i;
            if (first){
                if (list[n] != 0){
                    first = false;
                }
            }
            else{
                if (list[n] == 0){
                    l_right[i] = true;
                }
            }
            if (j != 3){
                if (list[n] == list[n+1] && list[n] != 0){
                    l_right2[i] = true;
                }
            }
        }
    }
}

void Game::verify_left_mvt(){

   /***********************************************
    * Pareil que pour verify_right_mvt() mais on part de la droite
    *
    *
    * *********************************************/
    for (int i = 0; i < 4; i++){
        l_left[i] = false;
        l_left2[i] = false;
    }
    int n;
    for (int i = 3; i >= 0; i--){
        bool first = true;
        for (int j = 3; j >= 0; j--){
            n = j + 4 * i;
            if (first){
                if (list[n] != 0){
                    first = false;
                }
            }
            else{
                if (list[n] == 0){
                    l_left[i] = true;
                }
            }
            if (j != 0){
                if (list[n] == list[n-1] && list[n] != 0){
                    l_left2[i] = true;
                }
            }
        }
    }
}

void Game::verify_low_mvt(){
    /***********************************************
     * Pareil que pour verify_right_mvt() mais on part du haut
     *
     *
     * *********************************************/
    for (int i = 0; i < 4; i++){
        l_low[i] = false;
        l_low2[i] = false;
    }
    int n;
    for (int j = 0; j < 4; j++){
        bool first = true;
        for (int i = 0; i < 4; i++){
            n = j + 4 * i;
            if (first){
                if (list[n] != 0){
                    first = false;
                }
            }
            else{
                if (list[n] == 0){
                    l_low[j] = true;
                }
            }
            if (i != 0){
                if (list[n] == list[n - 4] && list[n] != 0){
                    l_low2[j] = true;
                }
            }
        }
    }
}

void Game::verify_top_mvt(){
    /***********************************************
     * Pareil que pour verify_right_mvt() mais on part du bas
     *
     *
     * *********************************************/
    for (int i = 0; i < 4; i++){
        l_top[i] = false;
        l_top2[i] = false;
    }
    int n;
    for (int j = 3; j >= 0; j--){
        bool first = true;
        for (int i = 3; i >= 0; i--){
            n = j + 4 * i;
            if (first){
                if (list[n] != 0){
                    first = false;
                }
            }
            else{
                if (list[n] == 0){
                    l_top[j] = true;
                }
            }
            if (i != 3){
                if (list[n] == list[n + 4] && list[n] != 0){
                    l_top2[j] = true;
                }
            }
        }
    }
}

void Game::shift_right(int a){
    /******************************************************
     * On opere en trois etapes:
     * - on decale a droite tant qu'il y a des 0 entre deux valeurs non nulles
     * - on fusionne les cases vers la droite si on peut
     * - on decale a droite tant qu'il y a des 0 entre deux valeurs non nulles
     *
     * ******************************************************/
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
                    break;
                }
            }
        }
    }
    for (int i = b; i > a; i--){
        if (list[i] == list[i-1]){
            list[i] *= 2;
            add_score(list[i]);
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
                    break;
                }
            }
        }
    }
}

void Game::shift_left(int a){
    int b = a + 3;
    for (int i = a; i <= b; i++){
        if (list[i] != 0){
            int k = i;
            while(k > a){
                if (list[k-1] == 0){
                    list[k-1] = list[k];
                    list[k] = 0;
                    k -= 1;
                }
                else{
                    break;
                }
            }
        }
    }
    for (int i = a; i < b; i++){
        if (list[i] == list[i+1]){
            list[i] *= 2;
            add_score(list[i]);
            list[i+1] = 0;
        }
    }
    for (int i = a; i <= b; i++){
        if (list[i] != 0){
            int k = i;
            while(k > a){
                if (list[k-1] == 0){
                    list[k-1] = list[k];
                    list[k] = 0;
                    k -= 1;
                    afficher_data();
                }
                else{
                    break;
                }
            }
        }
    }
}

void Game::shift_low(int a){
    for (int n = 3; n >= 0; n--){
        int i = a + n*4;
        if (list[i] != 0){
            int k = i;
            int kp = a + (n + 1)*4;
            while(k < a + 3*4){
                if (list[kp] == 0){
                    list[kp] = list[k];
                    list[k] = 0;
                    k += 4;
                    kp += 4;
                }
                else{
                    break;
                }
            }
        }
    }
    for (int n = 3; n > 0; n--){
        int i = a + n*4;
        int im = a + (n - 1)*4;
        if (list[i] == list[im]){
            list[i] *= 2;
            add_score(list[i]);
            list[im] = 0;
        }
    }
    for (int n = 3; n >= 0; n--){
        int i = a + n*4;
        if (list[i] != 0){
            int k = i;
            int kp = a + (n + 1)*4;
            while(k < a + 3*4){
                if (list[kp] == 0){
                    list[kp] = list[k];
                    list[k] = 0;
                    k += 4;
                }
                else{
                    break;
                }
            }
        }
    }
}

void Game::shift_top(int a){
    for (int n = 0; n <= 3; n++){
        int i = a + n*4;
        if (list[i] != 0){
            int k = i;
            int km = a + (n - 1)*4;
            while(k > a){
                if (list[km] == 0){
                    list[km] = list[k];
                    list[k] = 0;
                    k -= 4;
                    km -= 4;
                }
                else{
                    break;
                }
            }
        }
    }
    for (int n = 0; n < 3; n++){
        int i = a + n * 4;
        int ip = a + (n + 1) * 4;
        if (list[i] == list[ip]){
            list[i] *= 2;
            add_score(list[i]);
            list[ip] = 0;
        }
    }
    for (int n = 0; n <= 3; n++){
        int i = a + n*4;
        if (list[i] != 0){
            int k = i;
            int km = a + (n - 1)*4;
            while(k > a){
                if (list[km] == 0){
                    list[km] = list[k];
                    list[k] = 0;
                    k -= 4;
                    km -= 4;
                }
                else{
                    break;
                }
            }
        }
    }
}


void Game::right_mvt(){
    /**********************************
     * On verifie si l'on a perdu et gagné
     * on fait tous les mouvements possible à droite
     * si on peut on prend une cases aléatoirement parmis celle qui sont vide et on y met un 2
     *
     * **********************************/
    lose();
    bool l1p = l_right[0];
    bool l2p = l_right[1];
    bool l3p = l_right[2];
    bool l4p = l_right[3];
    bool l1n = l_right2[0];
    bool l2n = l_right2[1];
    bool l3n = l_right2[2];
    bool l4n = l_right2[3];
    verify_right_mvt();
    shift_right(0);
    shift_right(4);
    shift_right(8);
    shift_right(12);
    if (l1p || l2p || l3p || l4p || l1n || l2n || l3n || l4n){
        list[empty_case()] = 2;
        change_color();
        update();
    }
}

void Game::left_mvt(){
    lose();
    verify_left_mvt();
    bool l1p = l_left[0];
    bool l2p = l_left[1];
    bool l3p = l_left[2];
    bool l4p = l_left[3];
    bool l1n = l_left2[0];
    bool l2n = l_left2[1];
    bool l3n = l_left2[2];
    bool l4n = l_left2[3];
    shift_left(0);
    shift_left(4);
    shift_left(8);
    shift_left(12);
    if (l1p || l2p || l3p || l4p || l1n || l2n || l3n || l4n){
        list[empty_case()] = 2;
        change_color();
        update();
    }
}

void Game::top_mvt(){
    lose();
    verify_top_mvt();
    bool l1p = l_top[0];
    bool l2p = l_top[1];
    bool l3p = l_top[2];
    bool l4p = l_top[3];
    bool l1n = l_top2[0];
    bool l2n = l_top2[1];
    bool l3n = l_top2[2];
    bool l4n = l_top2[3];
    shift_top(0);
    shift_top(1);
    shift_top(2);
    shift_top(3);
    if (l1p || l2p || l3p || l4p || l1n || l2n || l3n || l4n){
        list[empty_case()] = 2;
        change_color();
        update();
    }
}

void Game::low_mvt(){
    lose();
    verify_low_mvt();
    bool l1p = l_low[0];
    bool l2p = l_low[1];
    bool l3p = l_low[2];
    bool l4p = l_low[3];
    bool l1n = l_low2[0];
    bool l2n = l_low2[1];
    bool l3n = l_low2[2];
    bool l4n = l_low2[3];
    shift_low(0);
    shift_low(1);
    shift_low(2);
    shift_low(3);
    if (l1p || l2p || l3p || l4p || l1n || l2n || l3n || l4n){
        list[empty_case()] = 2;
        change_color();
        update();
    }
}

void Game::lose(){
    /*************************
     *  On regarde si on gagné avec win() ou perdu on verifiant juste les listes de bool qui indique les possibilités
     *
     * si toutes les vides sont nulles alors c'est la fin du jeu
     *
     *
     * *************************/
    win();
    afficher_data();
    verify_low_mvt();
    verify_top_mvt();
    verify_left_mvt();
    verify_right_mvt();
    bool inter[4] = {false, false, false, false};
    for (int i = 0; i < 4; i++){
        if (!(l_low[i] || l_low2[i] || l_left[i] || l_left2[i] || l_right[i] || l_right2[i] || l_top[i] || l_top2[i] )){
            inter[i] = true;
            cout << "i " << i << " " <<inter[i] << endl;
        }
    }
    if ((inter[0] && inter[1]) && (inter[2] && inter[3])){
        end = true;
    }
    update();
    cout << "end :" << end << endl;
}

void Game::win(){
    /***********************************
     * Si une valeur de list = 2048 alors le jeu est fini le joueur a gagné
     *
     * ***********************************/
    for (int i = 0; i < 16; i++){
        if (list[i] == 2048){
            win_end = true;
        }
    }
}

bool Game::give_win(){
    return win_end;
}

void Game::change_color(){
    /***********************************
     * Permet de changer la couleur de la case suivant sa valeur
     *
     * ***********************************/
    for (int i = 0; i < 16; i++){
        if (list[i] == 0){
            lcolor[i] = defcolor[0];
        }
        else{
            int c = int(log2(list[i]));
            lcolor[i] = defcolor[c];
        }
    }
}


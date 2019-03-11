#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include <QObject>
#include <QDebug>
#include <QVector>
#include <QStringList>
#include <QList>

#include <cstdlib>
#include <ctime>

using namespace std;


class Game {//: public QObject {
    //Q_OBJECT
public:
    //explicit Game(QObject *parent = 0);
    Game();
    ~Game(); // destructeur
    int random(); // nombre aléatoire
    void newgame(); // nouvelle partie
    void save(); // sauvegarder données
    void load(); // recuperer données


private:

    int score; // score actuel
    int best; // meilleur score
    bool win; // gagnant ?
    bool end; // fin partie ?
    int list[16]; // liste des valeurs des 16 cases


};

#endif // GAME_H

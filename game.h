#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>


#include <QObject>
#include <QDebug>
#include <QVector>
#include <QStringList>
#include <QList>
#include <QFile>
#include <QFileInfo>
#include <QCoreApplication>
#include <QDir>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QApplicationStateChangeEvent>
#include <QFileDialog>




using namespace std;


class Game {//: public QObject {
    //Q_OBJECT
public:
    //explicit Game(QObject *parent = 0);
    Game();
    ~Game(); // destructeur
    int random(vector<int> v); // nombre aléatoire
    void newgame(); // nouvelle partie
    void save(); // sauvegarder données
    void load(); // recuperer données
    void add_score(int a); //augmente le score
    int power(int n); // calcule puissance de deux
    int empty_case();
    int afficher_score();
    void afficher_data();


private:

    int score; // score actuel
    int best; // meilleur score
    bool win; // gagnant ?
    bool end; // fin partie ?
    int list[16]; // liste des valeurs des 16 cases
    fstream data;
    string path = "data.txt";


};

#endif // GAME_H

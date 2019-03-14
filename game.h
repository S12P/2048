#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>


#include <QObject>
#include <QString>
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
#include <QtQml>
#include <QApplication>
#include <QtGlobal>




using namespace std;




class Game : public QObject {
            Q_OBJECT


public:
    Q_INVOKABLE qint64 give_score();
    Q_INVOKABLE qint64 give_best();
    static void declareQML();
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
    void actualize();

private:

    int score = 0; // score actuel
    int best = 0; // meilleur score
    bool win = true; // gagnant ?
    bool end = false; // fin partie ?
    QList<int> list = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // liste des valeurs des 16 cases
    fstream data;
    string path = "data.txt";


};

#endif // GAME_H

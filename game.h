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
    Q_PROPERTY(QList<int> list READ getList NOTIFY update)
    Q_PROPERTY(qint64 score READ give_score NOTIFY update)
    Q_PROPERTY(qint64 best READ give_best NOTIFY update)
    qint64 give_best();
    qint64 give_score();
    QList<int> getList() const {return list;}
    //Q_INVOKABLE qint64 give_score();
    //Q_INVOKABLE qint64 give_best();
    Q_INVOKABLE void save();
    Q_INVOKABLE void newgame();
    //static void declareQML();
    Game();
    ~Game(); // destructeur
    int random(vector<int> v); // nombre aléatoire
    //void newgame(); // nouvelle partie
    //void save(); // sauvegarder données
    void load(); // recuperer données
    void add_score(int a); //augmente le score
    int power(int n); // calcule puissance de deux
    int empty_case();
    void afficher_score();
    void afficher_data();
    void actualize();
    void right_mvt();
    void left_mvt();
    void top_mvt();
    void low_mvt();
    void verify_right_mvt();
    void verify_left_mvt();
    void verify_top_mvt();
    void verify_low_mvt();
    int random_init();

signals:
    void update();

private:

    int score = 0; // score actuel
    int best = 0; // meilleur score
    bool win = true; // gagnant ?
    bool end = false; // fin partie ?
    QList<int> list = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // liste des valeurs des 16 cases
    bool l_right[4] = {false, false, false, false};
    bool l_left[4] = {false, false, false, false};
    bool l_top[4] = {false, false, false, false};
    bool l_low[4] = {false, false, false, false};
    bool l_right2[4] = {false, false, false, false};
    bool l_left2[4] = {false, false, false, false};
    bool l_top2[4] = {false, false, false, false};
    bool l_low2[4] = {false, false, false, false};
    fstream data;
    string path = "data.txt";


};

#endif // GAME_H

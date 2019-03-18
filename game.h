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
    Q_PROPERTY(bool end READ give_end NOTIFY update)
    Q_PROPERTY(bool win_end READ give_win NOTIFY update)


    Q_INVOKABLE void right_mvt();
    Q_INVOKABLE void left_mvt();
    Q_INVOKABLE void top_mvt();
    Q_INVOKABLE void low_mvt();
    Q_INVOKABLE void lose();
    Q_INVOKABLE void win();


    qint64 give_best();
    qint64 give_score();
    bool give_end();
    bool give_win();
    QList<int> getList() const {return list;}
    Q_INVOKABLE void save();
    Q_INVOKABLE void newgame();
    Game();
    ~Game(); // destructeur
    int random(vector<int> v); // nombre aléatoire
    void load(); // recuperer données
    void add_score(int a); //augmente le score
    int power(int n); // calcule puissance de deux
    int empty_case();
    void afficher_score();
    void afficher_data();
    void actualize();
    void verify_right_mvt();
    void verify_left_mvt();
    void verify_top_mvt();
    void verify_low_mvt();
    int random_init();
    void shift_right(int a);
    void shift_left(int a);
    void shift_top(int a);
    void shift_low(int a);

signals:
    void update();

private:

    int score = 0; // score actuel
    int best = 0; // meilleur score
    //bool win = true; // gagnant ?
    bool win_end = false;
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

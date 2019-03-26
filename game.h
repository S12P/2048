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


#include <cmath>




using namespace std;




class Game : public QObject {

    Q_OBJECT

public:
    Q_PROPERTY(QList<int> list READ getList NOTIFY update)
    Q_PROPERTY(qint64 score READ give_score NOTIFY update)
    Q_PROPERTY(qint64 best READ give_best NOTIFY update)
    Q_PROPERTY(bool end READ give_end NOTIFY update)
    Q_PROPERTY(bool win_end READ give_win NOTIFY update)
    Q_PROPERTY(QList<QString> lcolor READ give_color NOTIFY update)


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
    QList<QString> give_color() {return lcolor;}
    Q_INVOKABLE void save();
    Q_INVOKABLE void newgame();
    explicit Game(QObject *parent = 0);
    ~Game(); // destructeur
    int random(vector<int> v); // nombre aléatoire
    void load(); // recuperer données
    void add_score(int a); //augmente le score
    int power(int n); // calcule puissance de deux
    int empty_case();
    void afficher_score();
    void afficher_data();
    void ia();
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
    void change_color();

signals:
    void update();

private:

    int score = 0; // score actuel
    int best = 0; // meilleur score
    //bool win = true; // gagnant ?
    string begin = "DepartForm.ui.qml";
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

    QString c_0 = "#D8B758";
    QString c_2 = "#A37B08";
    QString c_4 = "#FFE833";
    QString c_8 = "#FFA533";
    QString c_16 = "#FF3383";
    QString c_32 = "#FF5133";
    QString c_64 = "#33FFBC";
    QString c_128 = "#33FF4A";
    QString c_256 = "#B933FF";
    QString c_512 = "#3A33FF";
    QString c_1024 = "#FF3344";
    QString c_2048 = "#FF3344";

    QList<QString> defcolor = {c_0, c_2, c_4, c_8, c_16, c_32, c_64, c_128, c_256, c_512, c_1024, c_2048};

    QList<QString> lcolor = {c_0, c_0, c_0, c_0, c_0, c_0, c_0, c_0, c_0, c_0, c_0, c_0, c_0, c_0, c_0, c_0}; // 16 cases


};

#endif // GAME_H

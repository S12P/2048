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


    qint64 give_best(); //donne le meilleur score
    qint64 give_score(); // donne le score actuel
    bool give_end(); // boolean pour savoir si il a perdu
    bool give_win(); // boolean pour savoir si il a gagné
    QList<int> getList() const {return list;} // donne la liste du jeu
    QList<QString> give_color() {return lcolor;} // donne la liste des couleurs
    Q_INVOKABLE void save(); // sauvegarde le jeu
    Q_INVOKABLE void newgame(); // lance un nouveau jeu
    Q_INVOKABLE void comeBack(); // retour en arrière
    Q_INVOKABLE void changeColor(); // Change les couleurs
    explicit Game(QObject *parent = 0);
    ~Game(); // destructeur
    int random(vector<int> v); // nombre aléatoire
    void load(); // recuperer données
    void add_score(int a); //augmente le score
    int power(int n); // calcule puissance de deux
    int empty_case(); // donne une cases aleatoirement par rapport a toute les cases vides
    void afficher_score(); // affiche le score
    void afficher_data(); // affiche les données
    void actualize(); // actualise le score et le jeu
    void verify_right_mvt(); // verifie que le mouvement a droite est possible
    void verify_left_mvt(); // verifie que le mouvement a gauche est possible
    void verify_top_mvt(); // verifie que le mouvement en haut est possible
    void verify_low_mvt(); // verifie que le mouvement en bas est possible
    int random_init();
    void shift_right(int a); // decale les cases a droite
    void shift_left(int a); // decale les cases a gauche
    void shift_top(int a); // decale les cases en haut
    void shift_low(int a); // decale les cases en bas
    void change_color();
    void copy();

signals:
    void update();

private:

    int score = 0; // score actuel
    int old_score = 0; // score pour retour en arrière
    int best = 0; // meilleur score
    string begin = "DepartForm.ui.qml";
    bool win_end = false;
    bool end = false; // fin partie ?
    QList<int> list = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // liste des valeurs des 16 cases
    QList<int> list_old = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // liste des valeurs des 16 cases



    /* les listes suivantes permettent de savoir si les mouvements sont possibles  */
    bool l_right[4] = {false, false, false, false};
    bool l_left[4] = {false, false, false, false};
    bool l_top[4] = {false, false, false, false};
    bool l_low[4] = {false, false, false, false};
    bool l_right2[4] = {false, false, false, false};
    bool l_left2[4] = {false, false, false, false};
    bool l_top2[4] = {false, false, false, false};
    bool l_low2[4] = {false, false, false, false};

    /* Definition du fichier de sauvegarde et de son nom  */
    fstream data;
    string path = "data.txt";


    /* Definition des couleurs des cases */
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
    QString c_1024 = "#990033";
    QString c_2048 = "#FF3344";

    QString c_0_1 = "#FDFEFE";
    QString c_2_1 = "#808080";
    QString c_4_1 = "#800000";
    QString c_8_1 = "#FA8072";
    QString c_16_1 = "#33FF90";
    QString c_32_1 = "#800080";
    QString c_64_1 = "#FF00FF";
    QString c_128_1 = "#AED6F1";
    QString c_256_1 = "#008080";
    QString c_512_1 = "#00FF00";
    QString c_1024_1 = "#FFFF00";
    QString c_2048_1 = "#FF0000";

    QList<QString> defcolor1 = {c_0, c_2, c_4, c_8, c_16, c_32, c_64, c_128, c_256, c_512, c_1024, c_2048};
    QList<QString> defcolor0 = {c_0_1, c_2_1, c_4_1, c_8_1, c_16_1, c_32_1, c_64_1, c_128_1, c_256_1, c_512_1, c_1024_1, c_2048_1};
    int choice_color = 0;
    QList<QString> defcolor = defcolor0;

    QList<QString> lcolor = {c_0, c_0, c_0, c_0, c_0, c_0, c_0, c_0, c_0, c_0, c_0, c_0, c_0, c_0, c_0, c_0}; // Couleurs des 16 cases du jeu


};

#endif // GAME_H
